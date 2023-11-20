/*   _____                                 _____                                                                                                                
  __|   _ |__  ______  ______  ____     __| __  |__  ____  ____      ____  __   _  ____   _  ______  ____   _   ______  _____  _____   ____  ____   _  ______   
 \  \  //    ||   ___||   ___||    \   |  |/ /     ||    ||    |    |    ||  | | ||    \ | ||   ___||    \ | | |   ___|/     \|     \ |    ||    \ | ||   ___|  
 |\  \//     ||   ___| `-.`-. |     \  |     \     ||    ||    |_  _|    ||  |_| ||     \| ||   ___||     \| | |   |__ |     ||      \|    ||     \| ||   |  |  
 |_\__/    __||______||______||__|\__\ |__|\__\  __||____||______||______||______||__/\____||______||__/\____| |______|\_____/|______/|____||__/\____||______|  
    |_____|                               |_____|                                                                                                               
                                           _                                                                                                                    
  _____   __   _  ____  ______  __  __    / |  _____   ____  _____    __  __    _                                                                               
 /     \ |  | | ||    ||   ___||  |/ /   / /  |     \ |    ||     | _|  |_\ \  //                                                                               
 |     | |  |_| ||    ||   |__ |     \  |_/   |      \|    ||     \|_    _|\ \//                                                                                
 \___/\_\|______||____||______||__|\__\       |______/|____||__|\__\ |__|  /__/                                                                                 
                                                  _                                                                                                             
   __    _ ______  ______  __  __  _____  _____   / |______  ____  ____   _                                                                                     
  \  \  //|   ___||   ___||  |/ / /     \/     \ / /|   ___||    ||    \ | |                                                                                     
   \  \// |   ___||   ___||     \ |     ||     ||_/ |   ___||    ||     \| |                                                                                     
    \__/  |______||______||__|\__\\_____/\_____/    |___|   |____||__/\____|*/ 

/*----------------------------------------------------------------------+
 |                                                                      |
 |     KTEM_lotto.c -- demonstrate lotto number simulation              |
 |                    of Kaikki Tai Ei Mitaan                           |
 |                                                                      |
 +----------------------------------------------------------------------*/

#include <stdlib.h>
#include <string.h>
#include <gigatron/console.h>
#include <time.h>

int readint(const char *prompt)
{
	char buffer[32];
	cprintf(prompt, strlen(prompt));
	console_readline(buffer, sizeof(buffer));
	return atoi(buffer);
}

void main()
{
  int b0[12],bb[12],i,ii,total,game,sw,it;
  long cash,saldo;
  int bt0[1],bbt[1];
  int totalbt,eit,egame;
  int sil; //printout silence mode
  int cup; //cupoung silence mode
  int big; //big saldo annoucements mode 0-10000

  cprintf("All or nothing simulation:\n"); 
  eit=readint("\nNbr of iterations:");
  egame=readint("Nbr of games:");
  sil=readint("Printout silence 0/1:");
  cup=readint("Cupoung silence 0/1:");
  big=readint("Big saldo info 0/nbr:");
  
  srand(time(0));

  for(it=0;it<eit;it++) //iterations 1-10000
  {
    cash=0;

    for(game=0;game<egame;game++) //game rounds how many weeks 1-52
    {
      sw=0;
      b0[0]=0;
      b0[1]=0;
      b0[2]=0;
      b0[3]=0;
      b0[4]=0;
      b0[5]=0;
      b0[6]=0;
      b0[7]=0;
      b0[8]=0;
      b0[9]=0;
      b0[10]=0;
      b0[11]=0;

      for(i=0;i<12;i++)
      {
        b0[i]=rand() % 24 +1;
        for(ii=0;ii<12;ii++)
        {
          if(b0[ii] == b0[i] && (ii != i)) sw=1;
        }
        if(sw==1){
          i--;
          sw=0;
        }
      }

      bt0[0]=rand() % 4 +1;

      if(cup != 1) cprintf("\nMy row:%d+%d+%d+%d+%d+%d+%d+%d+%d+%d+%d+%d*%d",b0[0],b0[1],b0[2],b0[3],b0[4],b0[5],b0[6],b0[7],b0[8],b0[9],b0[10],b0[11],bt0[0]);
      sw=0;
      bb[0]=0;
      bb[1]=0;
      bb[2]=0;
      bb[3]=0;
      bb[4]=0;
      bb[5]=0;
      bb[6]=0;
      bb[7]=0;
      bb[8]=0;
      bb[9]=0;
      bb[10]=0;
      bb[11]=0;

      for(i=0;i<12;i++)
      {
        bb[i]=rand() % 24 +1;
        for(ii=0;ii<12;ii++)
        {
          if(bb[ii] == bb[i] && (ii != i)) sw=1;
        }
        if(sw==1){
          i--;
          sw=0;
        }
      }

      bbt[0]=rand() % 4 +1;
      
      if(cup != 1) cprintf("\nWin row:%d+%d+%d+%d+%d+%d+%d+%d+%d+%d+%d+%d*%d",bb[0],bb[1],bb[2],bb[3],bb[4],bb[5],bb[6],bb[7],bb[8],bb[9],bb[10],bb[11],bbt[0]);

      total=0;

      for(i=0;i<12;i++)
      {
        for(ii=0;ii<12;ii++)
        {
          if(bb[i]==b0[ii])
          {
            total++;
          }
        }
      }
      totalbt=0;

      if(bbt[0]==bt0[0])
          {
            totalbt++;
          }
  
      if(cup != 1) cprintf("\nNumbers correct:%d*%d",total,totalbt);

      if((total==12 && totalbt==1)||(total==0 && totalbt==1)) {
      cash=cash+500000;
      if(sil != 1) cprintf("\n500 000 euro win");
      }
      if((total==12 && totalbt==0)||(total==0 && totalbt==0)) {
      cash=cash+125000;
      if(sil != 1) cprintf("\n125 000 euro win");
      }
      if((total==11 && totalbt==1)||(total==1 && totalbt==1)) {
      cash=cash+1000;
      if(sil != 1) cprintf("\n1000 euro win");
      }
      if((total==11 && totalbt==0)||(total==1 && totalbt==0)) {
      cash=cash+250;
      if(sil != 1) cprintf("\n250 euro win");
      }
      if((total==10 && totalbt==1)||(total==2 && totalbt==1)) {
      cash=cash+100;
      if(sil != 1) cprintf("\n100 euro win");
      }
      if((total==10 && totalbt==0)||(total==2 && totalbt==0)) {
      cash=cash+25;
      if(sil != 1) cprintf("\n25 euro win");
      }
      if((total==9 && totalbt==1)||(total==3 && totalbt==1)) {
      cash=cash+20;
      if(sil != 1) cprintf("\n20 euro win");
      }
      if((total==9 && totalbt==0)||(total==3 && totalbt==0)) {
      cash=cash+5;
      if(sil != 1) cprintf("\n5 euro win");
      }
      if((total==8 && totalbt==1)||(total==4 && totalbt==1)) {
      cash=cash+4;
      if(sil != 1) cprintf("\n4 euro win");
      }   
      if((total==8 && totalbt==0)||(total==4 && totalbt==0)) {
      cash=cash+1;
      if(sil != 1) cprintf("\n1 euro win");
      }
      if((total==7 && totalbt==1)||(total==5 && totalbt==1)||(total==6 && totalbt==1)) {
      cash=cash+1;
      if(sil != 1) cprintf("\n1 euro win");
      }

      saldo = cash - game * 2 -2;

      if(sil != 1 && saldo > 100) cprintf("\nGame,win,100 euro saldo:%d+%ld+%ld",game,cash,saldo);
      if(sil != 1 && saldo > 1000) cprintf("\nGame,win,1000 euro saldo:%d+%ld+%ld",game,cash,saldo);
      if(sil != 1 && saldo > 10000) cprintf("\nGame,win,10000 euro saldo:%d+%ld+%ld",game,cash,saldo);
      if(sil != 1 && saldo > 100000) cprintf("\nGame,win,100000 euro saldo:%d+%ld+%ld",game,cash,saldo);
      if(sil != 1 && saldo > 1000000) cprintf("\nGame,win,1000000 euro saldo:%d+%ld+%ld",game,cash,saldo);
      if(sil != 1 && saldo > 10000000) cprintf("\nGame,win,10000000 euro saldo:%d+%ld+%ld",game,cash,saldo);
    }
    if(big == 0) {
      cprintf("\nIteration,game,win,saldo:");
      cprintf("\n%d+%d+%ld+%ld",it,game,cash,saldo);
    }
    if(big > 0 && saldo > big) {
      cprintf("\nIteration,game,win,saldo:");
      cprintf("\n%d+%d+%ld+%ld",it,game,cash,saldo);
    }
  }
}

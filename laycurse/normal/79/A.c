#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int is_can(int *x,int *y,int mode){
  int res = 220;
  if(mode==0){
    while(*x > 0 && res >= 100) (*x)--, res -= 100;
    while(*y > 0 && res >= 10 ) (*y)--, res -= 10;
  } else {
    while(*y >= 12 && res >= 100) (*y)-=10, res-=100;
    while(*x >=  1 && res >= 100) (*x)-= 1, res-=100;
    while(*y >=  1 && res >= 10 ) (*y)-= 1, res-=10;
  }
  if(res==0) return 1; return 0;
}

int main(){
  int i,j,k,l,m,n;
  int x,y,win;

  while(scanf("%d%d",&x,&y)==2){
    for(;;){
      if(!is_can(&x,&y,0)){ win=0; break; }
      if(!is_can(&x,&y,1)){ win=1; break; }
    }

    if(win) puts("Ciel"); else puts("Hanako");
  }


  return 0;
}
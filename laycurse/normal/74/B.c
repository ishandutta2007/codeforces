#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int far(int enemy,int dir,int n){
  if(enemy==0) return n-1;
  if(enemy==n-1) return 0;
  if(dir==1) return 0;
  return n-1;
}

int main(){
  int i,j,k,l,m,n,len,turn;
  int now, enemy, dir;
  char in[1000], a[100], b[100];

  while(scanf("%d%d%d",&n,&now,&enemy)==3){
    scanf("%s%s%s",a,b,in);
    if(b[0]=='h') dir=-1; else dir=1;

    now--; enemy--;
    if(enemy+dir < 0 || enemy+dir >= n) dir *= -1;

    if(now < enemy) now = 0;
    else now = n-1;

    for(i=0;;i++) if(in[i]<' ') break; len=i;
    rep(turn,len){
      if(in[turn]=='1') now=-1;
      if(in[turn]=='0' && now==-1) now = far(enemy,dir,n);
      
      enemy += dir;
      if(enemy+dir < 0 || enemy+dir >= n) dir *= -1;

      if(enemy==now) break;
    }

    if(turn==len)puts("Stowaway"); else printf("Controller %d\n",turn+1);
  }


  return 0;
}
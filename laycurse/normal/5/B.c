#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char in[1010][1010]; int len[1010];

int main(){
  int i,j,k,l,m,n,w,k1,k2,kk,fg=0;
  int st,ed;

  n=0; while(gets(in[n])) n++;
  rep(i,n){ for(j=0;;j++) if(in[i][j]<' ') break; len[i]=j; }

  w=0;
  rep(i,n) if(w<len[i]) w=len[i];

  st=0; ed=n-1;
/*  while(len[st]==0) st++;
  while(len[ed]==0) ed--;*/

  rep(i,w+2) putchar('*'); puts("");
  REP(i,st,ed+1){
    k=w-len[i];
    putchar('*');
    k1=k/2; k2=k/2; if(k%2) fg++;
    if(k%2 && fg%2==0) k1++;
    if(k%2 && fg%2==1) k2++;
    rep(j,k1) putchar(' ');
    rep(j,len[i]) putchar(in[i][j]);
    rep(j,k2) putchar(' ');
    puts("*");
  }
  rep(i,w+2) putchar('*'); puts("");

  return 0;
}
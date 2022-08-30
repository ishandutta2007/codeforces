#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int pw[12];
int check[20000];

void doit(int mask,int turn){
  int i,j,k,mp[9],win=0;

  if(check[mask]>=0) return;

  k=mask;
  rep(i,9) mp[i]=k%3, k/=3;

  rep(i,3){
    if(mp[i*3+0] && mp[i*3+0]==mp[i*3+1] && mp[i*3+1]==mp[i*3+2]) win=mp[i*3+0];
    if(mp[i  +0] && mp[i  +0]==mp[i  +3] && mp[i  +3]==mp[i  +6]) win=mp[i  +0];
  }
  if(mp[0] && mp[0]==mp[4] && mp[4]==mp[8]) win=mp[0];
  if(mp[2] && mp[2]==mp[4] && mp[4]==mp[6]) win=mp[2];

  if(win){ check[mask]=1+win; return; }
  rep(i,9) if(!mp[i]) break;
  if(i==9){ check[mask]=4; return; }

  check[mask]=turn;
  rep(i,9) if(mp[i]==0) doit(mask+pw[i]*(turn+1),turn^1);
}

int main(){
  int i,j,k,l,m,n;
  char mp[99];

  pw[0]=1; REP(i,1,12) pw[i]=pw[i-1]*3;
  rep(i,pw[9]) check[i]=-1;

  doit(0,0);
  rep(i,3) scanf("%s",mp+i*3);
  k=0;
  rep(i,9){
    k*=3;
    if(mp[8-i]=='X') k++;
    if(mp[8-i]=='0') k+=2;
  }

  if(check[k]==-1) puts("illegal");
  if(check[k]== 0) puts("first");
  if(check[k]== 1) puts("second");
  if(check[k]== 2) puts("the first player won");
  if(check[k]== 3) puts("the second player won");
  if(check[k]== 4) puts("draw");
  
  return 0;
}
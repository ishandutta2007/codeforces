#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int x, y;
  int mp[51][51];

  int i, j, k;

  scanf("%d%d",&x,&y);
  rep(i,x) rep(j,y) scanf("%d",mp[i]+j);

  k = 0;
  rep(i,x) rep(j,y){
    if(!mp[i][j]) continue;
    if(i==0||j==0||i==x-1||j==y-1) k++;
  }

  if(k) puts("2"); else puts("4");

  return 0;
}
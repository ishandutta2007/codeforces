#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define INF 1000000000

int main(){
  int i,j,k,l,m,n,lim,res;
  int mn[1200];
  
  scanf("%d%d%d\n",&m,&n,&lim);
  rep(i,n) mn[i]=INF;
  while(m--){
    scanf("%d%d",&i,&j); i--;
    if(mn[i]>j) mn[i]=j;
  }
  rep(i,n) if(mn[i]==INF) mn[i]=0;
  res=0;
  rep(i,n) res+=mn[i];
  if(res > lim) res = lim;
  printf("%d\n",res);

  return 0;
}
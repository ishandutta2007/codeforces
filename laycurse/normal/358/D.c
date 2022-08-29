#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int n;
  int a[3000], b[3000], c[3000];
  int dp[3001];

  int i, j, add, go;

  scanf("%d",&n);
  rep(i,n) scanf("%d",a+i);
  rep(i,n) scanf("%d",b+i);
  rep(i,n) scanf("%d",c+i);

  rep(i,n+1) dp[i] = 0;
  rep(i,n){
    add = 0;
    REP(j,i,n){
      if(j==0 || j > i) go = dp[i] + add + a[j];
      else              go = dp[i] + add + b[j];
      if(dp[j+1] < go) dp[j+1] = go;
      if(j==0 || j > i) add += b[j];
      else              add += c[j];
    }
  }

  printf("%d\n",dp[n]);

  return 0;
}
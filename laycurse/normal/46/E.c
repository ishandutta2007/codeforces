#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define INF 1000000000000000LL

ll dp[1600][1600], res;
int in[1600][1600], sum[1600][1600];

int main(){
  int i,j,k,l,m,n;
  int x,y;

  scanf("%d%d",&x,&y);
  rep(i,x) rep(j,y) scanf("%d",in[i]+j);
  rep(i,x){
    sum[i][0]=in[i][0];
    REP(j,1,y) sum[i][j]=sum[i][j-1]+in[i][j];
  }

  rep(j,y) dp[0][j]=sum[0][j];
  REP(i,1,x){
    res = -INF;
    if(i%2){
      for(j=y-1;j>=0;j--){
        dp[i][j]=res + sum[i][j];
        if(res < dp[i-1][j]) res = dp[i-1][j];
      }
    }else{
      rep(j,y){
        dp[i][j]=res + sum[i][j];
        if(res < dp[i-1][j]) res = dp[i-1][j];
      }
    }
  }

  res = dp[x-1][0];
  REP(j,1,y) if(res<dp[x-1][j]) res = dp[x-1][j];

  printf("%I64d\n",res);

  return 0;
}
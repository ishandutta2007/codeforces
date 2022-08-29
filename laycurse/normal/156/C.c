#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define M 1000000007
int dp[120][4000];

int main(){
  int i,j,k,l,m,n;
  char in[120];
  int size;

  rep(i,120) rep(j,4000) dp[i][j] = 0;
  dp[0][0] = 1;
  rep(i,119) rep(j,3900) if(dp[i][j]) rep(k,26){
    dp[i+1][j+k] += dp[i][j];
    if(dp[i+1][j+k] >= M) dp[i+1][j+k] -= M;
  }

  scanf("%d",&size);
  while(size--){
    scanf("%s",in);
    n = strlen(in);

    m = 0;
    rep(i,n) m += in[i] - 'a';

    k = dp[n][m] - 1;
    if(k < 0) k += M;

    printf("%d\n",k);
  }

  return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define INF 1000000000

int len;
char in[110000];
int dame[30][30];

int dp[110000][27];

int main(){
  int i,j,k,l,m,n,add;
  int res;
  char buf[10];

  while(scanf("%s",in)==1){
    len = strlen(in);
    rep(i,len) in[i] -= 'a';

    rep(i,27) rep(j,27) dame[i][j] = 0;
    scanf("%d",&n);
    while(n--){
      scanf("%s",buf);
      i = buf[0] - 'a';
      j = buf[1] - 'a';
      dame[i][j] = dame[j][i] = 1;
    }

    rep(i,110000) rep(j,27) dp[i][j] = INF;
    dp[0][26] = 0;

    rep(i,len) rep(j,27) if(dp[i][j] != INF){
      if(!dame[j][in[i]]){
        if(dp[i+1][in[i]] > dp[i][j]) dp[i+1][in[i]] = dp[i][j];
      }
      if(dp[i+1][j] > dp[i][j] + 1) dp[i+1][j] = dp[i][j] + 1;
    }

    res = INF;
    rep(i,27) if(res > dp[len][i]) res = dp[len][i];
    printf("%d\n",res);
  }

  return 0;
}
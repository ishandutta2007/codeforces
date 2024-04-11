#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define INF 1000000000000000000LL

int a, b;
ll dp[4100], next[4100];

int main(){
  int i,j,k,l,n;
  int m, m2;
  ll res;

  scanf("%d",&n);
  m = n + 10; m2 = m*2;

  rep(i,m2) dp[i]=INF;
  dp[m]=0;

  while(n--){
    scanf("%d%d",&a,&b);
    rep(i,m2) next[i] = INF;
    rep(i,m2){
      if(i-1 >= 0 && next[i-1] > dp[i]) next[i-1] = dp[i];
      if(i+a < m2 && next[i+a] > dp[i]+b) next[i+a] = dp[i]+b;
      if(i+a >= m2 && next[m2-1] > dp[i]+b) next[m2-1] = dp[i]+b;
    }
    rep(i,m2) dp[i]=next[i];
  }

  res = INF;
  REP(i,m,m2) if(res > dp[i]) res=dp[i];

  printf("%I64d\n",res);

  return 0;
}
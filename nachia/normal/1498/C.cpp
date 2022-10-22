
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

const ull M=1000000007;

int N,K;
ull dp[1001];

void testcase(){
  scanf("%d%d",&N,&K);
  rep(i,N+1) dp[i]=0;
  dp[0]=1;
  ull ans=0;
  for(int k=K; k>=1; k--){
    rep(i,N+1){ ans+=dp[i]; if(ans>=M) ans-=M; }
    rep(i,N-1){ dp[i+1]+=dp[i]; if(dp[i+1]>=M) dp[i+1]-=M; }
    dp[N]=0;
    reverse(dp,dp+N+1);
  }
  printf("%llu\n",ans);
}

int main(){
  int T; scanf("%d",&T);
  while(T--) testcase();
  return 0;
}
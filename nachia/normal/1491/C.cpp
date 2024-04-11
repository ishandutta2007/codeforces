#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
ll A[5000];
ll dp[5000];

int main(){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    rep(i,N) scanf("%lld",&A[i]);
    rep(i,N) dp[i]=0;
    ll ans=0;
    rep(i,N){
      ll jumps=max(A[i]-1,dp[i]);
      ans+=jumps-dp[i];
      for(int j=i+2; j<=min((ll)N-1,i+A[i]); j++) dp[j]++;
      ll onejumps=max(0ll,jumps-(A[i]-1));
      if(i!=N-1) dp[i+1]+=onejumps;
    }
    printf("%lld\n",ans);
  }
  return 0;
}
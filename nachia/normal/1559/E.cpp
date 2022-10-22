
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)


const u64 MOD = 998244353;


u64 solve(int N, vector<int>& L, vector<int>& R, int M){
  vector<u64> dp(M+1,1);
  vector<u64> sumdp(M+2,0);
  dp[0] = 1;
  rep(i,N){
    rep(j,M+1){
      sumdp[j+1] = dp[j] + sumdp[j];
      if(sumdp[j+1] >= MOD) sumdp[j+1] -= MOD;
    }
    rep(j,M+1){
      int l = max(0,j-R[i]);
      int r = max(0,j-L[i]);
      dp[j] = MOD + sumdp[r] - sumdp[l];
      if(dp[j] >= MOD) dp[j] -= MOD;
    }
  }
  return dp[M];
}



int main() {
  int N, M; cin >> N >> M;
  vector<int> L(N), R(N);
  rep(i,N){ cin >> L[i] >> R[i]; L[i]--; }

  vector<int> prime(M+1,1);
  vector<int> divcnt(M+1,1);
  for(int i=2; i<=M; i++) if(prime[i] == 1){
    for(int j=i; j<=M; j+=i) divcnt[j] = -divcnt[j/i];
    for(int j=i*2; j<=M; j+=i) prime[j] = 0;
    if(i <= 10000) for(int j=i*i; j<=M; j+=i*i) divcnt[j] = 0;
  }

  u64 ans = 0;
  for(int k=1; k<=M; k++) if(divcnt[k] != 0){
    int n = N;
    vector<int> l = L; for(auto& a : l) a /= k;
    vector<int> r = R; for(auto& a : r) a /= k;
    int m = M/k;
    u64 tmp = solve(n,l,r,m);
    if(divcnt[k] == 1) ans += tmp;
    else ans += MOD - tmp;
  }

  ans %= MOD;
  cout << ans << "\n";

  return 0;
}


struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;
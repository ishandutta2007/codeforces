#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)


void testcase(){
  i64 N,M; cin >> N >> M;
  vector<i64> dp(N+1,0);
  dp[1] = 1;
  dp[2] = M-1;
  for(int i=1; i<N; i++){
    dp[i+1] = (dp[i+1] + dp[i] * 2) % M;
    for(int j=2; i*j<=N; j++){
      int l = j*i;
      int r = j*(i+1);
      dp[l] = (dp[l] + dp[i]) % M;
      if(r <= N) dp[r] = (dp[r] + M - dp[i]) % M;
    }
  }
  cout << dp[N] << "\n";
}



int main(){
  //int T; cin >> T;
  //rep(i,T) testcase();
  testcase();
  return 0;
}



struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;
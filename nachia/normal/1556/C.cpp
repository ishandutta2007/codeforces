
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
  int N; cin >> N;
  vector<i64> C(N); rep(i,N) cin >> C[i];
  vector<i64> P(N+1,0);
  rep(i,N){
    if(i%2 == 0) P[i+1] = P[i] + C[i];
    if(i%2 == 1) P[i+1] = P[i] - C[i];
  }
  //for(auto a : P) cout << a << " "; cout << endl;
  u64 ans = 0;
  for(int i=1; i<N; i+=2){
    u64 tmp = 0;
    i64 min_depth = P[i];
    for(int j=i-1; j>=0; j-=2){
      //cout << min_depth << " - ";
      i64 l = max(P[j], P[i+1]);
      i64 r = min(min_depth, P[j+1]);
      if(l <= r) tmp += r-l+1;
      min_depth = min(min_depth, P[j]);
    }
    ans += tmp-1;
    //cout << endl;
  }
  cout << ans << "\n";
}

int main(){
  //int T; cin >> T;
  //rep(t,T)
  testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;
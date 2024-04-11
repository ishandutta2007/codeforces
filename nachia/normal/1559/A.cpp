
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


void testcase(){
  int N; cin >> N;
  vector<int> A(N);
  rep(i,N) cin >> A[i];
  int ans = A[0];
  for(int a : A) ans &= a;
  cout << ans << "\n";
}


int main() {
  int T; cin >> T;
  while(T--) testcase();
  return 0;
}


struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;
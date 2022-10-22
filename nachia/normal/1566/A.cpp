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
  i64 n,s; cin >> n >> s;
  i64 rn = n / 2 + 1;
  i64 ans = s / rn;
  cout << ans << endl;
}


int main(){
  int T; cin >> T;
  rep(t,T) testcase();
  return 0;
}




struct ios_do_not_sync {
    ios_do_not_sync() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} ios_do_not_sync_instance;
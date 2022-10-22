
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
  int a,b; cin >> a >> b;
  if(a%2 != b%2){ cout << "-1\n"; return; }
  int ans = 0;
  if(a+b != 0) ans++;
  if(a!=b) ans++;
  cout << ans << "\n";
}

int main(){
  int T; cin >> T;
  rep(t,T) testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;
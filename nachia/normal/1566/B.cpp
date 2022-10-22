#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)




void testcase(){
  string s; cin >> s;
  if(s.find('0') == string::npos){ cout << 0 << endl; return; }
  while(s.size()) if(s.back() == '1') s.pop_back(); else break;
  while(s.size()) if(s.back() == '0') s.pop_back(); else break;
  while(s.size()) if(s.back() == '1') s.pop_back(); else break;
  if(s.empty()) cout << 1 << endl;
  else cout << 2 << endl;
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
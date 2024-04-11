#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)


void testcase(){
  int a,b; cin >> a >> b;
  if(a > b) swap(a,b);
  int n = a+b;
  int R = (n+1)/2 + a;
  int L = b - (n+1)/2;
  vector<int> ans;
  if(n%2 == 0){
    for(int i=L; i<=R; i+=2) ans.push_back(i);
  }
  else{
    for(int i=L; i<=R; i++) ans.push_back(i);
  }
  cout << ans.size() << "\n";
  rep(i,ans.size()){
    if(i) cout << " ";
    cout << ans[i];
  }
  cout << "\n";
}



int main(){
  int T; cin >> T;
  rep(i,T) testcase();
  return 0;
}



struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;
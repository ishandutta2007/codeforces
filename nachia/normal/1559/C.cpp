
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
  vector<int> ans;
  if(A[0] == 1){
    ans.push_back(N);
    rep(i,N) ans.push_back(i);
  }
  else if(A.back() == 0){
    rep(i,N) ans.push_back(i);
    ans.push_back(N);
  }
  else{
    int k = -1;
    rep(i,N-1) if(A[i] == 0 && A[i+1] == 1) k = i;
    rep(i,N){
      ans.push_back(i);
      if(i == k) ans.push_back(N);
    }
  }
  if(ans.empty()) cout << "-1\n";
  else{
    rep(i,N+1){
      if(i) cout << " ";
      cout << (ans[i] + 1);
    }
    cout << "\n";
  }
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
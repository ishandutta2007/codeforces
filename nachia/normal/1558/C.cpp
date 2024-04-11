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
  vector<int> A(N);
  vector<int> B(N);
  rep(i,N) cin >> A[i];
  rep(i,N) A[i]--;
  rep(i,N) B[A[i]] = i;
  rep(i,N) if(A[i] % 2 != i % 2){ cout << "-1\n"; return; }
  vector<int> ans;
  auto onemove = [&](int r)->void{
    reverse(A.begin(), A.begin()+r);
    rep(i,r) B[A[i]] = i;
    //for(auto a : A) cout << a << " "; cout << endl;
    ans.push_back(r);
  };
  while(N >= 3){
    if(B[N-1] != 0) onemove(B[N-1]+1);
    if(B[N-2] != 1) onemove(B[N-2]);
    if(B[N-1] != 0){
      onemove(B[N-1]+3);
      onemove(3);
    }
    onemove(N);
    rep(t,2){
      A.pop_back();
      B.pop_back();
      N--;
    }
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
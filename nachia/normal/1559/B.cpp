
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
  string S; cin >> S;
  rep(s,2){
    rep(t,2){
      reverse(S.begin(),S.end());
      rep(i,N-1) if(S[i+1] == '?'){
        if(S[i] == 'R') S[i+1] = 'B';
        else if(S[i] == 'B') S[i+1] = 'R';
      }
    }
    if(S[0] == '?') S[0] = 'R';
  }
  cout << S << "\n";
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
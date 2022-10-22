
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
  vector<int> A;
  rep(i,N){ int a; cin >> a; if(a%2 == 1) A.push_back(i); }
  if(A.size() < N/2){ cout << "-1\n"; return; }
  if(A.size() > (N+1)/2){ cout << "-1\n"; return; }
  i64 ans = 1001001001001001;
  if(A.size() == (N+1)/2){
    i64 tmp = 0;
    rep(i,A.size()) tmp += abs(A[i] - i*2);
    ans = min(ans,tmp);
  }
  if(A.size() == N/2){
    i64 tmp = 0;
    rep(i,A.size()) tmp += abs(A[i] - (i*2+1));
    ans = min(ans,tmp);
  }
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
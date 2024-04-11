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
  int n; cin >> n;
  int m; cin >> m;
  vector<pair<int,int>> A;
  rep(i,n*m){ int a; cin >> a; A.push_back(make_pair(a,i)); }
  sort(A.begin(), A.end());
  for(auto& a : A) a.second *= -1;
  i64 ans = 0;
  rep(i,n){
    sort(A.begin() + (i*m), A.begin() + ((i+1)*m));
    vector<int> I(m);
    rep(j,m) I[j] = -A[i*m+j].second;
    rep(r,m) rep(l,r) if(I[l] < I[r]) ans += 1;
  }
  cout << ans << "\n";
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
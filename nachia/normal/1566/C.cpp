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





int solve1(string s){
  int ans = 0;
  int n = s.size();
  vector<array<int,2>> nx(n+1);
  rep(k,2) nx[n][k] = n;
  for(int i=n-1; i>=0; i--){
    nx[i] = nx[i+1];
    nx[i][s[i]-'0'] = i;
  }
  vector<i64> dp(n+1,0);
  dp[0] = 0;
  for(int i=0; i<n; i++){
    rep(t,2) if(nx[i][t] != n){
      int mex = 0;
      int to = nx[i][t]+1;
      rep(y,2) if(mex==y) if(to > nx[i][y]) mex++;
      dp[to] = max(dp[to], dp[i] + mex);
    }
  }
  return dp[n];
}

void testcase(){
  int n; cin >> n;
  string s; cin >> s;
  string t; cin >> t;
  int ans = 0;
  string buf;
  rep(i,n){
    if(s[i] != t[i]){
      if(buf.size()){ ans += solve1(move(buf)); buf = ""; }
      ans += 2;
    }
    else{
      buf.push_back(s[i]);
    }
  }
  if(buf.size()){ ans += solve1(move(buf)); buf = ""; }
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
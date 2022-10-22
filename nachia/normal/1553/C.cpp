#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


int solve(string S){
  int rem[2] = {5,5};
  int sc[2] = {0,0};
  int pk = 0;
  rep(i,10){
    char c = S[i];
    sc[pk] += (c - '0');
    rem[pk]--;
    if(sc[0] > sc[1] + rem[1]) return i+1;
    if(sc[1] > sc[0] + rem[0]) return i+1;
    pk ^= 1;
  }
  return 10;
}


void testcase(){
  string S; cin >> S;
  int ans = 10;
  rep(t,2){
    string buf = S;
    rep(i,10) if(buf[i] == '?'){
      buf[i] = '0' + ((i&1)^t);
    }
    ans = min(ans,solve(buf));
  }
  cout << ans << "\n";
}


int main(){
  int T; cin >> T;
  while(T--) testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;
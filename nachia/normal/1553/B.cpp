#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


int main(){
  int T; cin >> T;
  while(T--){
    string S; cin >> S;
    string G; cin >> G;
    int n = S.size();
    string P = S;
    for(int i=n-2; i>=0; i--) P.push_back(S[i]);
    vector<vector<int>> E(n*2);
    rep(i,n-1) E[i].push_back(i+1);
    for(int i=1; i<n-1; i++) E[i].push_back(2*n-2-(i-1));
    rep(i,n-1) E[n-1+i].push_back(n+i);
    rep(i,2*n-1) E[n*2-1].push_back(i);
    vector<int> F(n*2,0);
    F[2*n-1] = 1;
    for(char c : G){
      vector<int> buf(n*2);
      rep(i,n*2) for(int e : E[i]) buf[e] |= F[i];
      rep(i,n*2-1) if(P[i] != c) buf[i] = 0;
      F = move(buf);
      //for(auto a : F) cout << a; cout << endl;
    }
    int ans = 0;
    for(auto a : F) ans |= a;
    if(ans) cout << "YES\n"; else cout << "NO\n";
  }
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)



void testcase(){
  string S,T; cin >> S >> T;
  if(S.size() % 2 != T.size() % 2) S = S.substr(1);
  int pT = 0;
  rep(i,S.size()){
    if(pT == T.size()) break;
    if(pT % 2 != (i + T.size() + S.size()) % 2) continue;
    if(T[pT] != S[i]) continue;
    pT++;
  }
  if(pT == T.size()) cout << "YES\n";
  else cout << "NO\n";
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
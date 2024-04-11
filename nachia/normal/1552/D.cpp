#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


void testcase(){
  int n; cin >> n;
  vector<int> A(n);
  rep(i,n) cin >> A[i];
  vector<int> S = {0};
  for(auto a : A) for(int i=S.size()-1; i>=0; i--) S.push_back(S[i]+a);
  sort(S.begin(),S.end());
  bool ok = false;
  rep(i,S.size()-1) if(S[i] == S[i+1]) ok = true;
  cout << (ok ? "YES\n" : "NO\n");
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
} ios_do_not_sync_instance;
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
  vector<vector<int>> A(n,vector<int>(5));
  rep(i,n) rep(t,5) cin >> A[i][t];
  int can = 0;
  for(int i=1; i<n; i++){
    int c = 0;
    rep(t,5) if(A[can][t] > A[i][t]) c++;
    if(c >= 3) can = i;
  }
  rep(i,n) if(i != can){
    int c = 0;
    rep(t,5) if(A[can][t] > A[i][t]) c++;
    if(c >= 3){ can = -1; break; }
  }
  if(can == -1) cout << "-1\n";
  else cout << (can+1) << "\n";
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
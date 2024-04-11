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
  string S; cin >> S;
  string T = S;
  sort(T.begin(),T.end());
  int k = 0;
  rep(i,n) if(S[i] != T[i]) k++;
  cout << k << "\n";
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
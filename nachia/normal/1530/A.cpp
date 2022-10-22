
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
  int N; cin >> N;
  rep(i,N){
    string S; cin >> S;
    int ans = 0;
    for(char c : S) ans = max(ans,c-'0');
    cout << ans << "\n";
  }
  return 0;
}


struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;
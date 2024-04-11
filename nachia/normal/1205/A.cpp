#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)



int main(){
  int N; cin >> N;
  if(N % 2 == 0) cout << "NO\n";
  else{
    cout << "YES\n";
    vector<int> ans(N);
    for(int i=0; i<N; i++) ans[i] = i*2;
    for(int i=1; i<N; i+=2) ans[i]++;
    for(int i=0; i<N; i++) ans.push_back(ans[i] ^ 1);
    for(int i=0; i<ans.size(); i++){
      if(i != 0) cout << " ";
      cout << (ans[i]+1);
    }
  }
  return 0;
}


struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;
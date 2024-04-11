#include <iostream>
using ll = long long;
using namespace std;

int main(){
  int T; cin>>T;
  while(T--){
    int N,M,K; cin>>N>>M>>K;
    bool ok = (K == N*M-1);
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
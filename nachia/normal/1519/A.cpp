#include <iostream>
using ll = long long;
using namespace std;

int main(){
  int T; cin>>T;
  while(T--){
    ll A,B,D; cin>>A>>B>>D;
    if(A>B) swap(A,B);
    bool ok = D >= (B+A-1)/A-1;
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
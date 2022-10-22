#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {

 int T; cin>>T;
 while(T--){
  int A,K; cin>>A>>K;
  int ans=0;
  if(A<K) ans = K-A;
  else ans = (A-K)%2;
  cout << ans << endl;
 }

 return 0;
}
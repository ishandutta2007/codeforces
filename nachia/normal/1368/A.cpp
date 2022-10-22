#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

int main() {
 UL T; cin>>T;
 rep(t,T){
  UL A,B,N; cin>>A>>B>>N;
  UL ans=0;
  while(max(A,B)<=N){
   ans++;
   if(A<B) swap(A,B);
   B+=A;
  }
  cout<<ans<<endl;
 }
 return 0;
}
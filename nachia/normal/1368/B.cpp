#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

int main() {
 ULL K; cin>>K;
 for(UL i=10; ; i++){
  ULL t=1;
  ULL m=i%10;
  ULL M=i/10;
  rep(j,m) t*=(M+1);
  rep(j,10-m) t*=M;
  if(t>=K){
   string src="codeforces";
   string ans;
   rep(j,10){
    rep(x,M) ans+=src[j];
    if(j<m) ans+=src[j];
   }
   cout<<ans<<endl;
   break;
  }
 }
 return 0;
}
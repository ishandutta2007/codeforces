#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

LL X[3],Y[3];

LL getmax(int x,int y,int m){
 LL t = min(X[x],Y[y]);
 X[x]-=t; Y[y]-=t;
 return t*m;
}

int main() {

 int T; scanf("%d",&T);
 while(T--){
  rep(i,3) scanf("%lld",&X[i]);
  rep(i,3) scanf("%lld",&Y[i]);
  LL ans = 0;
  ans += getmax(2,1,2);
  ans += getmax(0,2,0);
  ans += getmax(2,2,0);
  ans += getmax(1,2,-2);
  printf("%lld\n",ans);
 }

 return 0;
}
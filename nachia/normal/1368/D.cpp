#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

int main() {
 UL N; scanf("%u",&N);
 UL S[20]={};
 rep(i,N){
  UL a; scanf("%u",&a);
  rep(j,20) S[j]+=((a&(1<<j))?1:0);
 }
 ULL ans=0;
 rep(i,N){
  ULL tmp=0;
  rep(j,20) if(S[j]>i) tmp|=(1ull<<j);
  ans+=tmp*tmp;
 }
 printf("%llu\n",ans);
 return 0;
}
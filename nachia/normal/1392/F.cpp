#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
LL A[1000000];
LL S;
LL ans[1000000];

int main() {
 scanf("%d",&N);
 rep(i,N) scanf("%lld",&A[i]);
 rep(i,N) A[i] += N-i;
 rep(i,N) S += A[i];
 rep(i,N){
  int n = N-i;
  ans[i] = (S-1)/n+1;
  S -= ans[i];
 }
 rep(i,N) ans[i] -= N-i;
 rep(i,N){ if(i)printf(" "); printf("%lld",ans[i]); } printf("\n");

 return 0;
}
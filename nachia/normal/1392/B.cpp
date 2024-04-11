#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
LL A[200000];
LL MA;
LL K;

void loop(){
 scanf("%d%lld",&N,&K);
 rep(i,N) scanf("%lld",&A[i]);
 MA = -1000000000; rep(i,N) MA = max(MA,A[i]);
 K--; rep(i,N) A[i]=MA-A[i];
 MA = -1000000000; rep(i,N) MA = max(MA,A[i]);
 if(K%2) rep(i,N) A[i]=MA-A[i];
 rep(i,N){
  if(i) printf(" ");
  printf("%lld",A[i]);
 } printf("\n");
}

int main() {
 int T; scanf("%d",&T);
 while(T--) loop();
 return 0;
}
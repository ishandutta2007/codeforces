
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

ull GCD(ull a,ull b){ return b?GCD(b,a%b):a; }

ull SumGCD(ull N){
  ull dN=N, SdN=0;
  while(dN!=0){ SdN+=dN%10; dN/=10; }
  return GCD(N,SdN);
}

void testcase(){
  ull N; scanf("%llu",&N);
  while(SumGCD(N)<=1) N++;
  printf("%llu\n",N);
}

int main(){
  int T; scanf("%d",&T);
  while(T--) testcase();
  return 0;
}
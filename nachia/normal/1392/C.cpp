#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
LL A[200000];
LL ans;

void loop(){
 scanf("%d",&N);
 rep(i,N) scanf("%lld",&A[i]);
 ans = 0;
 rep(i,N-1){
  if(A[i]<=A[i+1]) continue;
  ans += A[i]-A[i+1];
 }
 printf("%lld\n",ans);
}

int main() {
 int T; scanf("%d",&T);
 while(T--) loop();
 return 0;
}
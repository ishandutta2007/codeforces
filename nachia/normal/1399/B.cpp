#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int A[50];
int B[50];

void loop(){
 scanf("%d",&N);
 rep(i,N) scanf("%d",&A[i]);
 rep(i,N) scanf("%d",&B[i]);
 int mA=1000000000, mB=1000000000;
 rep(i,N) mA = min(mA,A[i]);
 rep(i,N) mB = min(mB,B[i]);
 LL ans=0;
 rep(i,N){
  int tmp = max(A[i]-mA,B[i]-mB);
  ans += tmp;
 }
 printf("%lld\n",ans);
}

int main() {
 int T; scanf("%d",&T);
 while(T--) loop();
 return 0;
}
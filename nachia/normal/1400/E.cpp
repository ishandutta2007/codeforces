#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
LL A[5000];

LL solve(int l,int r,int d=0){
 if(l==r) return 0;
 int m=l; for(int i=l; i<r; i++) if(A[m]>A[i]) m=i;
 LL tmp = A[m]-d;
 tmp += solve(l,m,A[m]);
 tmp += solve(m+1,r,A[m]);
 tmp = min(tmp,LL(r-l));
 return tmp;
}

int main() {
 scanf("%d",&N);
 rep(i,N) scanf("%lld",&A[i]);
 printf("%lld\n",solve(0,N));
 return 0;
}
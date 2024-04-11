#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

ULL diffULL(ULL a, ULL b){ return max(a,b)-min(a,b); }
ULL GCD(ULL a,ULL b){ return b?GCD(b,a%b):a; }

int main(){
	int N,M; scanf("%d%d",&N,&M);
  vector<ULL> A(N); rep(i,N) scanf("%llu",&A[i]);
  vector<ULL> B(M); rep(i,M) scanf("%llu",&B[i]);
  if(N==1){ rep(i,M) printf("%llu\n",A[0]+B[i]); return 0; }
  ULL x=diffULL(A[0],A[1]); rep(i,N-1) x=GCD(x,diffULL(A[i],A[i+1]));
  rep(i,M) printf("%llu\n",GCD(A[0]+B[i],x));
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#ifdef LOCAL
#define makel(A) scanf("%lld",&A)
#define pll(A) printf("%lld\n",A)
#else
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d\n",A)
#endif
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 1000100
LL dp[MAX];
int t[MAX],n;
main(){
	make(n);
	if(n==1){
		puts("0");
		return 0;
	}
	R(i,n)make(t[i]);
	dp[0] = 0;
	dp[1] = abs(t[0] - t[1]);
	F(i,2,n){
		int war = abs(t[i] - t[i-1]);
		dp[i] = max(dp[i-1], dp[i-2] + war);
		if(t[i] <= t[i-1] && t[i-1] <= t[i-2] ||
			t[i] >= t[i-1] && t[i-1] >= t[i-2]
		)
			ma(dp[i],dp[i-1] + war);
	}
	pll(dp[n-1]);
}
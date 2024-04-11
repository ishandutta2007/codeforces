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
#define pll(A) printf("%lld ",A)
#else
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d ",A)
#endif
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 101001
int t,k,dp[MAX],sp[MAX];
const int P = 1e9 +7;
main(){
	make(t);make(k);
	dp[0] = 1;
	R(i,MAX){
		if(!i)
			dp[i] = 1;
		else{
			dp[i] = dp[i-1];
			if(i-k >= 0)
				dp[i] += dp[i-k];
			dp[i] %= P;
		}
		sp[i+1] = sp[i] + dp[i];
		sp[i+1] %= P;
	}
	while(t--){
		int a,b;make(a);make(b);
		printf("%d\n",(sp[b+1] - sp[a] + P) % P);
	}
}
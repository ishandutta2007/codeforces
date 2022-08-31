#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
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
#define MAX 2001
int n,k;
int dp[MAX][MAX];
const int P = 1000 * 1000 * 1000 +7;
main(){
	make(k);make(n);
	F(i,1,k+1){
		dp[0][i] = 1;
	}
	F(i,1,n)F(j,1,k+1){
		for(int l = j; l <= k ;l+=j){
			dp[i][l] += dp[i-1][j];
			if(dp[i][l] >= P)
				dp[i][l] -= P;
		}
	}
	int wyn = 0;
	F(i,1,k+1){
		wyn += dp[n-1][i];
		if(wyn > P)wyn -= P;
	}
	printf("%d\n",wyn);
}
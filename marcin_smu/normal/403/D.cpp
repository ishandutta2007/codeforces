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
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d ",A)
//#define makel(A) scanf("%lld",&A)
//#define pll(A) printf("%lld ",A)
#define MAX 2510
int dp[MAX][MAX];
LL sil[MAX],od[MAX];
const int P = 1000 * 1000 * 1000 + 7;
LL pot(LL a,int wyk){
	LL wyn = 1;
	while(wyk){
		if(wyk&1){
			wyn *=a;
			wyn %=P;
		}
		wyk/=2;
		a*=a;
		a%=P;
	}
	return wyn;
}
LL po(int a,int b){
	return sil[a] * od[b] %P * od[a-b] %P;
}
int test(int n,int k){
	if(k*(k+1)/2 > n)return 0;
	int wyn=0;
	R(i,n){
		wyn += po(k+i,i) * dp[n-i][k] %P;
		if(wyn >= P)wyn -= P;
	}
	return wyn * sil[k] % P;
}
int wyn[MAX][MAX];
main(){
	sil[0] = 1;
	od[0] = 1;
	F(i,1,MAX){
		sil[i] = sil[i-1] * i % P;
		od[i] = pot(sil[i], P-2);
	}
	dp[0][0] = 1;
	F(i,1,MAX)F(j,1,i+1){
		dp[i][j] = dp[i-j][j] + dp[i-j][j-1];
		if(dp[i][j] >= P)dp[i][j] -= P;
	}
	//R(i,10){R(j,10)printf("(%d,%d)%d ",i,j,dp[i][j]);puts("");}
	R(i,1001)R(j,1001)wyn[i][j] = test(i,j);
	int _;make(_);while(_--){
		int i,j;
		make(i);make(j);
		printf("%d\n",wyn[i][j]);
	}
}
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
#define MAX 100101
int n,m,s,e,a[MAX],k,dp[MAX][311];
vector<int> b[MAX];
int szukaj(int co,int wie){
	int po = -1;
	int ko = b[co].size();
	while(po+1 != ko){
		int m = (po+ko)/2;
		if(b[co][m] <= wie)
			po = m;
		else
			ko = m;
	}
	if(ko != b[co].size())
		return b[co][ko];
	else
		return MAX;
}
main(){
	make(n);make(m);make(s);make(e);
	R(i,n)make(a[i]);
	R(i,m){
		int pom;
		make(pom);
		b[pom].PB(i);
	}
	k = s/e;
	int wyn = 0;
	R(i,n)R(j,k+1){
		if(j == 0){
			dp[i][j] = -1;
			continue;
		}else{
			if(i == 0){
				if(j == 1)
					dp[i][j] = szukaj(a[i],-1);
				else
					dp[i][j] = MAX;
			}else
				dp[i][j] = min(dp[i-1][j],szukaj(a[i],dp[i-1][j-1]));
			
			if(j*e + i+1 + dp[i][j]+1 <= s && dp[i][j] != MAX)
				wyn = max(wyn,j);
		}
	}
	printf("%d\n",wyn);
}
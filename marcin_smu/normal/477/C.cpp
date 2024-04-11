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
#define MAX 2011
int dp[MAX][MAX];
char s[MAX],p[MAX];
int n,m,q[MAX][MAX];
main(){
	scanf("%s%s",s,p);
	n=0;while(s[n])n++;
	m=0;while(p[m])m++;
	R(i,n+1)q[0][i] = i;
	R(i,m){
		q[i+1][0] = -1;
		R(j,n){
			if(p[i] == s[j])
				q[i+1][j+1] = q[i][j];
			else
				q[i+1][j+1] = q[i+1][j];
		}
	}
// 	R(i,n){
// 		printf("%d ",q[m][i+1]);
// 	}
// 	puts("");
	R(i,n){
		R(j,i+2){
			dp[i+1][j] = dp[i][j];
			if(j)ma(dp[i+1][j],dp[i][j-1]);
			if(q[m][i+1] != -1){
				int us = i - q[m][i+1] + 1 - m;
				if(j>=us && q[m][i+1] >= j-us)
					ma(dp[i+1][j],dp[q[m][i+1]][j-us] + 1);
			}
	//		printf("%d ",dp[i+1][j]);
		}
	//	puts("");
	}
	
	R(i,n+1)printf("%d ",dp[n][i]);
	puts("");
}
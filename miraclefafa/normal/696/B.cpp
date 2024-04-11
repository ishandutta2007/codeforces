#include <cstdio>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

const int N=101000;
int n,p[N],sz[N];
double dp[N];
int main() {
	scanf("%d",&n);
	rep(i,2,n+1) scanf("%d",p+i);
	rep(i,1,n+1) sz[i]=1;
	per(i,2,n+1) sz[p[i]]+=sz[i];
	dp[1]=1;
	rep(i,2,n+1) dp[i]=dp[p[i]]+0.5*(1+sz[p[i]]-sz[i]);
	rep(i,1,n+1) printf("%.10f ",dp[i]);
	puts("");
}
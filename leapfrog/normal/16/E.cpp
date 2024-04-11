//
//
#include<bits/stdc++.h>
using namespace std;const double eps=1e-8;
int n;double dp[(1<<18)+5][20],a[20][20];
inline void dfs(int S)
{
	for(int i=0;i<n;i++) if(dp[S][i]>eps) return;
	int ct=0,w;for(int i=0;i<n;i++) if(S&(1<<i)) ++ct,w=i;
	if(ct==1) return(void)(dp[S][w]=1);else ct=ct*(ct-1)>>1;
	for(int i=0;i<n;i++) if(S&(1<<i)) for(int j=i+1;j<n;j++) if(S&(1<<j))
	{
		dfs(S^(1<<i)),dfs(S^(1<<j));
		for(int k=0;k<n;k++) dp[S][k]+=(dp[S^(1<<j)][k]*a[i][j]+dp[S^(1<<i)][k]*(1-a[i][j]))/ct;
		// printf("%d , %lf , %lf\n",S,dp[S][0],dp[S^(1<<j)][0]*a[i][j]+dp[S^(1<<i)][0]*(1-a[i][j]));
	}
	// printf("%d , %d -> %lf\n",S,ct,dp[S][0]);
}
int main()
{
	scanf("%d",&n),memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%lf",&a[i][j]);
	dfs((1<<n)-1);for(int i=0;i<n;i++) printf("%lf%c",dp[(1<<n)-1][i],i==n-1?'\n':' ');
	return 0;
}
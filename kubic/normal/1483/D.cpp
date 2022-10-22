#include <bits/stdc++.h>
using namespace std;
#define N 605
#define ll long long
int n,m,c,ans;ll e[N][N],dp[N][N],z[N][N],mx[N][N];bool vs[N][N];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) for(int j=1;j<i;++j) dp[i][j]=dp[j][i]=1e18; 
	for(int i=1,u,v,w;i<=m;++i)
		scanf("%d %d %d",&u,&v,&w),e[u][v]=e[v][u]=dp[u][v]=dp[v][u]=w;
	scanf("%d",&c);
	for(int i=1,u,v,w;i<=c;++i)
		scanf("%d %d %d",&u,&v,&w),z[u][v]=z[v][u]=w;
	for(int k=1;k<=n;++k) for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
		dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) for(int k=1;k<=n;++k)
		mx[i][j]=max(mx[i][j],z[i][k]-dp[j][k]);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
		if(e[i][j] && !vs[j][i]) for(int k=1;k<=n;++k)
			if(dp[k][i]+e[i][j]<=mx[k][j]) {vs[i][j]=1;++ans;break;}
	printf("%d\n",ans);return 0;
}
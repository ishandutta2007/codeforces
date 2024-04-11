#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;
using std::sort;
inline int mabs(int x)
{
	return x<0?-x:x;
}
const int N=405,inf=0x3f3f3f3f;
int n,q,ans;
int t[N];
int dp[N][N];
inline void solve()
{
	register int i,j;
	scanf("%d",&n);ans=inf;
	for(i=1;i<=n;i++)
		scanf("%d",&t[i]);
	sort(t+1,t+n+1);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(i=0;i<=n*2;i++)
		for(j=0;j<=n;j++)
			if(dp[i][j]<inf)
			{
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
				if(j<n)
					dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+mabs(t[j+1]-(i+1)));
				else
					ans=min(ans,dp[i][j]);
			}
	printf("%d\n",ans);
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
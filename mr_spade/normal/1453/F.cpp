#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;
const int N=3005;
int n;
int a[N];
int cnt[N][N];
int dp[N][N],smn[N][N];
inline void solve()
{
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(j=1;j<=n;j++)
		for(i=j;i>=1;i--)
			cnt[i][j]=cnt[i+1][j]+(i+a[i]>j);
	for(i=0;i<=n+1;i++)
	{
		memset(dp[i],0x3f,sizeof(int)*(n+2));
		memset(smn[i],0x3f,sizeof(int)*(n+2));
	}
	dp[n][n+1]=0;
	memset(smn[n],0,sizeof(int)*(n+2));
	for(i=n-1;i>=1;i--)
		for(j=n;j>=i+1;j--)
		{
			if(i+a[i]>=j)
				dp[i][j]=smn[j][i+a[i]+1]+cnt[i+1][j-1];
			smn[i][j]=min(smn[i][j+1],dp[i][j]);
		}
	int ans=0x3f3f3f3f;
	for(i=2;i<=n;i++)
		ans=min(ans,dp[1][i]);
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
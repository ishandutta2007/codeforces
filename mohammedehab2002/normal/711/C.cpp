#include <iostream>
using namespace std;
long long dp[105][105][105],col[105],p[105][105];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&col[i]);
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<m;x++)
		scanf("%I64d",&p[i][x]);
	}
	for (int i=0;i<=n;i++)
	{
		for (int x=0;x<=k;x++)
		{
			for (int j=1;j<=m;j++)
			{
				dp[i][x][j]=(1LL<<60);
				if (!i && !x)
				dp[i][x][j]=0;
				if (!i || !x)
				continue;
				if (col[i-1] && col[i-1]!=j)
				continue;
				if (col[i-1])
				p[i-1][j-1]=0;
				for (int l=1;l<=m;l++)
				{
					if (j==l && i!=1)
					dp[i][x][j]=min(dp[i][x][j],dp[i-1][x][l]+p[i-1][j-1]);
					else
					dp[i][x][j]=min(dp[i][x][j],dp[i-1][x-1][l]+p[i-1][j-1]);
				}
			}
		}
	}
	long long ans=(1LL<<60);
	for (int i=1;i<=m;i++)
	ans=min(ans,dp[n][k][i]);
	if (ans==(1LL<<60))
	ans=-1;
	printf("%I64d",ans);
}
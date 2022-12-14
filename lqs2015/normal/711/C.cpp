#include<iostream>
using namespace std;
const long long Inf=1e18;
long long dp[111][111][111],col[111],p[111][111],ans;
long long n,m,k;
int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) cin>>col[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		cin>>p[i][j];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=k;j++)
		{
			for (int h=1;h<=m;h++)
			{
				dp[i][j][h]=Inf;
			}
		}
	}
	if (col[1]) 
	{
		dp[1][1][col[1]]=0;
	}
	else
	{
		for (int i=1;i<=m;i++)
		{
			dp[1][1][i]=p[1][i];
		}
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=k;j++)
		{
			if (col[i])
			{
				if (col[i-1])
				{
					dp[i][j][col[i]]=col[i]==col[i-1] ? dp[i-1][j][col[i-1]] : dp[i-1][j-1][col[i-1]];
					continue;
				}
				for (int pc=1;pc<=m;pc++)
				{
					dp[i][j][col[i]]=min(dp[i][j][col[i]],pc==col[i] ? dp[i-1][j][pc] : dp[i-1][j-1][pc]);
				}
				continue;
			}
			for (int nc=1;nc<=m;nc++)
			{
				if (col[i-1])
				{
					dp[i][j][nc]=min(dp[i][j][nc],nc==col[i-1] ? dp[i-1][j][col[i-1]]+p[i][nc] : dp[i-1][j-1][col[i-1]]+p[i][nc]);
					continue;
				}
				for (int pc=1;pc<=m;pc++)
				{
					dp[i][j][nc]=min(dp[i][j][nc],nc==pc ? dp[i-1][j][pc]+p[i][nc] : dp[i-1][j-1][pc]+p[i][nc]);
				}
			}
		}
	}
	ans=Inf;
	for (int i=1;i<=m;i++)
	{
		ans=min(ans,dp[n][k][i]);
	}
	if (ans>=Inf) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
char mat[1111][1111];
int n,m,x,y,dp[1111][1111][2],ans,cntpoint[1111],cntj[1111];
bool f[1111][1111];
int main()
{
	cin>>n>>m>>x>>y;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>mat[i][j];
			cntpoint[j]+=(mat[i][j]=='.');
			cntj[j]+=(mat[i][j]=='#');
		}
	}
	for (int i=0;i<=m;i++)
	{
		for (int j=0;j<=y+1;j++)
		dp[i][j][0]=dp[i][j][1]=1e9;
	}
	dp[0][0][0]=dp[0][0][1]=0;
	for (int i=1;i<=m;i++)
	{
		for (int j=y+1;j>=1;j--)
		{
			for (int k=0;k<=1;k++)
			{
				if (j==1)
				{
					for (int h=x;h<=y;h++) dp[i][j][k]=min(dp[i][j][k],dp[i-1][h][1-k]);
					dp[i][j][k]+=(k ? cntj[i] : cntpoint[i]);
				}
				dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][k]+(k ? cntj[i] : cntpoint[i]));
			//	cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl; 
			}
		}
	}
	ans=1e9;
	for (int i=x;i<=y;i++) 
	{
		for (int j=0;j<=1;j++)
		{
			ans=min(ans,dp[m][i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
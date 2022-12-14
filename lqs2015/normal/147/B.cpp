#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,x,y,xy,yx,dp[10][333][333],dist[333][333],pdist[333][333],ans,r;
bool f;
vector<pair<int,int> > g[333];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<=9;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=n;k++)
			{
				if (j==k) dp[i][j][k]=0;
				else dp[i][j][k]=-1e9;
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&y,&xy,&yx);
		g[x].push_back(make_pair(x,xy));
		g[y].push_back(make_pair(y,yx));
		dp[0][x][y]=xy;
		dp[0][y][x]=yx;  
	}
	for (int i=1;i<=9;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int h=1;h<=n;h++)
			{
				for (int k=1;k<=n;k++)
				{	
					dp[i][j][h]=max(dp[i][j][h],dp[i-1][j][k]+dp[i-1][k][h]);
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i==j) dist[i][j]=0;
			else dist[i][j]=-1e9;
		}
	}
	for (int i=9;i>=0;i--)
	{
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=n;k++)
			{
				if (j==k) pdist[j][k]=0;
				else pdist[j][k]=-1e9;
			}
		}
		for (int j=1;j<=n;j++)
		{
			for (int h=1;h<=n;h++)
			{
				for (int k=1;k<=n;k++)
				{
					pdist[j][h]=max(pdist[j][h],dist[j][k]+dp[i][k][h]);
				}
			}
		}
		f=0;
		for (int j=1;j<=n;j++)
		{
			if (pdist[j][j]>0)
			{
				f=1;
				break;
			}
		}
		if (!f)
		{
			ans|=(1<<i);
			for (int j=1;j<=n;j++)
			{
				for (int k=1;k<=n;k++)
				dist[j][k]=pdist[j][k];
			}
		}
	}
	for (int j=1;j<=n;j++)
	{
		for (int k=1;k<=n;k++)
		{
			if (j==k) pdist[j][k]=0;
			else pdist[j][k]=-1e9;
		}
	}
	for (int j=1;j<=n;j++)
	{
		for (int h=1;h<=n;h++)
		{
			for (int k=1;k<=n;k++)
			{
				pdist[j][h]=max(pdist[j][h],dist[j][k]+dp[0][k][h]);
			}
		}
	}
	f=0;
	for (int j=1;j<=n;j++)
	{
		if (pdist[j][j]>0)
		{
			f=1;
			break;
		}
	}
	if (f) ans++;
	if (ans==1023) ans=0;	
	printf("%d\n",ans);
	return 0;
}
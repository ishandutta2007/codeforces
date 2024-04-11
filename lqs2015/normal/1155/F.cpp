#include<bits/stdc++.h>
using namespace std;
struct pth
{
	int x,y,msk;
}fuck[22222];
int n,m,mp[22][22],x,y,dp[22][22][22222],path[22][22][22222],msk,c;
int DP[22222],P[22222];
vector<pair<int,int> > ans;
void getp(pth &u)
{
	while(~path[u.x][u.y][u.msk])
	{
		c=path[u.x][u.y][u.msk];
		u.msk^=(1<<c);
		ans.push_back(make_pair(c+1,u.y+1));
		u.y=c;
	}
	for (int i=0;i<n;i++)
	{
		if (u.msk&(1<<i)) c=i;
	}
	ans.push_back(make_pair(u.x+1,c+1));
	ans.push_back(make_pair(u.y+1,c+1));
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);x--;y--;
		mp[x][y]=mp[y][x]=1;
	}
	memset(path,-1,sizeof(path));
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			for (int k=0;k<(1<<n);k++)
			dp[i][j][k]=1e9;
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			for (int k=0;k<n;k++)
			{
				for (int h=0;h<n;h++)
				{
					if (!mp[i][j] || !mp[j][k] || !mp[k][h] || i==k || j==h) continue;
					dp[i][h][(1<<j)|(1<<k)]=3;
					path[i][h][(1<<j)|(1<<k)]=k;
				}
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			for (int k=0;k<n;k++)
			{
				if (!mp[i][j] || !mp[j][k] || i==k) continue;
				dp[i][k][1<<j]=2;
			}
		}
	}
	for (int i=0;i<(1<<n);i++)
	{
		for (int j=0;j<n;j++)
		{
			for (int k=0;k<n;k++)
			{
				for (int h=0;h<n;h++)
				{
					if (i&(1<<h)) continue;
					if (!mp[k][h]) continue;
					if (dp[j][h][i|(1<<k)]>dp[j][k][i]+1)
					{
						dp[j][h][i|(1<<k)]=dp[j][k][i]+1;
						path[j][h][i|(1<<k)]=k;
					}
				}
			}
		}
	}
	DP[1]=0;
	for (int i=2;i<(1<<n);i++) DP[i]=1e9;
	memset(P,-1,sizeof(P));
	for (int i=1;i<(1<<n);i++)
	{
		for (int j=0;j<n;j++)
		{
			if (!(i&(1<<j))) continue;
			for (int k=0;k<n;k++)
			{
				if (!(i&(1<<k))) continue;
				msk=(1<<n)-1-i;
				for (int h=msk;h;h=(h-1)&msk)
				{
					if (DP[i|h]>DP[i]+dp[j][k][h])
					{
						DP[i|h]=DP[i]+dp[j][k][h];
						P[i|h]=i;
						fuck[i|h]=(pth){j,k,h};
					}
				}				
			}
		}
	}
	msk=(1<<n)-1;
	while(msk>1)
	{
		getp(fuck[msk]);
		msk=P[msk];
	}
	printf("%d\n",(int)ans.size());
	for (int i=0;i<ans.size();i++)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}
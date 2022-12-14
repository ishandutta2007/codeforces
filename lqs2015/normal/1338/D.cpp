#include<bits/stdc++.h>
using namespace std;
int n,x,y,dp[111111][2],ans,f[5][5],G[5][5];
vector<int> g[111111];
void upd(int &x,int y)
{
	if (x<y) x=y;
}
void dfs(int i,int fa)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
	}
	for (int j=0;j<2;j++)
	{
		for (int k=0;k<3;k++)
		{
			f[j][k]=-1e9;
		}
	}
	f[0][0]=0;f[1][0]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		for (int k=0;k<2;k++)
		{
			for (int h=0;h<3;h++)
			G[k][h]=-1e9;
		}
		for (int k=0;k<2;k++)
		{
			for (int h=0;h<3;h++)
			{
				if (!k)
				{
					upd(G[k][h],f[k][h]+1);					
				}
				else
				{
					upd(G[k][h],f[k][h]);
				}
				for (int p=0;p<2;p++)
				{
					if (k&p) continue;
					if (h==2) continue;
					upd(G[k][h+1],f[k][h]+dp[to][p]);
				}
			}
		}
		memcpy(f,G,sizeof(G));
	}
	if (fa) 
	{
		ans=max(ans,max(f[0][2]+1,f[1][2]));
		ans=max(ans,max(f[0][1]+1,f[1][1]));
	}
	else
	{
		ans=max(ans,max(f[0][2],f[1][2]));
		ans=max(ans,max(f[0][1],f[1][1]));
	}
	dp[i][0]=max(f[0][1],0);
	dp[i][1]=max(f[1][1],1);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
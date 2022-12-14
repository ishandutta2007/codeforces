#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,x,y,f[5555][3],sub[5555],ans,cnt,pre;
vector<int> dp[5555][3];
pair<int,int> res[11111];
vector<int> g[5555];
void dfs(int i,int fa)
{
	sub[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		sub[i]+=sub[to];
	}
	for (int j=0;j<=sub[i];j++)
	{
		f[j][0]=f[j][1]=f[j][2]=-1e9;
	}
	f[1][1]=f[0][0]=0;f[0][2]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		for (int k=sub[i];k>=0;k--)
		{
			for (int h=0;h<=2;h++)
			{
				if (f[k][h]<0) continue;
				for (int s=1;s<=sub[to];s++)
				{
					for (int t=0;t<=2;t++)
					{
						if (h && t && h!=t) continue;
						f[k+s][h]=max(f[k+s][h],f[k][h]+dp[to][t][s]);
					}
				}
				pre=f[k][h];
				for (int t=0;t<=2;t++)
				{
					if (h && t && h!=t) continue;
					f[k][h]=max(f[k][h],pre+dp[to][t][0]);
				}
			}
		}
	}
	for (int j=0;j<=sub[i];j++)
	{
		for (int k=0;k<=2;k++)
		{
			dp[i][k].push_back(f[j][k]); 
		}
	}
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
	for (int i=0;i<=2;i++)
	{
		for (int j=1;j<=n;j++) 
		{
			if (dp[1][i][j]>0) ans=max(ans,j+dp[1][i][j]);
		}
	}
	for (int i=0;i<=2;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (dp[1][i][j]>0 && j+dp[1][i][j]==ans) res[++cnt]=make_pair(j,dp[1][i][j]);
		}
	}
	sort(res+1,res+cnt+1);
	cnt=unique(res+1,res+cnt+1)-res-1;
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++) printf("%d %d\n",res[i].first,res[i].second);
	return 0;
}
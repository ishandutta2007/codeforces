#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
int n,m,h,u[111111],x,y,cnt,mn,cc[111111],dp[111111],sz[111111],mni;
vector<int> g[111111],rg[111111],v,ng[111111],col[111111];
bool used[111111];
map<pair<int,int>,int> mp;
void dfs(int i)
{
	used[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (used[to]) continue;
		dfs(to);
	}
	v.push_back(i); 
}
void rdfs(int i)
{
	used[i]=1;
	col[cnt].push_back(i); 
	cc[i]=cnt;
	for (int j=0;j<rg[i].size();j++)
	{
		int to=rg[i][j];
		if (used[to]) continue;
		rdfs(to);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for (int i=1;i<=n;i++) scanf("%d",&u[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if ((u[x]+1)%h==u[y]) 
		{
			g[x].push_back(y);
			rg[y].push_back(x); 
		}
		if ((u[y]+1)%h==u[x]) 
		{
			g[y].push_back(x);
			rg[x].push_back(y); 
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!used[i]) dfs(i);
	}
	memset(used,0,sizeof(used));
	for (int i=n-1;i>=0;i--)
	{
		if (!used[v[i]])
		{
			cnt++;
			rdfs(v[i]);
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<g[i].size();j++)
		{
			if (cc[i]!=cc[g[i][j]] && !mp[make_pair(cc[i],cc[g[i][j]])]) 
			{
				ng[cc[i]].push_back(cc[g[i][j]]);
				mp[make_pair(cc[i],cc[g[i][j]])]=1;
			}
		}
	}
	mn=1e9;
	for (int i=1;i<=cnt;i++)
	{
		if (ng[i].size()==0 && col[i].size()<mn) 
		{
			mn=col[i].size();
			mni=i;
		}
	}
	printf("%d\n",mn);
	for (int i=0;i<col[mni].size();i++) printf("%d ",col[mni][i]);
	printf("\n");
	return 0;
}
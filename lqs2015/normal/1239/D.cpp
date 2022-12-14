#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,m,x,y,col[1111111],cc,out[1111111],sz[1111111];
vector<int> g[1111111],v,rg[1111111];
bool used[1111111],f;
void dfs(int i)
{
	used[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		if (!used[g[i][j]]) dfs(g[i][j]);
	}
	v.push_back(i);
}
void rdfs(int i)
{
	col[i]=cc;sz[cc]++;
	for (int j=0;j<rg[i].size();j++)
	{
		if (!col[rg[i][j]]) rdfs(rg[i][j]);
	}
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) 
		{
			g[i].clear();
			rg[i].clear();
		}
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			if (x!=y)
			{
				g[x].push_back(y);
				rg[y].push_back(x);
			}
		}
		v.clear();
		for (int i=1;i<=n;i++) used[i]=col[i]=0;
		for (int i=1;i<=n;i++)
		{
			if (!used[i]) dfs(i);
		}
		cc=0;
		for (int i=(int)v.size()-1;i>=0;i--)
		{
			if (!col[v[i]]) 
			{
				++cc;sz[cc]=0;
				rdfs(v[i]);
			}
		}
		for (int i=1;i<=cc;i++) out[i]=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<g[i].size();j++)
			{
				int to=g[i][j];
				if (col[i]!=col[to]) out[col[i]]++;
			}
		}
		f=0;
		if (cc==1)
		{
			printf("No\n");
			continue;
		}
		for (int i=1;i<=cc;i++)
		{
			if (!out[i])
			{
				f=1;
				printf("Yes\n");
				printf("%d %d\n",sz[i],n-sz[i]);
				for (int j=1;j<=n;j++)
				{
					if (col[j]==i) printf("%d ",j);
				}
				printf("\n");
				for (int j=1;j<=n;j++)
				{
					if (col[j]!=i) printf("%d ",j);
				}
				printf("\n");
				break;
			}
		}
		if (!f) printf("No\n");
	}
	return Accepted;
}
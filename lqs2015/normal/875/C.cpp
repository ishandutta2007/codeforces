#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
using namespace std;
int n,m,pl,l,p[111111],nn[111111],up[111111],down[111111],pos;
bool used[111111],col[111111],vis[111111];
vector<int> g[111111];
void dfs(int i)
{
	used[i]=1;
	if (col[i])
	{
		printf("No\n");
		exit(0);
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (used[to]) continue;
		dfs(to);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&l);
		for (int j=1;j<=l;j++)
		{
			scanf("%d",&nn[j]);
		}
		if (i>1)
		{
			pos=0;
			for (int j=1;j<=min(l,pl);j++)
			{
				if (nn[j]!=p[j]) 
				{
					pos=j;
					break;
				}
			}
			if (!pos) 
			{
				if (l<pl) 
				{
					printf("No\n");
					return 0;
				}
				else vis[i-1]=1;
			}
			else
			{
				if (p[pos]<nn[pos]) 
				{
					vis[i-1]=1;
					g[nn[pos]].push_back(p[pos]); 
				}
				up[i-1]=p[pos];
				down[i]=nn[pos];
			}
		}
		pl=l;
		for (int j=1;j<=l;j++)
		{
			p[j]=nn[j];
		}
	}
	for (int i=1;i<n;i++)
	{
		if (!vis[i])
		{
			col[down[i+1]]=1;
			dfs(up[i]);
		}
	}
	for (int i=1;i<=m;i++)
	{
		if (used[i] && col[i])
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	int cnt=0;
	for (int i=1;i<=m;i++) 
	{
		if (used[i]) cnt++;
	}
	printf("%d\n",cnt);
	for (int i=1;i<=m;i++)
	{
		if (used[i]) printf("%d ",i);
	}
	printf("\n");
	return 0;
}
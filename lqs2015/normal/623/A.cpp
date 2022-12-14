#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,x,y,col[555],deg[555];
bool f[555][555],flag;
vector<int> g[555];
void dfs(int i,int c)
{
	col[i]=c;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (!col[to]) 
		{
			dfs(to,3-c);
		}
		else
		{
			if (col[to]+col[i]!=3) flag=1;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		f[x][y]=f[y][x]=1;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (!f[i][j])
			{
				g[i].push_back(j);
				g[j].push_back(i);  
				deg[i]++;deg[j]++;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!col[i] && deg[i]) 
		{
			dfs(i,1);	
			break;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!col[i] && deg[i]) 
		{
			printf("No\n");
			return 0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i==j) continue;
			if (col[i] && col[j] && col[i]!=col[j]) 
			{
				if (f[i][j]) 
				{
					printf("No\n");
					return 0;
				}
			}
		}
	}
	if (flag) printf("No\n");
	else
	{
		printf("Yes\n");
		for (int i=1;i<=n;i++) 
		{
			if (!col[i]) printf("b");
			else if (col[i]==1) printf("a");
			else printf("c");
		}
		printf("\n");
	}
	return Accepted;
}
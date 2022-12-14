#include<bits/stdc++.h>
using namespace std;
int t,T,n,m,col[111111],x,y,l[111111],r[111111],ls,rs;
vector<int> g[111111];
queue<int> q;
void Out()
{
	printf("IMPOSSIBLE\n");
	exit(0);
}
void dfs(int i,int c)
{
	col[i]=c;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (col[to])
		{
			if (col[to]!=3-c) Out();
		}
		else
		{
			dfs(to,3-c);
		}
	}
}
int main()
{
	scanf("%d%d",&t,&T);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
	}
	ls=-1e9;rs=1e9;
	for (int i=1;i<=n;i++) 
	{
		ls=max(ls,l[i]);
		rs=min(rs,r[i]);
	}
	if (ls+rs<t) ls+=(t-ls-rs);
	if (ls+rs>T) rs-=(ls+rs-T);
	if (ls<0 || rs<0) Out();
	for (int i=1;i<=n;i++)
	{
		if (l[i]<=ls && r[i]>=ls)
		{
			if (l[i]<=rs && r[i]>=rs);
			else col[i]=1;
		}
		else 
		{
			if (l[i]<=rs && r[i]>=rs) col[i]=2;
			else Out();
		}
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
	{
		if (col[i]) q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i];
			if (col[to])
			{
				if (col[to]!=3-col[x]) Out();
			}
			else 
			{
				col[to]=3-col[x];
				q.push(to);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!col[i]) dfs(i,1);
	}
	printf("POSSIBLE\n");
	printf("%d %d\n",ls,rs);
	for (int i=1;i<=n;i++)
	{
		printf("%d",col[i]);
	}
	printf("\n");
	return 0;
}
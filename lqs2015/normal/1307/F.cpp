#include<bits/stdc++.h>
using namespace std;
int n,k,r,cnt,x,y,dist[444444],pa[444444],dep[444444],an[444444][22],q,xx,yy;
vector<int> g[444444];
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return;
	pa[rx]=ry;
}
void bfs()
{
	memset(dist,-1,sizeof(dist));
	queue<int> q;
	for (int i=1;i<=r;i++)
	{
		scanf("%d",&x);
		dist[x]=0;
		q.push(x);
	}
	while(!q.empty())
	{
		x=q.front();q.pop();
		if (dist[x]>=k) continue;
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i];
			Union(x,to);
			if (!~dist[to])
			{
				dist[to]=dist[x]+1;
				q.push(to);
			}
		}
	}
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=18;i>=0;i--)
	{
		if (dep[an[x][i]]>=dep[y]) x=an[x][i];
	}
	if (x==y) return x;
	for (int i=18;i>=0;i--)
	{
		if (an[x][i]!=an[y][i])
		{
			x=an[x][i];
			y=an[y][i];
		}
	}
	return an[x][0];
}
void dfs(int i,int fa)
{
	dep[i]=dep[fa]+1;
	an[i][0]=fa;
	for (int j=1;j<=18;j++) an[i][j]=an[an[i][j-1]][j-1];
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
	}
}
int getan(int x,int p)
{
	for (int i=0;i<=18;i++)
	{
		if (p&(1<<i)) x=an[x][i];
	}
	return x;
}
int main()
{
	scanf("%d%d%d",&n,&k,&r);
	cnt=n;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		cnt++;
		g[x].push_back(cnt);
		g[y].push_back(cnt);
		g[cnt].push_back(x);
		g[cnt].push_back(y);
	}
	for (int i=1;i<=cnt;i++) pa[i]=i;
	bfs();
	dfs(1,0);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		int lc=lca(x,y);
		if (dep[x]+dep[y]-(dep[lc]<<1)<=(k<<1)) 
		{
			printf("YES\n");
		}
		else
		{
			int cln=dep[x]+dep[y]-(dep[lc]<<1);
			if (dep[x]-dep[lc]>=k) xx=getan(x,k);
			else xx=getan(y,cln-k);
			if (dep[y]-dep[lc]>=k) yy=getan(y,k);
			else yy=getan(x,cln-k);
			if (root(xx)==root(yy)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
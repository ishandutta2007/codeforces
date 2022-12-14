#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std; 
int n,m,x,y,pa[333333],val[333333],dist[333333],dep[333333];
vector<int> g[333333],tg[333333],v[333333];
vector<pair<int,int> > fg[333333];
bool used[333333];
void dfs(int i)
{
	used[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (used[to]) v[to].push_back(i);
		else 
		{
			tg[i].push_back(to);
			pa[to]=i;
			dfs(to); 
		} 
	}
}
void Init(int i)
{
	for (int j=0;j<tg[i].size();j++)
	{
		int to=tg[i][j];
		dep[to]=dep[i]+1;
		Init(to);
	}
}
int bfs(int s)
{
	queue<int> q;
	q.push(s);
	for (int i=1;i<=n;i++) dist[i]=1e9;
	dist[s]=0;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for (int i=0;i<fg[x].size();i++)
		{
			int to=fg[x][i].first,val=fg[x][i].second;
			if (dist[to]>dist[x]+val)
			{
				dist[to]=dist[x]+val;
				q.push(to); 
			}
		}
	}
	int mxi=1;
	for (int i=2;i<=n;i++)
	{
		if (dist[i]>dist[mxi]) mxi=i;
	}
	return mxi;
}
void ddfs(int i)
{
	for (int j=0;j<tg[i].size();j++)
	{
		int to=tg[i][j];
		ddfs(to);
		val[i]+=val[to];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	dfs(1);
	Init(1);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<v[i].size();j++)
		{
			int to=v[i][j];
			if (pa[to]==i || dep[to]<dep[i]) continue;
			val[to]++;
			val[i]--;
		}
	}
	ddfs(1);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<tg[i].size();j++)
		{
			int to=tg[i][j];
			if (val[to]>0)
			{
				fg[i].push_back(make_pair(to,0));
				fg[to].push_back(make_pair(i,0));  
			} 
			else
			{
				fg[i].push_back(make_pair(to,1));
				fg[to].push_back(make_pair(i,1));  
			}
		}
	}
	y=bfs(1);
	x=bfs(y);
	printf("%d\n",dist[x]);
	return 0;
}
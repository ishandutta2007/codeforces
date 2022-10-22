#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=3000;
const int INF=1e8;
struct node
{
	int id,step;
};
int n,m,sa,ta,la,sb,tb,lb;
bool vis[N+5];
int d[N+5][N+5];
vector<int> g[N+5];
void bfs(int s)
{
	memset(vis,0,sizeof(vis));
	queue<node> q;
	vis[s]=1;
	q.push(node{s,0});
	while(!q.empty())
	{
		int u=q.front().id;
		int cost=q.front().step;
		q.pop();
		d[s][u]=cost;
		cost++;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(vis[v]) continue;
			q.push(node{v,cost});
			vis[v]=1;
		}
	}
	return;
}
void init()
{
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) d[i][j]=INF;
	for(int i=1;i<=n;i++) bfs(i);
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	init();
	scanf("%d%d%d%d%d%d",&sa,&ta,&la,&sb,&tb,&lb);
	if(d[sa][ta]>la||d[sb][tb]>lb)
	{
		printf("-1\n");
		return 0;
	}
	int ans=INF;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(d[sa][i]+d[i][j]+d[j][ta]>la&&d[sa][j]+d[j][i]+d[i][ta]>la) continue;
			if(d[sb][i]+d[i][j]+d[j][tb]>lb&&d[sb][j]+d[j][i]+d[i][tb]>lb) continue;
			ans=min(ans,min(d[sa][i]+d[j][ta],d[sa][j]+d[i][ta])+min(d[sb][i]+d[j][tb],d[sb][j]+d[i][tb])+d[i][j]);
		}
	}
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(d[i][j]==0) continue;
			if(d[sa][i]+d[i][j]+d[j][ta]==d[sa][sb]&&d[sb][i]+d[i][j]+d[j][tb]==d[ta][tb])
			{
				flag=1;
				break;
			}
		}
	}
	if(!flag) ans=min(ans,d[sa][ta]+d[sb][tb]);
	printf("%d\n",m-ans);
	return 0;
}
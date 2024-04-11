#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 400005
using namespace std;
int n,m,cnt,id[N][2];
vector<pa>G[N];
int dis[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		id[i][0]=++cnt,id[i][1]=++cnt;
		G[id[i][0]].push_back(mp(id[i][1],0));
	}
	for (int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		G[id[x][0]].push_back(mp(id[y][0],w));
		G[id[y][1]].push_back(mp(id[x][1],w));
	}
	memset(dis,0x3f,sizeof(dis));
	dis[id[1][0]]=0;
	priority_queue<pa>q;
	q.push(mp(0ll,id[1][0]));
	while (!q.empty())
	{
		int u=q.top().se,w=-q.top().fi;
		q.pop();
		if (w!=dis[u]) continue;
		for (auto U:G[u])
		{
			int v=U.fi,ww=U.se;
			if (dis[v]>dis[u]+ww)
			{
				dis[v]=dis[u]+ww;
				q.push(mp(-dis[v],v));
			}
		}
	}
	for (int i=2;i<=n;i++)
		if (dis[id[i][1]]==dis[0]) cout<<-1<<" ";
		else cout<<dis[id[i][1]]<<" ";
	cout<<endl;
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
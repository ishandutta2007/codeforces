// Lynkcat.
// Problem: C. Keshi in Search of AmShZ
// Contest: Codeforces - Codeforces Round #800 (Div. 1)
// URL: https://codeforces.com/contest/1693/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
#define N 200005 
using namespace std;
int n,m;
poly G[N];
int dis[N];
int du[N];
int cnt[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		du[x]++;
		G[y].push_back(x);
	}
	priority_queue<pa>q;
	for (int i=1;i<=n;i++) dis[i]=inf;
	dis[n]=0;
	q.push(mp(0,n));
	while (!q.empty())
	{
		int u=q.top().se;
		int w=q.top().fi;
		q.pop();
		w=-w;
		if (w!=dis[u]) continue;
		for (auto v:G[u])
		{
			cnt[v]++;
			if (dis[v]>dis[u]+du[v]-cnt[v]+1)
			{
				dis[v]=dis[u]+du[v]-cnt[v]+1;
				q.push(mp(-dis[v],v));
			}
		}
	}
	cout<<dis[1]<<endl;
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
// Lynkcat.
// Problem: D. The Winter Hike
// URL: https://codeforces.com/contest/1621/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// -----------------------------------------------

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
#define N 505
using namespace std;
vector<pa>G[N*N];
int a[N][N];
int dis[N*N];
int id[N][N];
int tot;
int n;
void ad(int x,int y,int w)
{
	G[x].push_back(mp(y,w));
}
void BellaKira()
{
	cin>>n;
	int tot=0;
	for (int i=0;i<n*2;i++)
		for (int j=0;j<n*2;j++)
			cin>>a[i][j];
	for (int i=0;i<n*2;i++)
		for (int j=0;j<n*2;j++)
		{
			id[i][j]=++tot;
		}
	for (int i=n;i<n*2;i++)
	{
		ad(id[n][i],id[n-1][i],0);
		ad(id[n*2-1][i],id[0][i],0);
	}
	for (int i=n;i<n*2;i++)
	{
		ad(id[i][n],id[i][n-1],0);
		ad(id[i][n*2-1],id[i][0],0);
	}
	for (int i=n;i<n*2;i++)
		for (int j=0;j<n;j++)
		{
			ad(id[i][j],id[(i-1+n*2)%(n*2)][j],a[i][j]);
			ad(id[i][j],id[(i+1+n*2)%(n*2)][j],a[i][j]);
			ad(id[i][j],id[i][(j-1+n*2)%(n*2)],a[i][j]);
			ad(id[i][j],id[i][(j+1+n*2)%(n*2)],a[i][j]);
		}
	for (int i=0;i<n;i++)
		for (int j=n;j<n*2;j++)
		{
			ad(id[i][j],id[(i-1+n*2)%(n*2)][j],a[i][j]);
			ad(id[i][j],id[(i+1+n*2)%(n*2)][j],a[i][j]);
			ad(id[i][j],id[i][(j-1+n*2)%(n*2)],a[i][j]);
			ad(id[i][j],id[i][(j+1+n*2)%(n*2)],a[i][j]);
		}
	priority_queue<pa>q;
	for (int i=1;i<=tot;i++) dis[i]=inf;
	for (int i=n;i<n*2;i++)
		for (int j=n;j<n*2;j++)
			dis[id[i][j]]=0,q.push(mp(0,id[i][j]));
	while (!q.empty())
	{
		int u=q.top().se;
		int w=-q.top().fi;
		q.pop();
		if (w!=dis[u]) continue;
		for (auto [v,w]:G[u])
		{
			if (dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push(mp(-dis[v],v));
			}
		}
	}
	int ans=min({a[0][n],a[n-1][n],a[0][2*n-1],a[n-1][2*n-1],a[n][0],a[2*n-1][0],a[n*2-1][n-1],a[n][n-1]});
	for (int i=n;i<n*2;i++)
		for (int j=n;j<n*2;j++) ans+=a[i][j];
	cout<<ans<<endl;
	for (int i=1;i<=tot;i++) G[i].clear();
	
	
		
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
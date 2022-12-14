// Lynkcat.
// Problem: D. Arpas overnight party and Mehrdads silent entering
// Contest: Codeforces - 10.9
// URL: https://codeforces.com/gym/403061/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
int n;
poly G[N];
pa E[N];
int vis[N];
void dfs(int k,int c)
{
	vis[k]=c;
	for (auto u:G[k])
	{
		if (!vis[u]) dfs(u,3-c);
	}
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
		E[i]=mp(x,y);
	}
	for (int i=1;i<=2*n;i+=2)
		G[i].push_back(i+1),G[i+1].push_back(i);
	for (int i=1;i<=2*n;i++)
		if (!vis[i])
		{
			dfs(i,1);
		}
	for (int i=1;i<=n;i++)
		cout<<vis[E[i].fi]<<" "<<vis[E[i].se]<<'\n';
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
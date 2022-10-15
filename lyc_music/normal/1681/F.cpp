// Lynkcat.
// Problem: F. Unique Occurrences
// Contest: Codeforces - Educational Codeforces Round 129 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1681/problem/F
// Memory Limit: 1024 MB
// Time Limit: 6000 ms

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
#define N 500005
using namespace std;
int Siz[N];
map<int,int>siz[N];
int dep[N];
int lst[N];
int col[N];
poly P[N];
vector<pa>G[N];
int n;
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	if (k!=1)
	{
		lst[k]=P[col[k]].back();
		P[col[k]].push_back(k);
	} else
	{
		for (int i=1;i<=n;i++) P[i].push_back(k);
	}
	Siz[k]=1;
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa) continue;
		col[u]=w;
		dfs(u,k);
		Siz[k]+=Siz[u];
	}
	if (k!=1)
	{
		siz[k][col[k]]+=Siz[k];
		siz[lst[k]][col[k]]-=Siz[k];
		P[col[k]].pop_back();
	} else
		for (int i=1;i<=n;i++)
			siz[k][i]+=Siz[k];
}
void BellaKira()
{
	int ans=0;
	cin>>n;
	for (int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		G[x].push_back(mp(y,w));
		G[y].push_back(mp(x,w));
	}
	dfs(1,0);
	for (int i=2;i<=n;i++)
	{
		ans+=siz[i][col[i]]*siz[lst[i]][col[i]];
		// cout<<i<<" "<<siz[i][col[i]]<<" "<<siz[lst[i]][col[i]]<<endl;
	}
	cout<<ans<<endl;
		
		
}
signed main()
{
    IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
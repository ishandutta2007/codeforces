// Lynkcat.
// Problem: G1. Passable Paths (easy version)
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/G1
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
int n,dfn[N],DFN,rdfn[N];
poly G[N];
int q;
int siz[N],ffa[N],son[N],Tp[N],dep[N];;
int calc(int x,int y)
{
	return (dfn[x]<=dfn[y]&&dfn[y]<=rdfn[x]);
}
void dfs(int k,int fa)
{
	dfn[k]=++DFN;
	dep[k]=dep[fa]+1;
	siz[k]=1;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		siz[k]+=siz[u];
		if (siz[u]>siz[son[k]]) son[k]=u;
	}
	ffa[k]=fa;
	rdfn[k]=DFN;
}
void dfs1(int k,int tp)
{
	Tp[k]=tp;
	if (son[k]) dfs1(son[k],tp);
	for (auto u:G[k])
	{
		if (u==ffa[k]||u==son[k]) continue;
		dfs1(u,u);
	}
}
int lca(int x,int y)
{
	while (Tp[x]!=Tp[y])
	{
		if (dep[Tp[x]]<dep[Tp[y]]) swap(x,y);
		x=ffa[Tp[x]];
	}
	if (dep[x]<dep[y]) return x;
	return y;
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}	
	dfs(1,0);
	dfs1(1,1);
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		int x;
		cin>>x;
		poly g;
		for (int j=1;j<=x;j++) 
		{
			int y;
			cin>>y;
			g.push_back(y);
		}
		bool ans=0;
		sort(g.begin(),g.end(),[&](int x,int y){return dfn[x]<dfn[y];});
		int cnt=0,lim=0;
		for (int j=1;j<g.size();j++)
		{
			if (calc(g[j-1],g[j])) cnt++; else
			{
				lim=j;
				break;
			}
		}
		if (lim==0) ans=1;
		else
		{
			int cnt1=lim;
			for (int j=lim+1;j<g.size();j++)
			{
				if (calc(g[j-1],g[j])) cnt1=j;
				else break;
			}
			if (cnt1+1==g.size())
			{
				if (calc(g[0],g[lim]))
				{
					if (lca(g[1],g[lim])==g[0]) 
						ans=1;
				} else ans=1;
			}
		}
		if (ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
		
}
signed main()
{IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
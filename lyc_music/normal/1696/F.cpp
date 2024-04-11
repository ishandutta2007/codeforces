// Lynkcat.
// Problem: F. Tree Recovery
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/F
// Memory Limit: 512 MB
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
#define inf 1e18
#define mod 998244353
#define int ll
#define N  105
using namespace std;
int val[N];
int dis[N][N];
int ans;
poly G[N];
int n;
int a[N][N][N];
int del[N];
int ffa[N];
int gf(int x)
{
	if (x==ffa[x]) return x;
	return ffa[x]=gf(ffa[x]);
}
void merge(int x,int y)
{
	x=gf(x),y=gf(y);
	ffa[x]=y;
}
void solve(poly g)
{
	if (g.size()<=1) return;
	if (g.size()==2)
	{
		G[g[0]].push_back(g[1]);
		G[g[1]].push_back(g[0]);
		return;
	}
	poly all;
	int mx=-1,lft=0;
	for (auto u:g)
	{
		for (auto v:g) ffa[v]=v;
		for (auto v:g)
		{
			for (auto o:g)
			{
				if (v>=o) continue;
				if (a[v][o][u]) merge(v,o);
			}
		}
		poly gg;
		for (auto v:g)
			if (gf(v)==v) gg.push_back(v);
		if ((int)gg.size()>(int)mx)
		{
			mx=gg.size();
			lft=u;
		}
		val[u]=gg.size();
	}
	// cout<<"?"<<mx<<" "<<lft<<endl;
	int oo=-1;
	for (auto u:g)
	{
		if (val[u]==mx) continue;
		bool bl=1;
		for (int i:g)
			for (int j:g)
				if (i!=u&&i!=lft&&j!=u&&j!=lft&&i<j)
				{
					if (a[i][j][u]!=a[i][j][lft]) 
					{
						bl=0;
					}
				}
		if (bl) 
		{
			oo=u;
			break;
		}
	}
	if (oo==-1)
	{
		ans=0;
		return;
	}
	G[lft].push_back(oo);
	G[oo].push_back(lft);
	poly nxtg;
	for (auto u:g)
		if (u!=lft) nxtg.push_back(u);
	solve(nxtg);
}
void BellaKira()
{
	cin>>n;
	for (int i=0;i<n;i++) del[i]=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) dis[i][j]=inf;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
		{
			string st;
			cin>>st;
			for (int k=0;k<n;k++) a[i][j][k]=st[k]-'0';
		}
	ans=1;
	poly g;
	for (int i=0;i<n;i++)
		g.push_back(i);
	solve(g);
	for (int i=0;i<n;i++)
	{
		dis[i][i]=0;
		for (auto u:G[i])
			dis[i][u]=1;
	}
	for (int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (dis[i][j]==inf) ans=0;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			for (int k=0;k<n;k++)	
				if ((dis[i][k]==dis[j][k])!=(a[i][j][k])) 
					ans=0;
	if (ans==0) cout<<"NO"<<endl;
	else 
	{
		cout<<"YES"<<endl;
		for (int i=0;i<n;i++)
			for (auto u:G[i])
				if (u<i) cout<<u+1<<" "<<i+1<<endl;
	}
	for (int i=0;i<n;i++) G[i].clear();
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
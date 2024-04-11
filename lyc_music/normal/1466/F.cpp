// Lynkcat.
// Problem: F. Euclid's nightmare
// URL: https://codeforces.com/contest/1466/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define mod 1000000007
#define int ll
#define N 500005
using namespace std;
int n,m,fa[N];
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
int merge(int x,int y)
{
	x=gf(x),y=gf(y);
	if (x==y) return 0;
	fa[x]=y;
	return 1;
}
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void BellaKira()
{
	poly G;
	cin>>n>>m;
	for (int i=0;i<=m;i++) fa[i]=i;
	for (int i=1;i<=n;i++)
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
		if (g.size()==1) g.push_back(0);
		if (merge(g[0],g[1])) 
		{
			G.push_back(i);
		}
	}
	cout<<quickPower(2,G.size())<<" "<<G.size()<<endl;
	for (auto u:G) cout<<u<<" ";
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
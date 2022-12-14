// Lynkcat.
// Problem: G. Orray
// Contest: Codeforces - Codeforces Round #827 (Div. 4)
// URL: https://codeforces.com/contest/1742/problem/G
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
#define inf 1e9
#define mod 998244353
#define int ll
// #define N 
using namespace std;
int n;
int ans[200005];
void BellaKira()
{
	cin>>n;
	vector<pa>g;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		g.push_back(mp(x,x));
	}
	int x=0;
	int bl=0;
	for (int i=1;i<=n;i++)
	{
		if (bl)
		{
			ans[i]=g.back().se;
			g.pop_back();
			continue;
		}
		for (auto &u:g)
			u.fi&=((1ll<<30)-1)^x;
		sort(g.begin(),g.end());
		if (g[0].fi==g.back().fi)
		{
			bl=1;
		}
		ans[i]=g.back().se;
		x|=ans[i];
		g.pop_back();
	}
	for (int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<'\n';
		
		
			
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
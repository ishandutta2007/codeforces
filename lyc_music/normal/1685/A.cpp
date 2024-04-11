// Lynkcat.
// Problem: A. Circular Local MiniMax
// URL: https://codeforces.com/contest/1685/problem/A
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
#define N 200005
using namespace std;
int n,a[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n%2==1) return cout<<"NO"<<endl,void();
	sort(a+1,a+n+1);
	poly g;
	for (int i=1;i<=n/2;i++)
	{
		g.push_back(a[i]);
	}
	int l=n/2+1;
	poly g1;
	for (int i=0;i<g.size();i++)
	{
		int now=max(g[i],g[(i+1)%g.size()]);
		if (a[l]<=now) return cout<<"NO"<<endl,void();
		g1.push_back(g[i]);
		g1.push_back(a[l]);
		l++;
	}	
	cout<<"YES"<<endl;
	for (auto u:g1) cout<<u<<" ";
	cout<<endl;
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
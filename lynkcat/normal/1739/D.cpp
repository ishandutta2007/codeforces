// Lynkcat.
// Problem: D. Reset K Edges
// Contest: Codeforces - Educational Codeforces Round 136 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1739/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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
#define N  200005
using namespace std;
poly G[N];
int lim,sum;
int n,m;
int f[N];
void dfs(int k,int fa)
{
	f[k]=0;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		if (f[u]+1==lim&&k!=1)
		{
			sum++;
			// cout<<"?"<<lim<<" "<<u<<" "<<k<<" "<<sum<<endl;
		} else f[k]=max(f[k],f[u]+1);
	}
}
int calc(int mid)
{
	lim=mid;
	sum=0;
	dfs(1,0);
	return sum;
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		G[x].push_back(i);
	}
	int ans=n;
	int l=1,r=n;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (calc(mid)<=m)
		{
			ans=mid;
			r=mid-1;
		} else l=mid+1;
	}
	cout<<ans<<'\n';
	for (int i=1;i<=n;i++) poly().swap(G[i]);
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
// Lynkcat.
// Problem: D. Chip Move
// Contest: Codeforces - Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/D
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
int n,m,dp[N],ans[N],g[N],sum[N];
void BellaKira()
{
	cin>>n>>m;
	dp[0]=1;
	for (int x=m;(m+x)*(x-m+1)/2<=n;x++)
	{
		for (int i=1;i<=n;i++)
			g[i]=0;
		for (int i=0;i<x;i++) sum[i]=0;
		for (int i=0;i<=n;i++)
		{
			g[i]=sum[i%x];
			sum[i%x]=(sum[i%x]+dp[i]>=mod)?sum[i%x]+dp[i]-mod:sum[i%x]+dp[i];
		}
		for (int i=0;i<=n;i++) 
		{dp[i]=g[i];ans[i]=(ans[i]+dp[i]>=mod)?ans[i]+dp[i]-mod:ans[i]+dp[i];}
	}
	for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
	
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
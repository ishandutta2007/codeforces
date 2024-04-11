// Lynkcat.
// Problem: D. Almost Triple Deletions
// Contest: Codeforces - Codeforces Round #804 (Div. 2)
// URL: https://codeforces.com/contest/1699/problem/D
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
// #define int ll
#define N 5005
using namespace std;
int n,ans,dp[N],g[N];
int a[N],lst[N];
int cnt[N];
int f[N][N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) g[i]=0;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		lst[i]=g[a[i]];
		g[a[i]]=i;
	}
	for (int i=1;i<=n;i++)
	{
		int mx=0,sm=0;
		for (int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			mx=max(mx,cnt[a[j]]);
			sm++;
			if (2*mx<=sm)
				f[i][j]=sm%2;
			else f[i][j]=2*mx-sm;
		}
		for (int j=i;j<=n;j++) cnt[a[j]]--;
	}
	int ans=0;
	dp[0]=0;
	for (int i=1;i<=n;i++)
	{
		dp[i]=-inf;
		for (int j=lst[i];j>=0;j=lst[j])
		{
			dp[i]=max(dp[i],dp[j]+1-f[j+1][i-1]);
			ans=max(ans,dp[i]-f[i+1][n]);
			// cout<<j<<"->"<<i<<endl;
			if (j==0) break;
		}
	}
	cout<<ans<<endl;
	
		
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
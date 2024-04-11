// Lynkcat.
// Problem: E. Moving Chips
// URL: https://codeforces.com/contest/1680/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// -----------------------------------------------

//~~
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
int n;
int fa[N];
int b[2];
int dp[N][2];
int ans;
int cnt;
void BellaKira()
{
	cin>>n;
	string st[2];
	cin>>st[0];
	cin>>st[1];
	st[0]=' '+st[0];
	st[1]=' '+st[1];
	b[0]=0;b[1]=0;
	ans=0;
	cnt=0;
	int l=n,r=0;
	for (int i=0;i<2;i++)
		for (int j=1;j<=n;j++)
			if (st[i][j]=='*')
				r=max(r,j),l=min(l,j),b[i]++;
	dp[l-1][0]=0;
	dp[l-1][1]=0;
	for (int i=l;i<=r;i++)
	{
		dp[i][1]=min(dp[i-1][0],dp[i-1][1])+2;
		dp[i][0]=min(dp[i-1][0],dp[i-1][1])+2;
		if (st[1][i]!='*')
		{
			dp[i][0]=min(dp[i-1][0]+1,dp[i][0]);
		}
		if (st[0][i]!='*')
		{
			dp[i][1]=min(dp[i-1][1]+1,dp[i][1]);
		}
		// cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	cout<<min(dp[r][0],dp[r][1])-1<<endl;
	// cout<<ans<<endl;
	
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
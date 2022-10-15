// Lynkcat.
// Problem: D. Keep the Average High
// Contest: Codeforces - Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf -1e18
#define mod 998244353
#define int ll
#define N 50005
using namespace std;
int dp[N][4];
int n,a[N],m;
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for (int i=1;i<=n;i++) a[i]-=m;
	dp[0][0]=0;
	dp[0][1]=inf,dp[0][2]=inf;dp[0][2]=inf;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=3;j++)
			dp[i][j]=inf;
		for (int j=0;j<=3;j++)
		{
			dp[i][0]=max(dp[i-1][j],dp[i][0]);
		}
		dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
		if (i>1&&a[i-1]+a[i]>=0)
		{
			dp[i][2]=max(dp[i][2],dp[i-1][1]+1);
		}
		if (i>2&&a[i-1]+a[i]>=0&&a[i-1]+a[i]+a[i-2]>=0)
		{
			dp[i][3]=max(dp[i][3],dp[i-1][2]+1);
			dp[i][3]=max(dp[i][3],dp[i-1][3]+1);
		}
		// cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<endl;
	}
	cout<<max({dp[n][0],dp[n][1],dp[n][2],dp[n][3]})<<endl;
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
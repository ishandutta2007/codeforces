// Lynkcat.
// Problem: CF429B Working out
// URL: https://www.luogu.com.cn/problem/CF429B?contestId=73710
// Memory Limit: 250 MB
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
#define mod 998244353
#define int ll
//#define N
using namespace std;
int n,m;
void gt(vector<poly> &dp,vector<poly> &a)
{
	dp[1][1]=a[1][1];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		if (!(i==1&&j==1))
		{
			dp[i][j]=-inf;
			if (i>1) dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][j]);
			if (j>1) dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i][j]);
		}
}
void BellaKira()
{
	cin>>n>>m;
	vector<poly>a(n+1,poly(m+1,0));
	vector<poly>dp,dp1,dp2,dp3;
	dp=a,dp1=a,dp2=a,dp3=a;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>a[i][j];
	gt(dp,a);
	
	for (int i=1;i<n-i+1;i++)
		for (int j=1;j<=m;j++)
			swap(a[i][j],a[n-i+1][j]);
	gt(dp1,a);
	for (int i=1;i<n-i+1;i++)
		for (int j=1;j<=m;j++)
			swap(dp1[i][j],dp1[n-i+1][j]);
			
			
	for (int i=1;i<=n;i++)
		for (int j=1;j<m-j+1;j++)
			swap(a[i][j],a[i][m-j+1]);
	gt(dp2,a);
	for (int i=1;i<n-i+1;i++)
		for (int j=1;j<=m;j++)
			swap(dp2[i][j],dp2[n-i+1][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m-j+1;j++)
			swap(dp2[i][j],dp2[i][m-j+1]);
			
			
	for (int i=1;i<n-i+1;i++)
		for (int j=1;j<=m;j++)
			swap(a[i][j],a[n-i+1][j]);
	gt(dp3,a);
	for (int i=1;i<=n;i++)
		for (int j=1;j<m-j+1;j++)
			swap(dp3[i][j],dp3[i][m-j+1]);
			
	int ans=-inf;
	for (int i=2;i<n;i++)
		for (int j=2;j<m;j++)
		{
			ans=max(ans,dp[i][j-1]+dp1[i+1][j]+dp2[i][j+1]+dp3[i-1][j]);
			ans=max(ans,dp1[i][j-1]+dp[i-1][j]+dp2[i+1][j]+dp3[i][j+1]);
		}
	// cout<<dp[1][1]<<endl;
	cout<<ans<<endl;
	
	
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
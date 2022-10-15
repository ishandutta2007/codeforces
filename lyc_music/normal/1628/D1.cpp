// Lynkcat.
// Problem: D1. Game on Sum (Easy Version)
// URL: https://codeforces.com/contest/1628/problem/D1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
#define mod 1000000007
#define int ll
#define N 2005
using namespace std;
int dp[N][N];
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
	int inv2=quickPower(2,mod-2);
	dp[0][0]=1;
	for (int i=1;i<=2000;i++)
	{
		for (int j=1;j<=i;j++)
		{
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])*inv2%mod;
		}
		dp[i][i]=i;
	}
}
signed main()
{
	int T=1;
	BellaKira();
	cin>>T;
	while (T--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		cout<<dp[n][m]*k%mod<<endl;
	}
}
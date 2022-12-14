// Problem: E. Ela Goes Hiking
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/E
// Memory Limit: 256 MB
// Time Limit: 2500 ms

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
#define N  1000005
using namespace std;
int n,s[N],dp[N],suf[N];
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void BellaKira()
{
	cin>>n;
	s[0]=1;
	for (int i=1;i<=n;i++)
	{
		dp[i]=quickPower(2,i/2);
		s[i]=(s[i-1]+dp[i])%mod;
	}
	suf[n]=1;
	s[n]=1;
	s[n+1]=0;
	for (int i=n-1;i>=1;i--)
	{
		int x=i*2;
		x=min(x,n+1);
		suf[i]=0;
		if (x>i)
		{
			suf[i]=(s[i+1]-s[x]+mod)%mod;
		}
		s[i]=(s[i+1]+suf[i])%mod;
	}
	int pw=1,pww=1;
	for (int i=1;i<n;i++) pw=pw*500000004%mod,pww=pww*2%mod;
	// cout<<562500004*pww%mod<<'\n';
	for (int i=1;i<=n;i++)
		cout<<(dp[i]*suf[i]%mod*pw%mod)<<'\n';
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
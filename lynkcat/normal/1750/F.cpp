// Problem: F. Majority
// Contest: Codeforces - CodeTON Round 3 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1750/problem/F
// Memory Limit: 1024 MB
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
// #define mod 998244353
#define int ll
#define N 5005
using namespace std;
int n,m,dp[N],s[N],f[N];
int mod;
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
	cin>>n>>m;
	mod=m;
  	dp[1]=1;
  	for (int i=2;i<=n;i++)
  	{
  		s[i]=(s[i-1]+s[i])%mod;
  		if (i&1) s[i]=(s[i]+dp[(i-1)/2])%mod;
  		for (int j=1;3*j+1<=i;j++)
  			s[i]=(s[i-1-3*j]*dp[j]%mod+s[i])%mod;
  		for (int j=1;2*j<=i;j++)
  			f[i]=(s[i-2*j]*dp[j]%mod+f[i])%mod;
  		dp[i]=(quickPower(2,i-2)-f[i]+mod)%mod;
  	}
  	cout<<dp[n]<<'\n';
			
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
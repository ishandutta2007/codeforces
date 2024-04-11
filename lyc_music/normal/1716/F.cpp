// Lynkcat.
// Problem: F. Bags with Balls
// Contest: Codeforces - Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms

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
#define N 2005
using namespace std;
int n,m,k,pw[N],pwm[N],S[N][N];
int fac[N],C[N];
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
	cin>>n>>m>>k;
	pw[0]=1;
	for (int i=1;i<=k;i++)
	{
		pw[i]=pw[i-1]*(((m+1)/2)%mod)%mod;
	}
	int nw=0;
	C[0]=1;
	for (int i=1;i<=min(k,n);i++)
	{
		C[i]=C[i-1]*(n-i+1)%mod;
	}
		
	int x=quickPower(m,n)%mod;
	int inv=quickPower(m,mod-2);
	int ans=0;
	for (int i=0;i<=min(k,n);i++)
	{
		ans=(ans+S[k][i]*pw[i]%mod*x%mod*C[i]%mod)%mod;
		// cout<<i<<","<<S[k][i]<<" "<<pw[i]<<" "<<x<<" "<<C[i]<<endl;
		x=x*inv%mod;
	}
	cout<<ans<<endl;
		
		
}
signed main()
{
	fac[0]=1;
	for (int i=1;i<=2000;i++) fac[i]=fac[i-1]*i%mod;
	for (int i=1;i<=2000;i++) fac[i]=quickPower(fac[i],mod-2);
	S[0][0]=1;
	for (int i=1;i<=2000;i++)
	{
		for (int j=1;j<=i;j++)
		{
			S[i][j]=(S[i-1][j-1]+j*S[i-1][j]%mod)%mod;
		}
	}
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
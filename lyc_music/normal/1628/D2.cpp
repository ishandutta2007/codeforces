// Lynkcat.
// Problem: D2. Game on Sum (Hard Version)
// URL: https://codeforces.com/contest/1628/problem/D2
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
#define N 2000005
using namespace std;
int fac[N],inv[N];
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
int C(int x,int y)
{
	if (x<y||y<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void BellaKira()
{
	fac[0]=1;
	for (int i=1;i<=2000000;i++) fac[i]=fac[i-1]*i%mod;
	inv[2000000]=quickPower(fac[2000000],mod-2);
	for (int i=2000000;i>=1;i--)
		inv[i-1]=inv[i]*i%mod;
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
		if (n==m) cout<<n*k%mod<<endl;
		else
		{
			int ans=0;
			for (int i=m;i>=1;i--)
			{
				ans=(ans+k*i%mod*quickPower(quickPower(2,mod-2),n-i)%mod*C(n-i-1,m-i)%mod)%mod;
			}		
			cout<<ans<<endl;
		}
	}
}
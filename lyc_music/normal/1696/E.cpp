// Lynkcat.
// Problem: E. Placing Jinas
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/E
// Memory Limit: 512 MB
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
#define mod 1000000007
#define int ll
#define N 1000005
using namespace std;
int n,a[N],ans;
int fac[N],inv[N];
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
inline int C(int x,int y)
{
	if (x<y||y<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n+1;i++)
		cin>>a[i];
	for (int i=1;i<=n+1;i++)
	{
		int x=i-1;
		ans=(ans+C(x+a[i],i))%mod;
	}
	cout<<ans<<endl;
}
signed main()
{
	fac[0]=1;
	for (int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	inv[N-1]=quickPower(fac[N-1],mod-2);
	for (int i=N-1;i>=1;i--)
		inv[i-1]=inv[i]*i%mod;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
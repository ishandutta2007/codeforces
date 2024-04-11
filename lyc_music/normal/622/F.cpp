// Lynkcat.
// Problem: F. The Sum of the k-th Powers
// URL: https://codeforces.com/contest/622/problem/F
// Memory Limit: 256 MB
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
#define mod 1000000007
#define int ll
#define N 2000005
using namespace std;
int n,m,f[N],pre[N],suf[N],fac[N],inv[N];
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
int get(int l,int r)
{
	if (l>r) return 1;
	if (r<0)
	{
		if ((-l)%2==1)
			return (mod-inv[-l])%mod;
		return inv[-l];
	}
	return inv[r];
}
void BellaKira()
{
	cin>>n>>m;
	f[1]=1;
	for (int i=2;i<=m+2;i++) f[i]=(f[i-1]+quickPower(i,m))%mod;
	int ans=0;
	m+=2;
	pre[0]=1;
	for (int i=1;i<=m;i++) pre[i]=pre[i-1]*(n-i+mod)%mod;
	suf[m+1]=1;
	for (int i=m;i>=1;i--) suf[i]=suf[i+1]*(n-i+mod)%mod;
	for (int i=1;i<=m;i++)
	{
		int nw=pre[i-1]*suf[i+1]%mod*get(i-m,-1)%mod*get(1,i-1)%mod;
		nw=nw*f[i]%mod;
		ans=(ans+nw)%mod;
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
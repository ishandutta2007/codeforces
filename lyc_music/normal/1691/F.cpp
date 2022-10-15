// Lynkcat.
// Problem: F. K-Set Tree
// URL: https://codeforces.com/contest/1691/problem/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
#define N 200005
using namespace std;
int siz[N];
int fac[N];
int inv[N];
int n,m;
poly G[N];
int ans;
int C(int x,int y)
{
	if (x<y||y<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
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
int calc(int x)
{
	return C(x,m);
}
void dfs(int k,int fa)
{
	siz[k]=1;
	int now=0;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		siz[k]+=siz[u];
		now=(now-calc(siz[u])+mod)%mod;
	}
	now=(now+calc(siz[k]))%mod;
	ans=(ans+now*(n-siz[k])%mod*siz[k]%mod)%mod;
	
	now=0;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		now=(now-calc(siz[u])+mod)%mod;
	}
	now=(now-calc(n-siz[k])+mod)%mod;
	ans=(ans+(now+calc(n))*n%mod)%mod;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		now=(now+calc(siz[u]))%mod;
		now=(now+calc(n-siz[u]))%mod;
		ans=(ans+now*(n-siz[u])%mod*siz[u]%mod)%mod;
		now=(now-calc(siz[u])+mod)%mod;
		now=(now-calc(n-siz[u])+mod)%mod;
	}
	// cout<<"!"<<k<<" "<<ans<<endl;
}
void BellaKira()
{
	cin>>n>>m;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=quickPower(fac[n],mod-2);
	for (int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%mod;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	cout<<ans<<endl;
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
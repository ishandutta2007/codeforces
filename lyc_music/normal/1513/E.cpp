#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 1000000007
#define int ll
#define N 300005
using namespace std;
int n,a[N],fac[N],inv[N];
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
	map<int,int>Mp;
	int ans=1;
	int sm=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		Mp[a[i]]++;
		sm+=a[i];
	}
	if (sm%n!=0)
	{
		return cout<<0<<endl,void();
	}
	sm/=n;
	int x=0;
	int y=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]<sm) x++;
		if (a[i]>sm) y++;
	}
	if (x==0) 
	{
		return cout<<1<<endl,void();
	}
	if (x==1||y==1)
	{
		for (auto [u,v]:Mp)
		{
			ans=ans*inv[v]%mod;
		}
		ans=ans*fac[n]%mod;
		cout<<ans<<endl;
	} else
	{
		for (auto [u,v]:Mp)
		{
			ans=ans*inv[v]%mod;
		}
		cout<<2*fac[x]%mod*fac[y]%mod*inv[x+y]%mod*fac[n]%mod*ans%mod<<endl;
	}
}
signed main()
{
	fac[0]=1;
	for (int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	inv[N-1]=quickPower(fac[N-1],mod-2);
	for (int i=N-1;i>=1;i--) inv[i-1]=inv[i]*i%mod;
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
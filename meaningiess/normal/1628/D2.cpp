#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll f[2020][2020],fac[1000010],ifac[1000010];
ll C(int x,int y){return fac[x]*ifac[y]%mod*ifac[x-y]%mod;}
ll qpow(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) (res*=x)%=mod;(x*=x)%=mod;y>>=1;
	}
	return res;
}
int main()
{
	int T,i;cin>>T;fac[0]=ifac[0]=1;
	for (i=1;i<=1000000;i++) fac[i]=fac[i-1]*i%mod;
	ifac[1000000]=qpow(fac[1000000],mod-2);
	for (i=999999;i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	while (T--)
	{
		int n,m,j,k;ll ans=0;cin>>n>>m>>k;
		if (n==m) {cout<<1ll*k*n%mod<<endl;continue;}
		for (i=1;i<=m;i++) (ans+=C(n-i-1,m-i)*qpow(500000004,n-i)%mod*i)%=mod;
		cout<<ans*k%mod<<endl;
	}
}
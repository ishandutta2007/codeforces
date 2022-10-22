#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int a[200010];
ll fac[400010],ifc[400010];
ll qpow(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) (res*=x)%=mod;(x*=x)%=mod;y>>=1;
	}
	return res;
}
ll C(ll x,ll y)
{
	return fac[x]*ifc[y]%mod*ifc[x-y]%mod;
}
int main()
{
	int n,i,t;cin>>n;ll ans=0;fac[0]=ifc[0]=1;
	for (i=1;i<=400000;i++) fac[i]=(fac[i-1]*i)%mod,ifc[i]=qpow(fac[i],mod-2);
	for (i=0;i<=n;i++)
	{
		cin>>t;
		if (t)(ans+=C(i+t,t-1))%=mod;
		//cout<<ans<<endl;
	}
	cout<<((ans+mod))%mod;
}
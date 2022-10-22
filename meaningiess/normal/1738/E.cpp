#include<bits/stdc++.h>
#define ll long long
#define fi first
#define sc second
#define mod 998244353
using namespace std;
map<ll,int> prl,prr,sfl,sfr,us;
ll a[100010],pw2[100010],fac[100010],ifac[100010];
ll qpow(ll x,ll y)
{
	ll res=1;
	for (;y;y>>=1,(x*=x)%=mod) if (y&1) (res*=x)%=mod;
	return res;
}
ll C(ll x,ll y)
{
	return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int main()
{
	int T;cin>>T;pw2[0]=1;fac[0]=ifac[0]=1;
	for (int i=1;i<=100000;i++) pw2[i]=pw2[i-1]*2%mod,fac[i]=fac[i-1]*i%mod;
	ifac[100000]=qpow(fac[100000],mod-2);
	for (int i=99999;i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	while (T--)
	{
		int n,i;ll s=0;cin>>n;prl.clear();prr.clear();sfl.clear();sfr.clear();us.clear();
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<n;i++)
		{
			s+=a[i];
			if (!prl[s]) prl[s]=i;prr[s]=i;
			us[s]=1;
		}
		s=0;
		for (i=n;i>1;i--)
		{
			s+=a[i];
			if (!sfr[s]) sfr[s]=i-1;sfl[s]=i-1;
			us[s]=1;
		}
		int lstl=0,lstr=n+1;ll ans=1;
		for (auto ggg:us)
		{
			ll x=ggg.fi;
			int pl=max(lstl+1,prl[x]),pr=max(lstl,prr[x]);
			int sl=sfl[x]?sfl[x]:lstr,sr=sfr[x]?sfr[x]:lstr-1;
			if (pl>sr) break;
			if (pr<sl)
			{
				ll tp=0,p=max(pr-pl+1,sr-sl+1),q=min(pr-pl+1,sr-sl+1);
				for (int j=0;j<=q;j++) tp+=C(p,j)*C(q,j)%mod;
				tp%=mod;
				ans*=tp;
				ans%=mod;
			}
			else
			{
				ans*=pw2[sr-pl+1];
				ans%=mod;
			}
			lstl=pr;lstr=sl;
		}
		cout<<ans<<endl;
	}
}
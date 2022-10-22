#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
#define N 1333333
using namespace std;
ll a[N],b[N],c[N],fac[N],ifac[N];int lg[N],rev[N];
ll qpow(ll x,ll y)
{
	ll res=1;if (y==-1) y=mod-2;
	while (y)
	{
		if (y&1) (res*=x)%=mod;(x*=x)%=mod;y>>=1;
	}
	return res;
}
void ntt(ll *a,int n,int f)
{
	int bit=lg[n-1]+1,i,j,o;n=(1<<bit);
	for (i=0;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	for (i=0;i<n;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (o=1;o<n;o*=2)
	{
		ll tp=qpow(qpow(3,f),(mod-1)/(o*2));
		for (i=0;i<n;i+=o*2)
		{
			ll r=1;
			for (j=0;j<o;j++,(r*=tp)%=mod)
			{
				ll x=a[i+j],y=r*a[i+j+o]%mod;
				a[i+j]=(x+y)%mod;a[i+j+o]=(x-y+mod)%mod;
			}
		}
	}
	if (f==-1) {ll p=qpow(n,f);for (i=0;i<n;i++) (a[i]*=p)%=mod;}
}

int main()
{
	int T,i;cin>>T;fac[0]=ifac[0]=1;
	for (i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	ifac[N-1]=qpow(fac[N-1],mod-2);
	for (i=N-2;i>=1;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	for (i=2;i<N;i++) lg[i]=lg[i>>1]+1;
	while (T--)
	{
		int n;cin>>n;
		int m=(1<<lg[n])*4;
		for (i=0;i<=m;i++) a[i]=b[i]=0;
		for (i=0;i<=n/2;i++) a[2*i]=qpow(qpow(2,i),mod-2)*ifac[i]%mod;
		for (i=0;i<=n;i++) b[i]=ifac[i];
		ntt(a,m,1);ntt(b,m,1);
		for (i=0;i<=m;i++) c[i]=a[i]*b[i]%mod;
		ntt(c,m,-1);
		for (i=0;i<=m;i++) c[i]=c[i]*fac[i]%mod;
		ll ans=0;
		for (i=0;i<=n/4;i++)
		{
			ans+=fac[n-2*i]*ifac[n-4*i]%mod*ifac[i]%mod*c[n-4*i]%mod;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
}
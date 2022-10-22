#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mod=998244353;
const int N=210000;
ll n,k;
ll f[N],g[N];
ll qpow(ll a,ll b)
{
	ll res=1;
	for(;b>0;b/=2,a=a*a%mod) if(b%2) res=res*a%mod;
	return res;
}
void init(int m)
{
	f[0]=1;
	for(int i=1;i<=n;i++) f[i]=f[i-1]*i%mod;
	for(int i=0;i<=n;i++) g[i]=qpow(f[i],mod-2);
	return;
}
ll C(int n,int m)
{
	if(n<m) return 0;
	return f[n]*g[m]%mod*g[n-m]%mod;
}
ll S(int n,int m)
{
	ll sum=0;
	for(int i=0;i<=m-1;i++)
	{
		sum+=qpow(mod-1,i)*C(m,i)%mod*qpow(m-i,n)%mod;
		sum%=mod;
	}
	return sum;
}
int main()
{
	scanf("%lld%lld",&n,&k);
	if(k==0)
	{
		ll sum=1;
		for(int i=n;i>=1;i--) sum=sum*i%mod;
		printf("%lld\n",sum);
		return 0;
	}
	if(k>=n) return printf("0\n"),0;
	int m=n-k;
	init(m);
	ll ans=S(n,m)*C(n,m)%mod*2%mod;
	printf("%lld\n",ans);
	return 0;
}
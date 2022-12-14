#include<iostream>
#include<cstdio>
using namespace std;
const long long mod=1e9+9ll;
long long n,a,b,k,t,f,p,ans;
char s[111111];
long long binpow(long long a,long long t)
{
	long long res=1ll,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return res;
}
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&k);
	scanf("%s",s);
	for (long long i=0;i<k;i++)
	{
		t=(n-i)/k;
		f=binpow(a,n-i)*binpow(b,i)%mod;
		p=binpow(binpow(a,k),mod-2ll)*binpow(b,k)%mod;
		if (p==1)
		{
			if (s[i]=='+') ans=(ans+f*(t+1))%mod;
			else ans=(ans-f*(t+1))%mod;
		}
		else
		{
			if (s[i]=='+') ans=(ans+(f*(binpow(p,t+1ll)-1ll)%mod)*binpow(p-1ll,mod-2ll))%mod;
			else ans=(ans-(f*(binpow(p,t+1ll)-1ll)%mod)*binpow(p-1ll,mod-2ll))%mod;
		}
	}
	if (ans<0) ans+=mod;
	printf("%I64d\n",ans);
	return 0;
}
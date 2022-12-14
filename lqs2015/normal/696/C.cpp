#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n;
bool f;
long long binpow(long long a,long long t)
{
	long long res=1,p=a%mod;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return res;
}
long long a[111111],ans1,ans2;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]%2==0)
		{
			f=1;
			break;
		}
	}
	if (f)
	{
		ans1=2;ans2=2;
		for (int i=1;i<=n;i++)
		{
			ans1=binpow(ans1,a[i]);
			ans2=binpow(ans2,a[i]);
		}
		ans1=(ans1*binpow(2ll,mod-2)%mod+1)*binpow(3ll,mod-2)%mod;
		ans2=ans2*binpow(2ll,mod-2)%mod;
		printf("%lld/%lld\n",ans1,ans2);
	}
	else
	{
		ans1=2;ans2=2;
		for (int i=1;i<=n;i++)
		{
			ans1=binpow(ans1,a[i]);
			ans2=binpow(ans2,a[i]);
		}
		ans1=(ans1*binpow(2ll,mod-2)%mod-1)*binpow(3ll,mod-2)%mod;
		ans1=(ans1+mod)%mod;
		ans2=ans2*binpow(2ll,mod-2)%mod;
		printf("%lld/%lld\n",ans1,ans2);
	}
	return 0;
}
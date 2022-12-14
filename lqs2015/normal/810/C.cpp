#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=1e9+7;
long long a[444444],n,ans,prev;
long long Binpow(int n)
{
	long long p=2,res=1;
	for (int i=n;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return (res-1)%mod;
}
int main()
{
	scanf("%I64d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
	{
		prev=((2*prev)%mod+(a[i]-a[i-1])*Binpow(i-1)%mod)%mod;
		ans=(ans+prev)%mod;
	}
	printf("%I64d\n",ans);
	return 0;
}
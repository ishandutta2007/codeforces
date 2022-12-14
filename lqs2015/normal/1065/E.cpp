#include<iostream>
#include<cstdio>
using namespace std;
const long long mod=998244353;
long long n,m,a,b[222222],ans;
long long binpow(long long a,long long t)
{
	long long res=1,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return res;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&a);
	for (long long i=1;i<=m;i++) scanf("%I64d",&b[i]);
	ans=binpow(a,n-2*b[m]);
	for (long long i=1;i<=m;i++)
	{
		ans=(ans*(((binpow(a,b[i]-b[i-1])*(binpow(a,b[i]-b[i-1])-1)%mod)*((mod+1)/2)%mod)+binpow(a,b[i]-b[i-1])))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
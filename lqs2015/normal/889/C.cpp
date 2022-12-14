#include<iostream>
#include<cstdio>
using namespace std;
const long long mod=1e9+7;
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
long long n,k,jc[1111111],injc[1111111],f[1111111],sum[1111111];
void Init()
{
	jc[0]=1;
	for (long long i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	injc[n]=binpow(jc[n],mod-2);
	for (long long i=n-1;i>=0;i--) injc[i]=injc[i+1]*(i+1)%mod;
}
int main()
{
	cin>>n>>k;
	Init();
	for (long long i=k+1;i<=n;i++)
	{
		f[i]=((i-k-1)*jc[i-2]%mod+jc[i-2]*(sum[i-1]-sum[i-k-1])%mod)%mod;
		sum[i]=(sum[i-1]+f[i]*injc[i-1])%mod;
	}
	cout<<(jc[n-1]*sum[n]%mod+mod)%mod<<endl;
	return 0;
}
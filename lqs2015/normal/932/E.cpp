#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7,maxn=5000;
long long n,k,jc[11111],injc[11111],pw[11111],ans,s[5555][5555],c[5555];
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
void Init()
{
	jc[0]=injc[0]=1;
	for (long long i=1;i<=maxn;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		injc[i]=injc[i-1]*binpow(i,mod-2)%mod;
	}
	for (long long i=0;i<=maxn;i++)
	{
		pw[i]=binpow(i,n);
	}
	s[0][0]=1;
	for (int i=1;i<=maxn;i++)
	{
		for (int j=1;j<=i;j++)
		{
			s[i][j]=(s[i-1][j-1]+j*s[i-1][j])%mod;
		}
	}
	long long res=1;
	for (long long i=0;i<=n && i<=k;i++)
	{
		c[i]=res;
		res=res*(n-i)%mod;
	}
}
int main()
{
	cin>>n>>k;
	Init();
	for (long long i=0;i<=k && i<=n;i++)
	{
		ans=(ans+s[k][i]*c[i]%mod*binpow(2,n-i))%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
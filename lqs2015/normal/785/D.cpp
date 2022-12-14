#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long mod=1e9+7;
long long n,l,r,ans,jc[444444],injc[444444];
char s[222222];
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
	jc[0]=1;
	for (long long i=1;i<=400000;i++) jc[i]=jc[i-1]*i%mod;
	injc[400000]=binpow(jc[400000],mod-2);
	for (long long i=399999;i>=0;i--) injc[i]=injc[i+1]*(i+1)%mod;
}
long long C(long long n,long long k)
{
	if (n<0 || k<0 || k>n) return 0;
	return (jc[n]*injc[k]%mod)*injc[n-k]%mod;
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	Init();
	for (long long i=0;i<n;i++)
	{
		if (s[i]==')') r++;
	}
	for (long long i=0;i<n;i++)
	{
		if (s[i]==')') r--;
		else 
		{
			l++;
			ans=(ans+C(l+r-1,l))%mod;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
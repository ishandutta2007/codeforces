#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const long long maxn=1e6,mod=998244353;
long long n,m,jc[1111111],injc[1111111],ans;
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
	for (long long i=1;i<=maxn;i++) jc[i]=jc[i-1]*i%mod;
	injc[maxn]=binpow(jc[maxn],mod-2);
	for (long long i=maxn-1;i>=0;i--) injc[i]=injc[i+1]*(i+1)%mod;
}
long long P(long long n,long long k)
{
	if (n<k) return 0;
	return jc[n]*injc[k]%mod;
}
int main()
{
	scanf("%I64d",&n);
	Init();
	ans=jc[n];
	for (long long i=2;i<n;i++)
	{
		ans=(ans+((i-1)*P(n,i)%mod)*(n-i))%mod;
	}
	printf("%I64d\n",(ans+mod)%mod);
	return Accepted;
}
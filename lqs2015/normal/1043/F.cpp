#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const long long mod=998244353;
long long jc[666666],injc[666666],n,a[333333],cnt[333333],dp[333333];
bool exist[333333];
long long C(long long n,long long k)
{
	if (n<k) return 0;
	return (jc[n]*injc[k]%mod)*injc[n-k]%mod;
}
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
	for (long long i=1;i<=600000;i++) jc[i]=jc[i-1]*i%mod;
	injc[600000]=binpow(jc[600000],mod-2);
	for (long long i=599999;i>=0;i--) injc[i]=injc[i+1]*(i+1)%mod;
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		exist[a[i]]=1;
	}
	for (long long i=1;i<=300000;i++)
	{
		for (long long j=i;j<=300000;j+=i)
		{
			if (exist[j]) cnt[i]++;
		}
	}
	Init();
	for (long long i=1;i<=7;i++)
	{
		memset(dp,0,sizeof(dp));
		for (long long j=300000;j>=1;j--)
		{
			dp[j]=C(cnt[j],i);
			for (long long k=j+j;k<=300000;k+=j) dp[j]=(dp[j]-dp[k])%mod;
		}
		if (dp[1]) 
		{
			printf("%I64d\n",i);	
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
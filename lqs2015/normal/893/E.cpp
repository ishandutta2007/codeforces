#include<iostream>
using namespace std;
const long long mod=1e9+7;
long long dp[1111111][23],q,x,y,ans,p,jc[1111111],injc[1111111],pw[1111111],cs;
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
	jc[0]=injc[0]=1ll;
	for (long long i=1;i<=1000000;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		injc[i]=injc[i-1]*binpow(i,mod-2)%mod;
	}
}
long long C(long long n,long long k)
{
	return ((jc[n]*injc[k])%mod)*injc[n-k]%mod;
}
int main()
{
	pw[0]=1ll;
	for (long long i=1;i<=1000000;i++)
	pw[i]=pw[i-1]*2ll%mod;
	Init();
	dp[1][0]=1ll;
	for (long long i=1;i<=1000000;i++)
	{
		for (long long j=0;j<=19;j++)
		{
			if (!dp[i][j]) continue;
			for (long long k=i+i;k<=1000000;k+=i)
			{
				dp[k][j+1]=dp[k][j+1]+dp[i][j];
				if (dp[k][j+1]>mod) dp[k][j+1]-=mod;
			}
		}
	}
	cs=binpow(2ll,mod-2ll);
	scanf("%I64d",&q);
	while(q--)
	{
		scanf("%I64d%I64d",&x,&y);
		ans=0;
		for (long long i=0;i<=20;i++)
		{
			p=dp[x][i];
			if (!p) continue;
			ans=(ans+p*C(y,i))%mod;
		}
		ans=((ans*pw[y])%mod)*cs%mod;
		printf("%I64d\n",ans);
	}
	return 0;
}
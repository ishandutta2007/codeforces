#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
const LL MOD=1000000007LL;
LL n;
LL s,a[31],ans,inv[31];
LL qpow(LL p,LL n)
{
	LL w=p%MOD,con=1;
	while(n>0)
	{
		if(n&1) con=(con*w)%MOD;
		w=(w*w)%MOD;
		n>>=1;
	}
	return con;
}
LL C(LL n,LL k)
{
	LL con=1,o=1;
	for(LL i=1;i<=k;i++)
	{
		con=(con*(n%MOD))%MOD;n--;
		con=(con*inv[o])%MOD;o++;
	}
	return con;
}
int main()
{
	scanf("%I64d%I64d",&n,&s);
	for(LL i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++) inv[i]=qpow(i,MOD-2);
	for(LL i=0;i<(1<<n);i++)
	{
		LL t=s,w=1;
		for(LL j=0;j<n;j++)
			if(i&(1<<j)) t-=a[j+1]+1,w=-w;
		if(t>=0) ans=(ans+C(t+n-1,n-1)*w+MOD)%MOD;
	}
	printf("%I64d\n",ans);
	return 0;
}
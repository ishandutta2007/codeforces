#include <iostream>
using namespace std;
#define mod 1000000006
long long cnt[200005],pre[200005],suf[200005];
long long pow_log(int x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%(mod+1);
	if (y%2)
	ret=(ret*x)%(mod+1);
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	pre[0]=1;
	for (int i=1;i<200005;i++)
	pre[i]=((cnt[i]+1)*pre[i-1])%mod;
	suf[200004]=1;
	for (int i=200003;i>=0;i--)
	suf[i]=((cnt[i]+1)*suf[i+1])%mod;
	long long ans=1;
	for (int i=1;i<200004;i++)
	{
		if (cnt[i])
		{
			long long x=(pre[i-1]*suf[i+1])%mod;
			x*=(cnt[i]*(cnt[i]+1)/2)%mod;
			x%=mod;
			ans=(ans*pow_log(i,x))%(mod+1);
		}
	}
	printf("%I64d",ans);
}
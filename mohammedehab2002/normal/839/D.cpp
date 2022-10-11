#include <iostream>
using namespace std;
#define mod 1000000007
long long ci[1000005],cnt[1000005],ans[1000005];
long long pow_log(long long x,long long y)
{
	if (y==0)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
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
		ci[a]++;
	}
	for (int i=2;i<=1000000;i++)
	{
		for (int x=i;x<=1000000;x+=i)
		cnt[i]+=ci[x];
	}
	long long res=0;
	for (int i=1000000;i>1;i--)
	{
		ans[i]=(pow_log(2,cnt[i]-1)*cnt[i])%mod;
		for (int x=2*i;x<=1000000;x+=i)
		ans[i]=(ans[i]-ans[x]+mod)%mod;
		res=(res+ans[i]*i)%mod;
	}
	printf("%I64d",res);
}
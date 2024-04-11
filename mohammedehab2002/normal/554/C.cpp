#include <iostream>
using namespace std;
#define mod 1000000007
long long ncr[2005][2005];
int main()
{
	for (int i=0;i<2005;i++)
	{
		ncr[i][0]=1;
		for (int x=1;x<=i;x++)
		ncr[i][x]=(ncr[i-1][x]+ncr[i-1][x-1])%mod;
	}
	long long ans=1;
	int k,sum=0;
	scanf("%d",&k);
	for (int i=0;i<k;i++)
	{
		int a;
		scanf("%d",&a);
		if (!i)
		{
			sum+=a;
			continue;
		}
		long long tmp=0;
		for (int x=1;x<=a;x++)
		tmp=(tmp+ncr[sum+a-x-1][a-x])%mod;
		ans=(ans*tmp)%mod;
		sum+=a;
	}
	printf("%I64d",ans);
}
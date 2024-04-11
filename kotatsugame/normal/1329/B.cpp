#include<cstdio>
#include<algorithm>
using namespace std;
int T;
long long D,M;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld",&D,&M);
		long long ans=1;
		for(int k=0;1<<k<=D;k++)
		{
			long long R=min(D,(1LL<<k+1)-1);
			ans=ans*(R-(1<<k)+2)%M;
		}
		printf("%lld\n",(ans+M-1)%M);
	}
}
#include<cstdio>
using namespace std;
int Q;
main()
{
	scanf("%d",&Q);
	for(;Q--;)
	{
		long long k,n,a,b;
		scanf("%lld%lld%lld%lld",&k,&n,&a,&b);
		if(k-b*n<=0)
		{
			puts("-1");
		}
		else
		{
			long long ans=(k-b*n-1)/(a-b);
			if(ans>n)ans=n;
			printf("%lld\n",ans);
		}
	}
}
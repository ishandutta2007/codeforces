#include<cstdio>
using namespace std;
int T;
long long N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld\n",&N);
		long long ans=0;
		for(long long w=1;w<=N;w+=2)
		{
			ans+=(4*w-4)*(w/2);
		}
		printf("%lld\n",ans);
	}
}
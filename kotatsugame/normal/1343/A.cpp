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
		long long x=-1;
		for(int k=2;k<=35;k++)
		{
			long long u=(1LL<<k)-1;
			if(N%u==0)
			{
				x=N/u;
				break;
			}
		}
		printf("%lld\n",x);
	}
}
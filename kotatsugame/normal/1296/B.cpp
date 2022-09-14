#include<cstdio>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int S;
		scanf("%d",&S);
		long long ans=0;
		while(S>=10)
		{
			ans+=S-S%10;
			S=S%10+S/10;
		}
		printf("%lld\n",ans+S);
	}
}
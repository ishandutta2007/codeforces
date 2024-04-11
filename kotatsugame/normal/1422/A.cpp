#include<cstdio>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		long long a,b,c,d;
		scanf("%lld%lld%lld",&a,&b,&c);
		d=a+b+c-1;
		printf("%lld\n",d);
	}
}
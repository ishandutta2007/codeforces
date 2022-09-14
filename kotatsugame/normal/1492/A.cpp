#include<cstdio>
#include<algorithm>
using namespace std;
int T;
long long P,A,B,C;
long long f(long long p,long long a)
{
	return (p+a-1)/a*a-p;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld%lld%lld",&P,&A,&B,&C);
		printf("%lld\n",min(f(P,A),min(f(P,B),f(P,C))));
	}
}
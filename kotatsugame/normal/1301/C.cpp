#include<cstdio>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		long long N,M;
		scanf("%lld%lld",&N,&M);
		long long L=(N-M)/(M+1);
		long long ka=(N-M)%(M+1);
		long long kb=M+1-ka;
		printf("%lld\n",N*(N+1)/2-(L+1)*(L+2)/2*ka-L*(L+1)/2*kb);
	}
}
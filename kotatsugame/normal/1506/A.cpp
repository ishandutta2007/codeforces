#include<cstdio>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int N,M;
		long long X;
		scanf("%d%d%lld",&N,&M,&X);
		X--;
		long long i=X%N,j=X/N;
		printf("%lld\n",i*M+j+1);
	}
}
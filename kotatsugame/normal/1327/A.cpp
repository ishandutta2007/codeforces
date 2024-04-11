#include<cstdio>
using namespace std;
int t;
long long N,K;
main()
{
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%lld%lld",&N,&K);
		long long d=N-K*K;
		puts(d<0||d%2==1?"NO":"YES");
	}
}
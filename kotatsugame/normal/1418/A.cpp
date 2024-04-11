#include<cstdio>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		long long x,y,k;scanf("%lld%lld%lld",&x,&y,&k);
		printf("%lld\n",k+(k*(y+1)-1+x-1-1)/(x-1));
	}
}
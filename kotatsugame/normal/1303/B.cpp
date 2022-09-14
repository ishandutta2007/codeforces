#include<cstdio>
using namespace std;
int T;
long long N,G,B;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld%lld",&N,&G,&B);
		long long high=(N+1)/2;
		long long low=N-high;
		long long t;
		if(high%G==0)t=high/G-1;
		else t=high/G;
		low-=B*t;
		long long ans=t*(G+B)+(high-t*G);
		if(low>0)ans+=low;
		printf("%lld\n",ans);
	}
}
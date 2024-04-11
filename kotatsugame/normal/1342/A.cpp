#include<cstdio>
using namespace std;
int T;
long long x,y,a,b,ans;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		ans=0;
		long long t=x<y?x:y;
		ans+=t*(b<2*a?b:2*a);
		x-=t;y-=t;
		ans+=(x+y)*a;
		printf("%lld\n",ans);
	}
}
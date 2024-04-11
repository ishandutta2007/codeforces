#include<cstdio>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		long long a,b,c,r;scanf("%lld%lld%lld%lld",&a,&b,&c,&r);
		if(a>b)
		{
			long long tmp=a;
			a=b;
			b=tmp;
		}
		long long ans=b-a;
		long long L=c-r,R=c+r;
		if(L<a)
		{
			if(R<a);
			else if(R<b)ans=b-R;
			else ans=0LL;
		}
		else if(L<=b)
		{
			if(R<=b)ans-=R-L;
			else ans-=b-L;
		}
		else if(b<L);
		printf("%lld\n",ans);
	}
}
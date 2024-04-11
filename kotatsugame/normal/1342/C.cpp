#include<cstdio>
using namespace std;
int T;
int a,b,q;
long long l,r;
bool ok[40040];
int cnt[40040];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&a,&b,&q);
		cnt[0]=0;
		for(int i=0;i<a*b;i++)
		{
			cnt[i+1]=cnt[i];
			if(i%a%b!=i%b%a)
			{
				cnt[i+1]++;
			}
		}
		int X=a*b;
		for(;q--;)
		{
			scanf("%lld%lld",&l,&r);
			r++;
			long long ans=0;
			if(l/X==r/X)
			{
				ans=cnt[r%X]-cnt[l%X];
			}
			else
			{
				ans+=cnt[X]-cnt[l%X];
				l=l/X*X+X;
				ans+=cnt[r%X];
				r=r/X*X;
				ans+=(r-l)/X*cnt[X];
			}
			printf("%lld%c",ans,q?' ':'\n');
		}
	}
}
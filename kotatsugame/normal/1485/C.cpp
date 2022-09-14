#include<cstdio>
using namespace std;
int T,X,Y;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&X,&Y);
		int b=1;
		long long ans=0;
		while(b<=Y)
		{
			int L=X/(b+1),R=b-1;
			if(L<R)break;
			ans+=R;
			b++;
		}
		while(b<=Y)
		{
			int u=X/(b+1);
			if(u==0)break;
			int rb=X/u-1;
			if(rb>=Y)
			{
				ans+=(long long)u*(Y-b+1);
			}
			else
			{
				ans+=(long long)u*(rb-b+1);
			}
			b=rb+1;
		}
		printf("%lld\n",ans);
	}
}
#include<cstdio>
#include<algorithm>
using namespace std;
int N,H,A,B,K;
main()
{
	scanf("%d%d%d%d%d",&N,&H,&A,&B,&K);
	for(;K--;)
	{
		int ta,fa,tb,fb;
		scanf("%d%d%d%d",&ta,&fa,&tb,&fb);
		if(ta==tb)
		{
			printf("%d\n",abs(fa-fb));
		}
		else
		{
			int len=abs(ta-tb);
			if(fa>fb)swap(fa,fb);
			if(B<fa)
			{
				printf("%d\n",len+fa-B+fb-B);
			}
			else if(fb<A)
			{
				printf("%d\n",len+A-fb+A-fa);
			}
			else
			{
				printf("%d\n",len+fb-fa);
			}
		}
	}
}
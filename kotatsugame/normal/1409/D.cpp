#include<cstdio>
using namespace std;
int T;
long long N;
int S;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%d",&N,&S);
		int nowS=0;
		long long ans=9e18;
		long long p=1e18;
		for(int tm=0;tm<19;tm++)
		{
			if(N/p%10<9)
			{
				long long M=(N+p-1)/p*p;
				int ts=nowS+M/p%10;
				if(ts<=S&&ans>M-N)ans=M-N;
			}
			nowS+=N/p%10;
			p/=10;
		}
		if(nowS<=S)ans=0;
		printf("%lld\n",ans);
	}
}
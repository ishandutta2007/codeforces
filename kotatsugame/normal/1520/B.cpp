#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int ans=0;
		long long p=1;
		while(p<=N)
		{
			long long t=N/p;
			if(t>9)t=9;
			ans+=t;
			p=p*10+1;
		}
		printf("%d\n",ans);
	}
}
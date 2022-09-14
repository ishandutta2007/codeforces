#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int ans=N-1;
		for(int t=1;t*t<=N;t++)
		{
			int now=t-1+(N+t-1)/t-1;
			if(ans>now)ans=now;
		}
		printf("%d\n",ans);
	}
}
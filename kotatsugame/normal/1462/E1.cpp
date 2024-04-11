#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[2<<17];
long long cnt[2<<17];
long long ans;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=1;i<=N+2;i++)cnt[i]=0;
		ans=0;
		for(int i=0;i<N;i++)
		{
			int a;
			scanf("%d",&a);
			for(int x=-2;x<=2;x++)for(int y=x;y<=2;y++)if(a+x>=1&&a+y>=1&&abs(x-y)<=2)
			{
				if(x==y)ans+=cnt[a+x]*(cnt[a+x]-1)/2;
				else ans+=cnt[a+x]*cnt[a+y];
			}
			cnt[a]++;
		}
		printf("%lld\n",ans);
	}
}
#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,C;
int A[2<<17],B[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&C);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<N-1;i++)scanf("%d",&B[i]);
		long long ans=9e18;
		long long dy=0;
		long long now=0;
		for(int i=0;i<N;i++)
		{
			if(now>=C)ans=min(ans,dy);
			else ans=min(ans,dy+(C-now+A[i]-1)/A[i]);
			if(i+1<N)
			{
				if(now>=B[i])
				{
					now-=B[i];
					dy++;
				}
				else
				{
					long long k=(B[i]-now+A[i]-1)/A[i];
					dy+=k+1;
					now+=k*A[i];
					now-=B[i];
				}
			}
		}
		printf("%lld\n",ans==(long long)9e18?-1:ans);
	}
}
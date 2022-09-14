#include<cstdio>
using namespace std;
int t;
int N,M;
int A[1<<17],ia[1<<17];
main()
{
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			ia[A[i]]=i;
		}
		int pick=-1;
		long long ans=M;
		for(int i=0;i<M;i++)
		{
			int b;scanf("%d",&b);
			if(ia[b]>pick)
			{
				int left=ia[b]-i;
				ans+=2*left;
				pick=ia[b];
			}
		}
		printf("%lld\n",ans);
	}
}
#include<cstdio>
using namespace std;
int T,N,M,K;
int A[2<<17],Ac[2<<17],B[2<<17],Bc[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&M,&K);
		for(int i=0;i<N;i++)Ac[i]=0;
		for(int i=0;i<M;i++)Bc[i]=0;
		for(int i=0;i<K;i++)
		{
			scanf("%d",&A[i]);
			A[i]--;
			Ac[A[i]]++;
		}
		for(int i=0;i<K;i++)
		{
			scanf("%d",&B[i]);
			B[i]--;
			Bc[B[i]]++;
		}
		long long ans=0;
		for(int i=0;i<K;i++)
		{
			ans+=K-Ac[A[i]]-Bc[B[i]]+1;
		}
		printf("%lld\n",ans/2);
	}
}
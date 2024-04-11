#include<cstdio>
using namespace std;
int T,N;
int A[2<<17],B[2<<17];
int Ac[2<<17],Bc[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)Ac[i]=Bc[i]=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d%d",&A[i],&B[i]);
			A[i]--,B[i]--;
			Ac[A[i]]++;
			Bc[B[i]]++;
		}
		long long ans=(long long)N*(N-1)*(N-2)/6;
		for(int i=0;i<N;i++)
		{
			ans-=(long long)(Ac[A[i]]-1)*(Bc[B[i]]-1);
		}
		printf("%lld\n",ans);
	}
}
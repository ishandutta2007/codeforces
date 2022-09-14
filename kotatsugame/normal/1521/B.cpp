#include<cstdio>
using namespace std;
int T,N;
int A[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int mi=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			if(A[i]<A[mi])mi=i;
		}
		printf("%d\n",N-1);
		for(int i=0;i<N;i++)if(i!=mi)
		{
			printf("%d %d %d %d\n",i+1,mi+1,A[mi]+((mi-i)%2==0?0:1),A[mi]);
		}
	}
}
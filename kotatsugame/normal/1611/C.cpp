#include<cstdio>
using namespace std;
int T,N;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		if(A[0]==N)
		{
			printf("%d",N);
			for(int i=N-1;i>=1;i--)printf(" %d",A[i]);
			puts("");
		}
		else if(A[N-1]==N)
		{
			for(int i=N-2;i>=0;i--)printf("%d ",A[i]);
			printf("%d\n",N);
		}
		else puts("-1");
	}
}
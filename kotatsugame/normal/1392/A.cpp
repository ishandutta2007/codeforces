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
		int M=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			if(M<A[i])M=A[i];
		}
		bool ok=false;
		for(int i=0;i<N;i++)if(A[i]<M)ok=true;
		printf("%d\n",ok?1:N);
	}
}
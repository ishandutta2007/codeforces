#include<cstdio>
using namespace std;
int T,N,S;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		S=0;
		for(int i=0;i<N;i++)
		{
			int A;
			scanf("%d",&A);
			S+=A;
		}
		printf("%d\n",S==N?0:S<N?1:S-N);
	}
}
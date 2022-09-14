#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		double S=0,mx=-2e9;
		for(int i=0;i<N;i++)
		{
			int A;scanf("%d",&A);
			S+=A;
			if(mx<A)mx=A;
		}
		printf("%.16f\n",mx+(S-mx)/(N-1));
	}
}
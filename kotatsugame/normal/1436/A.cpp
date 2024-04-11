#include<cstdio>
using namespace std;
int T,N,M;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)
		{
			int A;scanf("%d",&A);
			M-=A;
		}
		puts(M?"NO":"YES");
	}
}
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
			for(int j=0;j<M;j++)
			{
				putchar(i==0&&j==0?'W':'B');
			}
			puts("");
		}
	}
}
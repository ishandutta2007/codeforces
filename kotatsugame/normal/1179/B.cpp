#include<cstdio>
using namespace std;
int N,M;
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<(N+1)/2;i++)
	{
		if(i!=N-1-i)
		{
			for(int j=0;j<M;j++)
			{
				printf("%d %d\n",i+1,j+1);
				printf("%d %d\n",N-i,M-j);
			}
		}
		else
		{
			for(int j=0;j<(M+1)/2;j++)
			{
				if(j!=M-1-j)
				{
					printf("%d %d\n",i+1,j+1);
					printf("%d %d\n",i+1,M-j);
				}
				else
				{
					printf("%d %d\n",i+1,j+1);
				}
			}
		}
	}
}
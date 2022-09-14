#include<cstdio>
using namespace std;
int T,N;
int A[100][100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			A[i][i]=1;
			A[i][(i+1)%N]=1;
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				printf("%d%c",A[i][j],j+1==N?'\n':' ');
				A[i][j]=0;
			}
		}
	}
}
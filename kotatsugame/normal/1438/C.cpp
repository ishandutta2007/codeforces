#include<cstdio>
using namespace std;
int T,N,M;
int A[100][100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			scanf("%d",&A[i][j]);
			if((i+j)%2!=A[i][j]%2)A[i][j]++;
		}
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			printf("%d%c",A[i][j],j+1==M?'\n':' ');
		}
	}
}
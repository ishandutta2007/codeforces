#include<cstdio>
using namespace std;
int N;
int A[2<<17][2];
main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)for(int j=0;j<2;j++)scanf("%d",&A[i][j]);
	if(N==3)
	{
		puts("1 2 3");
		return 0;
	}
	int u=1;
	for(int i=1;i<N;i++)
	{
		int v=A[u][0],w=A[u][1];
		if(A[v][0]==w||A[v][1]==w)u=v;
		else u=w;
		printf("%d ",u);
	}
	puts("1");
}
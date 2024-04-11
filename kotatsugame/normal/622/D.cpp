#include<cstdio>
using namespace std;
int N;
int A[1<<20];
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		if(i%2==1)
		{
			A[i/2]=i;
			A[N-i/2-1]=i;
		}
		else
		{
			A[N+i/2-1]=i;
			A[N+N-i/2-1]=i;
		}
	}
	for(int i=0;i<2*N;i++)
	{
		printf("%d%c",A[i]==0?N:A[i],i+1==2*N?10:32);
	}
}
#include<cstdio>
using namespace std;
int N,M,K;
int A[2<<17];
main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	int now=0;
	for(int i=N;i--;)
	{
		if(now>=A[i])
		{
			now-=A[i];
		}
		else
		{
			if(M==0)
			{
				printf("%d\n",N-i-1);
				return 0;
			}
			M--;
			now=K-A[i];
		}
	}
	printf("%d\n",N);
}
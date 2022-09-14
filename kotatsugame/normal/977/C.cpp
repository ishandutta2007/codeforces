#include<cstdio>
#include<algorithm>
using namespace std;
int N,K;
int A[2<<17];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	if(K==0)
	{
		if(A[0]==1)puts("-1");
		else puts("1");
	}
	else if(K==N)
	{
		printf("%d\n",A[N-1]);
	}
	else
	{
		if(A[K-1]<A[K])printf("%d\n",A[K-1]);
		else puts("-1");
	}
}
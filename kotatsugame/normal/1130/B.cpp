#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int A[1<<17][2];
main()
{
	scanf("%d",&N);
	for(int i=0;i<2*N;i++)
	{
		int a;
		scanf("%d",&a);
		if(A[a][0])A[a][1]=i+1;
		else A[a][0]=i+1;
	}
	A[0][0]=A[0][1]=1;
	long long now=0;
	for(int i=1;i<=N;i++)
	{
		now+=min(abs(A[i-1][0]-A[i][0])+abs(A[i-1][1]-A[i][1]),
				abs(A[i-1][0]-A[i][1])+abs(A[i-1][1]-A[i][0]));
	}
	printf("%lld\n",now);
}
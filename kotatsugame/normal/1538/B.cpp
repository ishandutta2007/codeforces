#include<cstdio>
using namespace std;
int T,N;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int sum=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			sum+=A[i];
		}
		if(sum%N!=0)
		{
			puts("-1");
			continue;
		}
		sum/=N;
		int cnt=0;
		for(int i=0;i<N;i++)cnt+=A[i]>sum;
		printf("%d\n",cnt);
	}
}
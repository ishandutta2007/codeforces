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
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		int R=N-1;
		while(R>0&&A[R-1]>=A[R])R--;
		while(R>0&&A[R-1]<=A[R])R--;
		printf("%d\n",R);
	}
}
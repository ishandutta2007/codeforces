#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,A[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int M=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			M=max(M,A[i]);
		}
		int s=0;
		for(int i=0;i<N;i++)
		{
			if((M-A[i])%2!=0)s++;
		}
		puts(s>0?"NO":"YES");
	}
}
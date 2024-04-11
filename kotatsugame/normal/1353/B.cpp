#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,K;
int A[30],B[30];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<N;i++)scanf("%d",&B[i]);
		sort(A,A+N);
		sort(B,B+N);
		int ans=0;
		for(int k=0;k<=K;k++)
		{
			int now=0;
			for(int i=0;i<N;i++)
			{
				if(i>=k)now+=A[i];
				else now+=max(A[i],B[i+N-k]);
			}
			ans=max(ans,now);
		}
		printf("%d\n",ans);
	}
}
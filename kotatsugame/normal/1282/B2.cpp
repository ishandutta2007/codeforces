#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,P,K;
int A[2<<17];
int S[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&P,&K);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		sort(A,A+N);
		int ans=0;
		S[0]=0;
		for(int i=1;i<=N;i++)
		{
			S[i]=A[i-1]+(i>=K?S[i-K]:S[i-1]);
			if(S[i]<=P)ans=i;
		}
		printf("%d\n",ans);
	}
}
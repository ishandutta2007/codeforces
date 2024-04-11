#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[2][1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<2;i++)for(int j=0;j<N;j++)scanf("%d",&A[i][j]);
		int ans=2e9;
		int L=0,R=0;
		for(int j=0;j<N;j++)R+=A[0][j];
		for(int j=0;j<N;j++)
		{
			R-=A[0][j];
			ans=min(ans,max(L,R));
			L+=A[1][j];
		}
		printf("%d\n",ans);
	}
}
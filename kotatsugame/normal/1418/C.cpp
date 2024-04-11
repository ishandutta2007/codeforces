#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[2<<17],dp[2][2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<=N;i++)dp[0][i]=dp[1][i]=1e9;
		dp[0][0]=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<2;j++)
			{
				dp[1-j][i+1]=min(dp[1-j][i+1],dp[j][i]+A[i]*!j);
				dp[1-j][i+2]=min(dp[1-j][i+2],dp[j][i]+(A[i]+A[i+1])*!j);
			}
		}
		printf("%d\n",min(dp[0][N],dp[1][N]));
	}
}
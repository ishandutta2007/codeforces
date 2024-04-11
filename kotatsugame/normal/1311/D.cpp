#include<cstdio>
#include<algorithm>
using namespace std;
int T,A[3];
const int LIM=40000;
int dp[3][LIM+1];
int pr[2][LIM+1];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		for(int i=0;i<3;i++)scanf("%d",&A[i]);
		for(int i=1;i<=LIM;i++)dp[2][i]=abs(A[2]-i);
		for(int i=2;i--;)
		{
			for(int j=1;j<=LIM;j++)
			{
				dp[i][j]=1e9;
				for(int k=j;k<=LIM;k+=j)if(dp[i][j]>dp[i+1][k])
				{
					dp[i][j]=dp[i+1][k];
					pr[i][j]=k;
				}
				dp[i][j]+=abs(A[i]-j);
			}
		}
		int mA=1;
		for(int i=1;i<=LIM;i++)if(dp[0][mA]>dp[0][i])mA=i;
		printf("%d\n%d %d %d\n",dp[0][mA],mA,pr[0][mA],pr[1][pr[0][mA]]);
	}
}
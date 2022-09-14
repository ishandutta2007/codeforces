#include<cstdio>
#include<algorithm>
using namespace std;
int N,K;
int A[5050];
int dp[5050][5050];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	int r=0;
	for(int i=0;i<N;i++)
	{
		while(r<N&&A[r]<=A[i]+5)r++;
		for(int j=0;j<=K;j++)
		{
			dp[j+1][r]=max(dp[j+1][r],dp[j][i]+r-i);
			dp[j][i+1]=max(dp[j][i+1],dp[j][i]);
		}
	}
	printf("%d\n",dp[K][N]);
}
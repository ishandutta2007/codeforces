#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int dp[101][10001];
main()
{
	scanf("%d",&N);
	for(int i=0;i<=N;i++)for(int j=0;j<=N*100;j++)dp[i][j]=-1e9;
	dp[0][0]=0;
	int sum=0;
	int mu=0;
	for(int i=0;i<N;i++)
	{
		int a,b;scanf("%d%d",&a,&b);
		sum+=b;
		for(int k=i;k>=0;k--)
		{
			for(int j=0;j<=mu;j++)
			{
				dp[k+1][j+a]=max(dp[k+1][j+a],dp[k][j]+b);
			}
		}
		mu+=a;
	}
	for(int i=1;i<=N;i++)
	{
		int ans=0;
		for(int j=0;j<=mu;j++)
		{
			ans=max(ans,min(sum+dp[i][j],j*2));
		}
		printf("%d.%d%c",ans/2,ans%2*5,i==N?10:32);
	}
}
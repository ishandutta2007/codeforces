#include<cstdio>
#include<algorithm>
using namespace std;
int N,K;
int c[1<<17],f[1<<17];
int dp[501][5050];
int h[10];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N*K;i++)
	{
		int A;
		scanf("%d",&A);
		c[A]++;
	}
	for(int i=0;i<N;i++)
	{
		int A;
		scanf("%d",&A);
		f[A]++;
	}
	for(int i=0;i<K;i++)scanf("%d",&h[i]);
	for(int i=0;i<N;i++)for(int j=0;j<N*K;j++)
	{
		for(int l=1;l<=K;l++)dp[i+1][j+l]=max(dp[i+1][j+l],dp[i][j]+h[l-1]);
	}
	int ans=0;
	for(int i=1;i<1<<17;i++)ans+=dp[f[i]][c[i]];
	printf("%d\n",ans);
}
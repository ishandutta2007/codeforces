#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,K;
int A[2<<17];
int sA[2020];
int XY[2020];
int dp[2020];
main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	for(int i=0;i<K;i++)sA[i+1]=sA[i]+A[i];
	for(int i=0;i<M;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<=K)
		{
			XY[x]=max(XY[x],y);
		}
	}
	for(int i=0;i<K;i++)dp[i]=1e9;
	for(int i=K;i;i--)
	{
		dp[i-1]=min(dp[i-1],dp[i]+A[i-1]);
		for(int j=1;j<=i;j++)
		{
			if(XY[j]>0)
			{
				dp[i-j]=min(dp[i-j],dp[i]+sA[i]-sA[i-j+XY[j]]);
			}
		}
	}
	printf("%d\n",dp[0]);
}
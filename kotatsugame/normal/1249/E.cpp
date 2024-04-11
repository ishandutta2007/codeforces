#include<cstdio>
#include<algorithm>
using namespace std;
int N,C;
int A[2<<17],B[2<<17];
int dp[2<<17];
main()
{
	scanf("%d%d",&N,&C);
	for(int i=1;i<N;i++)scanf("%d",&A[i]);
	for(int i=1;i<N;i++)scanf("%d",&B[i]);
	int cumB=0;
	int mn=0;
	for(int i=1;i<N;i++)
	{
		cumB+=B[i];
		dp[i]=min(dp[i-1]+A[i],cumB+mn+C);
		mn=min(mn,dp[i]-cumB);
	}
	for(int i=0;i<N;i++)printf("%d%c",dp[i],i+1==N?10:32);
}
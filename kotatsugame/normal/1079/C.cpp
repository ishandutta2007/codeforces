#include<cstdio>
using namespace std;
int N;
int A[1<<17];
int B[1<<17];
bool dp[1<<17][5];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<5;i++)dp[0][i]=true;
	for(int i=0;i<N-1;i++)
	{
		for(int j=0;j<5;j++)if(dp[i][j])
		{
			for(int k=0;k<5;k++)if(j!=k)
			{
				if(A[i]<A[i+1]&&j>k)continue;
				if(A[i]>A[i+1]&&j<k)continue;
				dp[i+1][k]=true;
			}
		}
	}
	int st=0;
	while(st<5&&!dp[N-1][st])st++;
	if(st==5)
	{
		puts("-1");
		return 0;
	}
	B[N-1]=st;
	for(int i=N-1;i--;)
	{
		for(int j=0;j<5;j++)if(st!=j&&dp[i][j])
		{
			if(A[i]<A[i+1]&&j>st)continue;
			if(A[i]>A[i+1]&&j<st)continue;
			B[i]=st=j;
			break;
		}
	}
	for(int i=0;i<N;i++)printf("%d%c",B[i]+1,i+1==N?10:32);
}
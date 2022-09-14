#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
char S[2<<17];
int dp[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d\n%s\n",&N,S);
		int ans=N;
		for(int st=0;st<N&&st<8;st++)
		{
			for(int i=0;i<=N;i++)dp[i]=N;
			dp[0]=0;
			for(int i=0;i<N;i++)
			{
				if(i+2<=N)
				{
					dp[i+2]=min(dp[i+2],dp[i]+(S[(st+i)%N]!='R')+(S[(st+i+1)%N]!='L'));
				}
				if(i+3<=N)
				{
					dp[i+3]=min(dp[i+3],dp[i]+(S[(st+i)%N]!='R')+(S[(st+i+1)%N]!='R')+(S[(st+i+2)%N]!='L'));
				}
				if(i+3<=N)
				{
					dp[i+3]=min(dp[i+3],dp[i]+(S[(st+i)%N]!='R')+(S[(st+i+1)%N]!='L')+(S[(st+i+2)%N]!='L'));
				}
				if(i+4<=N)
				{
					dp[i+4]=min(dp[i+4],dp[i]+(S[(st+i)%N]!='R')+(S[(st+i+1)%N]!='R')+(S[(st+i+2)%N]!='L')+(S[(st+i+3)%N]!='L'));
				}
			}
			ans=min(ans,dp[N]);
		}
		printf("%d\n",ans);
	}
}
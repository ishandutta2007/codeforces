#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,K;
char S[1<<20];
int cnt[1<<20],dp[1<<20];
main()
{
	scanf("%d\n",&T);
	for(;T--;)
	{
		scanf("%d %d\n%s\n",&N,&K,S);
		cnt[0]=0;
		for(int i=0;i<N;i++)cnt[i+1]=cnt[i]+(S[i]=='1'?1:0);
		int ans=cnt[N];
		dp[0]=0;
		for(int i=1;i<=N;i++)
		{
			int t=S[i-1]=='1'?0:1;
			dp[i]=cnt[i-1];
			if(i>=K)dp[i]=min(dp[i],dp[i-K]+cnt[i-1]-cnt[i-K]);
			dp[i]+=t;
			ans=min(ans,dp[i]+cnt[N]-cnt[i]);
		}
		printf("%d\n",ans);
	}
}
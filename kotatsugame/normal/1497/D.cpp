#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
int T,N;
int t[5000],s[5000];
long long dp[2][5000];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&t[i]),t[i]--;
		for(int i=0;i<N;i++)scanf("%d",&s[i]);
		int now=0;
		for(int i=0;i<N;i++)dp[now][i]=0;
		for(int i=1;i<N;i++)
		{
			int nxt=1-now;
			for(int j=0;j<N;j++)dp[nxt][j]=dp[now][j];
			long long L=-s[i],R=s[i];
			for(int j=i-1;j>=0;j--)
			{
				if(t[j]!=t[i])
				{
					dp[nxt][j]=max(dp[nxt][j],max(L+s[j],R-s[j]));
					long long X=dp[now][j]+abs(s[i]-s[j]);
					dp[nxt][i]=max(dp[nxt][i],X);
					L=max(L,X-s[i]);
					R=max(R,X+s[i]);
				}
			}
			now=nxt;
		}
		long long ans=-1e18;
		for(int j=0;j<N;j++)ans=max(ans,dp[now][j]);
		printf("%lld\n",ans);
	}
}
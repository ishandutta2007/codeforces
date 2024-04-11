#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
long long dp[2<<17][10];
main()
{
	scanf("%d",&N);
	for(int i=1;i<10;i++)dp[0][i]=-1e18;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<10;j++)dp[i+1][j]=-1e18;
		int K;
		scanf("%d",&K);
		int mx3=-1e9;
		int mx2=-1e9;
		vector<long long>mx1;
		for(int i=0;i<K;i++)
		{
			int c,d;scanf("%d%d",&c,&d);
			if(c==1)mx1.push_back(d);
			else if(c==2)mx2=max(mx2,d);
			else mx3=max(mx3,d);
		}
		sort(mx1.begin(),mx1.end());
		reverse(mx1.begin(),mx1.end());
		for(int j=0;j<10;j++)
		{
			long long T=dp[i][j];
			dp[i+1][j]=max(dp[i+1][j],T);
			if(mx3>0)dp[i+1][(j+1)%10]=max(dp[i+1][(j+1)%10],T+mx3*(j==9?2:1));
			if(mx2>0)dp[i+1][(j+1)%10]=max(dp[i+1][(j+1)%10],T+mx2*(j==9?2:1));
			if(mx2>0&&!mx1.empty())
			{
				dp[i+1][(j+2)%10]=max(dp[i+1][(j+2)%10],T+mx2*(j==9?2:1)+mx1[0]*(j==8?2:1));
				dp[i+1][(j+2)%10]=max(dp[i+1][(j+2)%10],T+mx1[0]*(j==9?2:1)+mx2*(j==8?2:1));
			}
			if(mx1.size()>=1)
			{
				dp[i+1][(j+1)%10]=max(dp[i+1][(j+1)%10],T+mx1[0]*(j==9?2:1));
			}
			if(mx1.size()>=2)
			{
				dp[i+1][(j+2)%10]=max(dp[i+1][(j+2)%10],T+mx1[0]*(j>=8?2:1)+mx1[1]);
			}
			if(mx1.size()>=3)
			{
				dp[i+1][(j+3)%10]=max(dp[i+1][(j+3)%10],T+mx1[0]*(j>=7?2:1)+mx1[1]+mx1[2]);
			}
		}
	}
	long long ans=-1e18;
	for(int j=0;j<10;j++)ans=max(ans,dp[N][j]);
	printf("%lld\n",ans);
}
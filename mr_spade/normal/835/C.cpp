#include<cstdio>
const int N=1e5+5,S=100;
int dp[15][S+5][S+5];
int n,q,c,ans;
int mp[S+5][S+5];
bool book[S+5][S+5];
signed main()
{
	int i,j;
	int x1,x2,y1,y2;
	scanf("%d%d%d",&n,&q,&c);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x1,&y1,&ans);
		dp[ans][x1][y1]++;
	}
	for(int t=0;t<=c;t++)
		for(x1=1;x1<=S;x1++)
			for(y1=1;y1<=S;y1++)
				dp[t][x1][y1]+=dp[t][x1-1][y1]+dp[t][x1][y1-1]-dp[t][x1-1][y1-1];
	int t;
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		ans=0;
		for(int p=0;p<=c;p++)
		{
			ans+=((p+t)%(c+1))*(dp[p][x2][y2]-dp[p][x1-1][y2]-dp[p][x2][y1-1]+dp[p][x1-1][y1-1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
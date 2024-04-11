#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char s1[100005],s2[100005];
int pos[100005],cnt;
int dp[5005][5005][2];
signed main()
{
	int t,n,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=read();
		y=read();
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		cnt=0;
		for(int i=1;i<=n;i++)if(s1[i]!=s2[i])pos[++cnt]=i;
		if(cnt%2==1)
		{
			printf("-1\n");
			continue;
		}
		if(y<=x)
		{
			if(cnt>=4)
			{
				printf("%lld\n",1LL*(cnt/2)*y);
				continue;
			}
			if(cnt==0)
			{
				printf("0\n");
				continue;
			}
			if(pos[2]-pos[1]==1)printf("%lld\n",min(2*y,x));
			else printf("%lld\n",y);
			continue;
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)dp[i][j][0]=dp[i][j][1]=1121131433448687LL;
		}
		if(s1[1]!=s2[1])dp[1][0][1]=0;
		else dp[1][0][0]=0;
		for(int i=2;i<=n;i++)
		{
			int now;
			if(s1[i]==s2[i])now=0;
			else now=1;
			for(int j=0;j<=n;j++)
			{
				dp[i][j+1][now]=min(dp[i][j+1][now],dp[i-1][j][1]);
				dp[i][j][now]=min(dp[i][j][now],dp[i-1][j][0]);
				dp[i][j+1][now^1]=min(dp[i][j+1][now^1],dp[i-1][j][0]+x);
				dp[i][j][now^1]=min(dp[i][j][now^1],dp[i-1][j][1]+x);
			}
		}
		int ans=1121131433448687LL;
		for(int j=0;j<=n;j+=2)
		{
			ans=min(ans,dp[n][j][0]+(j/2)*y);
			if(j!=0)ans=min(ans,dp[n][j-1][1]+(j/2)*y);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,dp[100005][2][2];char s[100005];
int main()
{
	for(read(T);T--;)
	{
		scanf("%s",s+1),n=strlen(s+1);for(int i=1;i<=n;i++) memset(dp[i],0x3f,sizeof(dp[i]));
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) dp[1][i][j]=i+j;
		for(int i=2;i<=n;i++)
		{
			if(s[i]==s[i-2])
			{
				dp[i][0][1]=min(dp[i-1][1][0]+1,dp[i-1][0][0]+1);
				dp[i][1][1]=min(dp[i-1][1][1]+1,dp[i-1][0][1]+1);
				if(s[i]!=s[i-1]) dp[i][0][0]=dp[i-1][1][0];
				dp[i][1][0]=dp[i-1][1][1];continue;
			}
			if(s[i]==s[i-1])
			{
				dp[i][0][1]=min(dp[i-1][0][0]+1,dp[i-1][1][0]+1);
				dp[i][1][0]=min(dp[i-1][1][1],dp[i-1][0][1]);
				dp[i][1][1]=min(dp[i-1][1][1]+1,dp[i-1][0][1]+1);
			}
			else
			{
				dp[i][0][1]=min(dp[i-1][0][0]+1,dp[i-1][1][0]+1);
				dp[i][1][0]=min(dp[i-1][1][1],dp[i-1][0][1]);
				dp[i][1][1]=min(dp[i-1][1][1]+1,dp[i-1][0][1]+1);
				dp[i][0][0]=min(dp[i-1][1][0],dp[i-1][0][0]);
			}
		}
		printf("%d\n",min(min(dp[n][0][0],dp[n][0][1]),min(dp[n][1][0],dp[n][1][1])));
	}
	return 0;
}
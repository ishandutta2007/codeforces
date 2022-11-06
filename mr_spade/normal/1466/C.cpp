#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
char s[N];
int bk1[N],bk2[N],dp[N][4];
inline void solve()
{
	register int i,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(bk1+1,0,sizeof(int)*n);
	memset(bk2+1,0,sizeof(int)*n);
	for(i=2;i<=n;i++)
		if(s[i]==s[i-1])
			bk1[i]=1;
	for(i=3;i<=n;i++)
		if(s[i]==s[i-2])
			bk2[i]=1;
	for(i=0;i<=n;i++)
		memset(dp[i],0x3f,sizeof(dp[i]));
	dp[0][0]=0;
	for(i=0;i<n;i++)
		for(j=0;j<4;j++)
		{
			dp[i+1][((j<<1)&2)+1]=min(dp[i+1][((j<<1)&2)+1],dp[i][j]+1);
			if((!bk1[i+1]||(j&1))&&(!bk2[i+1]||(j>>1&1)))
				dp[i+1][((j<<1)&2)]=min(dp[i+1][((j<<1)&2)],dp[i][j]);
		}
	int ans=0x3f3f3f3f;
	for(j=0;j<4;j++)
		ans=min(ans,dp[n][j]);
	printf("%d\n",ans);
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
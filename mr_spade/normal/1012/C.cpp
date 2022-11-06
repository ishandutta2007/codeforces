#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;
using std::max;
const int N=5005;
int n;
int a[N];
int dp[N][N>>1][3];
signed main()
{
	int last;
	register int i,j;
	scanf("%d",&n);
	a[0]=-0x3f3f3f3f;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[1][0][0]=dp[1][0][1]=dp[1][0][2]=0;
	for(i=2;i<=n;i++)
		for(j=0;j<=(i+1)>>1;j++)
		{
			if(i>2)
				last=min(a[i-2]-1,a[i-1]);
			else
				last=a[i-1];
			dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]+max(0,a[i]-last+1));
			dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]+max(0,last-a[i]+1));
			dp[i][j][2]=min(dp[i][j][2],dp[i-1][j][0]);
			if(j>0)
				dp[i][j][0]=min(dp[i][j][0],dp[i-1][j-1][1]+max(0,a[i]-a[i-1]+1));
			dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]+max(0,a[i-1]-a[i]+1));
			dp[i][j][2]=min(dp[i][j][2],dp[i-1][j][1]);
			dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][2]+max(0,a[i]-a[i-1]+1));
			dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][2]+max(0,a[i-1]-a[i]+1));
			dp[i][j][2]=min(dp[i][j][2],dp[i-1][j][2]);
		}
	for(i=1;i<=(n+1)>>1;i++)
		printf("%d ",min(min(dp[n][i][0],dp[n][i][2]),dp[n][i-1][1]));
	return 0;
}
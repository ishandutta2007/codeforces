#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
inline int abs(int x)
{
	return x<0?-x:x;
}
const int N=1e5+5;
int r,n,ans;
int x[N],y[N],t[N];
int dp[N],pdp[N];
inline bool judge(int i,int j)
{
	return t[j]+abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i];
}
signed main()
{
	register int i,j;
	scanf("%d%d",&r,&n);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
	x[0]=y[0]=1;
	memset(dp+1,-1,sizeof(int)*n);
	for(i=1;i<=n;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(t[i]-t[j]>2*r)
			{
				dp[i]=max(dp[i],pdp[j]+1);
				break;
			}
			if((~dp[j])&&judge(i,j))
				dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
		pdp[i]=max(pdp[i-1],dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
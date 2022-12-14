#include<bits/stdc++.h>
using namespace std;
double dp[1111],l,r,mid,cr;
int path[1111],x[1111],b[1111],n,L,cur,ans[1111],cnt;
bool check(double mid)
{
	for (int i=0;i<=n;i++) dp[i]=-1e9;
	dp[0]=0.00;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<i;j++)
		{
			cr=dp[j]+(double)b[i]-mid*sqrt((double)abs(x[i]-x[j]-L));
			if (cr>dp[i])
			{
				dp[i]=cr;
				path[i]=j;
			}
		}
	}
	if (dp[n]>=0.00) return 1;
	return 0;
}
int main()
{
	scanf("%d%d",&n,&L);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&b[i]);
	}
	l=0;r=1e9;
	for (int i=1;i<=60;i++)
	{
		mid=(l+r)/2.00;
		if (check(mid)) l=mid;
		else r=mid;
	}
	cur=n;
	while(cur)
	{
		ans[++cnt]=cur;
		cur=path[cur];
	}
	for (int i=cnt;i>=1;i--)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
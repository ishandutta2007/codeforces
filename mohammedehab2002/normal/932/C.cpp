#include <iostream>
#include <string.h>
using namespace std;
int dp[1000005];
int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for (int i=min(a,b);i<=n;i++)
	{
		if (i>=a && dp[i-a]!=-1)
		dp[i]=0;
		else if (i>=b && dp[i-b]!=-1)
		dp[i]=1;
	}
	if (dp[n]==-1)
	{
		printf("-1");
		return 0;
	}
	int pos=1;
	while (n!=0)
	{
		int cur=a;
		if (dp[n]==1)
		cur=b;
		for (int i=pos;i<pos+cur;i++)
		{
			if (i==pos+cur-1)
			printf("%d ",pos);
			else
			printf("%d ",i+1);
		}
		pos+=cur;
		n-=cur;
	}
}
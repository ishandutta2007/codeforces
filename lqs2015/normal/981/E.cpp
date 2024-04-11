#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,x,y,z,dp[11111],cnt;
pair<int,pair<int,int> > k[11111];
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		k[i]=make_pair(x,make_pair(y,z));
	}
	sort(k+1,k+q+1);
	dp[0]=1e9;
	for (int i=1;i<=q;i++)
	{
		for (int j=n;j>=k[i].second.second;j--)
		{
			if (dp[j-k[i].second.second]>=k[i].first)
			{
				dp[j]=max(dp[j],min(dp[j-k[i].second.second],k[i].second.first));
			}
		}
	}
	for (int i=1;i<=n;i++) if (dp[i]) cnt++;
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++) if (dp[i]) printf("%d ",i);
	return 0;
}
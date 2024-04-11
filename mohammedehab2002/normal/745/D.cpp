#include <iostream>
#include <vector>
using namespace std;
int dp[10][2][1005];
void ask(vector<int> v)
{
	printf("%d\n",v.size());
	for (int i:v)
	printf("%d ",i);
	printf("\n");
	fflush(stdout);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<10;i++)
	{
		vector<int> v1,v2;
		for (int j=1;j<=n;j++)
		{
			if (j&(1<<i))
			v1.push_back(j);
			else
			v2.push_back(j);
		}
		if (v1.empty())
		{
			for (int j=1;j<=n;j++)
			dp[i][1][j]=(1<<30);
		}
		else
		{
			ask(v1);
			for (int j=1;j<=n;j++)
			scanf("%d",&dp[i][1][j]);
		}
		if (v2.empty())
		{
			for (int j=1;j<=n;j++)
			dp[i][0][j]=(1<<30);
		}
		else
		{
			ask(v2);
			for (int j=1;j<=n;j++)
			scanf("%d",&dp[i][0][j]);
		}
	}
	printf("-1\n");
	for (int i=1;i<=n;i++)
	{
		int ans=(1<<30);
		for (int j=0;j<10;j++)
		{
			if (i&(1<<j))
			ans=min(ans,dp[j][0][i]);
			else
			ans=min(ans,dp[j][1][i]);
		}
		printf("%d ",ans);
	}
	fflush(stdout);
}
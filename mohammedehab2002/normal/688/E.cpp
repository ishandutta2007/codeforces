#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int arr[505];
bool dp[505][505][505];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	dp[0][0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int x=0;x<=k;x++)
		{
			for (int j=0;j<=k;j++)
			{
				dp[i][x][j]=dp[i-1][x][j];
				if (x>=arr[i])
				{
					dp[i][x][j]|=dp[i-1][x-arr[i]][j];
					if (j>=arr[i])
					dp[i][x][j]|=dp[i-1][x-arr[i]][j-arr[i]];
				}
			}
		}
	}
	for (int i=0;i<=k;i++)
	{
		if (dp[n][k][i])
		v.push_back(i);
	}
	printf("%d\n",v.size());
	for (int i:v)
	printf("%d ",i);
}
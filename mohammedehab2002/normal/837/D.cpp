#include <iostream>
using namespace std;
int dp[205][6005],maxi[205][6005],mx[205][6005];
pair<int,int> arr[205];
int fact(long long n,int x)
{
	int ans=0;
	while (n%x==0)
	{
		n/=x;
		ans++;
	}
	return ans;
}
int main()
{
	int n,k;
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		long long tmp;
		cin >> tmp;
		arr[i]=make_pair(fact(tmp,2),fact(tmp,5));
	}
	for (int i=0;i<205;i++)
	{
		for (int x=0;x<6005;x++)
		{
			maxi[i][x]=-(1<<30);
			mx[i][x]=-(1<<30);
		}
	}
	maxi[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int x=0;x<=min(i,k);x++)
		{
			for (int j=0;j<6005;j++)
			{
				if (!x || j<arr[i].second)
				dp[x][j]=maxi[x][j];
				else
				dp[x][j]=max(maxi[x][j],maxi[x-1][j-arr[i].second]+arr[i].first);
				mx[x][j]=max(mx[x][j],dp[x][j]);
			}
		}
		for (int x=0;x<205;x++)
		{
			for (int j=0;j<6005;j++)
			{
				maxi[x][j]=max(maxi[x][j],mx[x][j]);
				mx[x][j]=maxi[x][j];
			}
		}
	}
	int ans=0;
	for (int i=0;i<6005;i++)
	ans=max(ans,min(i,dp[k][i]));
	cout << ans;
}
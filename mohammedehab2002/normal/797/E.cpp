#include <iostream>
using namespace std;
int arr[100005],dp[100005][350];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=n-1;i>=0;i--)
	{
		for (int x=1;x<350;x++)
		{
			dp[i][x]=1;
			if (i+arr[i]+x<n)
			dp[i][x]=dp[i+arr[i]+x][x]+1;
		}
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int p,k;
		scanf("%d%d",&p,&k);
		p--;
		if (k<350)
		printf("%d\n",dp[p][k]);
		else
		{
			int ans=0;
			while (p<n)
			{
				ans++;
				p=p+arr[p]+k;
			}
			printf("%d\n",ans);
		}
	}
}
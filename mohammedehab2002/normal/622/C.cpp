#include <iostream>
using namespace std;
int dp[200005],arr[200005];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	dp[n-1]=n;
	for (int i=n-2;i>=0;i--)
	{
		if (arr[i]==arr[i+1])
		dp[i]=dp[i+1];
		else
		dp[i]=i+1;
	}
	while (q--)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		if (arr[l-1]!=x)
		printf("%d\n",l);
		else if (dp[l-1]>=r)
		printf("-1\n");
		else
		printf("%d\n",dp[l-1]+1);
	}
}
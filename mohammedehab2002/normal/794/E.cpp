#include <bits/stdc++.h>
using namespace std;
int arr[300005],ans[2][300005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		ans[(n-1)%2][n-1]=max(ans[(n-1)%2][n-1],arr[i]);
	}
	for (int i=1;i<n-1;i++)
	{
		int tmp=n-2*min(i,n-i-1)-1;
		ans[tmp%2][tmp]=max(ans[tmp%2][tmp],min(arr[i],max(arr[i-1],arr[i+1])));
	}
	for (int i=0;i<n-1;i++)
	{
		int tmp=n-2*min(i+1,n-i-1);
		ans[tmp%2][tmp]=max(ans[tmp%2][tmp],max(arr[i],arr[i+1]));
	}
	for (int i=0;i<n;i++)
	{
		if (i)
		{
			ans[0][i]=max(ans[0][i],ans[0][i-1]);
			ans[1][i]=max(ans[1][i],ans[1][i-1]);
		}
		printf("%d ",ans[i%2][i]);
	}
}
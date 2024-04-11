#include <iostream>
#include <algorithm>
using namespace std;
int ans[100005][3],arr[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	for (int i=0;i<n;i++)
	ans[i%(n/3)][i/(n/3)]=arr[i];
	for (int i=0;i<n/3;i++)
	{
		for (int x=1;x<3;x++)
		{
			if (!(ans[i][x]>ans[i][x-1] && ans[i][x]%ans[i][x-1]==0))
			{
				printf("-1");
				return 0;
			}
		}
	}
	for (int i=0;i<n/3;i++)
	{
		for (int x=0;x<3;x++)
		printf("%d ",ans[i][x]);
		printf("\n");
	}
}
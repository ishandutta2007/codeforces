#include <iostream>
#include <algorithm>
using namespace std;
int arr[1005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	for (int i=0;i<n;i++)
	{
		if (arr[i]%arr[0])
		{
			printf("-1");
			return 0;
		}
	}
	printf("%d\n",2*n);
	for (int i=0;i<n;i++)
	printf("%d %d ",arr[0],arr[i]);
}
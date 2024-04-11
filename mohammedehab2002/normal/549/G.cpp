#include <iostream>
#include <algorithm>
using namespace std;
int arr[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]),arr[i]+=i;
	sort(arr,arr+n);
	for (int i=0;i<n-1;i++)
	{
		if (arr[i]==arr[i+1])
		{
			printf(":(");
			return 0;
		}
	}
	for (int i=0;i<n;i++)
	printf("%d ",arr[i]-i);
}
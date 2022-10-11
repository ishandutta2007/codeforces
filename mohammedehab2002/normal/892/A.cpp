#include <iostream>
#include <algorithm>
using namespace std;
int arr[100005];
long long sum;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		sum+=a;
	}
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	if (arr[n-1]+arr[n-2]>=sum)
	printf("YES");
	else
	printf("NO");
}
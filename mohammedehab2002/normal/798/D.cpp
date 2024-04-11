#include <iostream>
#include <algorithm>
using namespace std;
pair<pair<int,int>,int> arr[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i].first.first),arr[i].second=i+1;
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i].first.second);
	sort(arr,arr+n);
	reverse(arr,arr+n);
	printf("%d\n%d",n/2+1,arr[0].second);
	for (int i=1;i<n;i+=2)
	{
		if (arr[i].first.second>arr[i+1].first.second)
		printf(" %d",arr[i].second);
		else
		printf(" %d",arr[i+1].second);
	}
}
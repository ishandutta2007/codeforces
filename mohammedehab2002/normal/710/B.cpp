#include <iostream>
#include <algorithm>
using namespace std;
int arr[300005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	printf("%d",arr[(n-1)/2]);
}
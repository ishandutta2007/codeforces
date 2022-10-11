#include <iostream>
#include <algorithm>
using namespace std;
int arr[100005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int sum=0;
	for (int i=0;i<k;i++)
	sum+=arr[i];
	printf("%d",sum);
}
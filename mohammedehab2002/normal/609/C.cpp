#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[100005];
int main()
{
	int n,s=0,ans=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]),s+=arr[i];
	sort(arr,arr+n);
	for (int i=0;i<n;i++)
	{
		if (i<n-s%n)
		ans+=abs(arr[i]-s/n);
		else
		ans+=abs(arr[i]-s/n-1);
	}
	printf("%d",ans/2);
}
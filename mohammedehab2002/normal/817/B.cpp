#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int arr[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    sort(arr,arr+n);
    if (arr[1]==arr[2])
    {
    	long long a=count(arr,arr+n,arr[1]);
    	if (arr[0]==arr[1])
    	printf("%I64d",a*(a-1)*(a-2)/6LL);
    	else
    	printf("%I64d",a*(a-1)/2LL);
	}
	else
	printf("%d",count(arr,arr+n,arr[2]));
}
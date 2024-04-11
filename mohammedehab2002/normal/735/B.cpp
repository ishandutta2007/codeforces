#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	int arr[n];
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	long long s1=0,s2=0;
	if (a>b)
	swap(a,b);
	for (int i=n-1;i>=n-a;i--)
	s1+=arr[i];
	for (int i=n-a-1;i>=n-a-b;i--)
	s2+=arr[i];
	printf("%.8lf",(double)s1/a+(double)s2/b);
}
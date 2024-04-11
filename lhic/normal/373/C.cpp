#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int n;

int arr[600000];


bool check(int x)
{
	if (2*x<n)
		return false;
	for (int i=0;i<x;i++)
	{
		if (i+x>=n)	
			break;
		if (arr[i]<2*arr[i+x])
			return false;
	}
	return true;
	
}



int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	reverse(arr,arr+n);
	int l=0;
	int r=n;
	while (r-l>1)
	{
		int m=(l+r)/2;
		if (check(m))
			r=m;
		else
			l=m;
	}
	printf("%d",r);
	return 0;
}
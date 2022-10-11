#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main()
{
	int n,k,maxi=0,test=0,i;
	cin >> n >> k;
	vector <double> arr(n),ans(n,0);
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		if (arr[i]>maxi)
		maxi=arr[i];
	}
	for (i=0;i<n;i++)
	{
		ans[i]+=maxi-arr[i];
		test+=maxi-arr[i];
	}
	if (test>k)
	{
		cout << -1;
		return 0;
	}
	k-=test;
	double t=(double)k/n;
	for (i=0;i<n;i++)
	printf ("%9.7f\n",(ans[i]+t));
}
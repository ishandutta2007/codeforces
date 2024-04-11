#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
int main()
{
	vector <double> v;
	int n,k,i;
	cin >> n >> k;
	double arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	sort (arr,arr+n);
	v.push_back(arr[0]);
	v.push_back(k-arr[n-1]);
	for (i=1;i<n;i++)
	v.push_back((arr[i]-arr[i-1])/2);
	printf ("%9.7f",*max_element (v.begin(),v.end()));
}
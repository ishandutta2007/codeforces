#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,w,i;
	cin >> n >> w;
	int arr[n*2];
	for (i=0;i<n*2;i++)
	cin >> arr[i];
	sort (arr,arr+n*2);
	printf ("%9.7f",(min(min(arr[0]*3.0,arr[n]*1.5)*n,(double)w)));
}
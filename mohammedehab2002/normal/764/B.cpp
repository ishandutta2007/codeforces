#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=0;i<n/2;i+=2)
	swap(arr[i],arr[n-i-1]);
	for (int i=0;i<n;i++)
	printf("%d ",arr[i]);
}
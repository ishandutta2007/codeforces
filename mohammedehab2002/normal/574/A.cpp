#include <iostream>
#include <algorithm>
using namespace std;
int find_max(int arr[],int f,int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		if (arr[i]==f)
		return i;
	}
}
int main()
{
	int n,i,maxi;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	int tmp=arr[0];
	again:maxi=*max_element(arr,arr+n);
	if (maxi==arr[0])
	{
		if (count(arr,arr+n,arr[0])==1)
		{
			cout << arr[0]-tmp;
			return 0;
		}
		cout << arr[0]-tmp+1;
		return 0;
	}
	arr[find_max(arr,maxi,n)]--;	
	arr[0]++;
	goto again;
}
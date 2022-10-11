#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
	int n,found=0,i,ans=1,res=0;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	sort (arr,arr+n);
	again: for (i=0;i<n;i++)
	{
		if (ans!=arr[i])
		res++;
	}
	if (res==n)
	{
		cout << ans;
		exit(0);
	}
	else
	{
		ans++;
		res=0;
		goto again;
	}
}
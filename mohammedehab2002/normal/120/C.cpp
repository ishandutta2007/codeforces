#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int maximum(pair<int,int> arr[],int n)
{
	int maxi=0,pos;
	for (int i=0;i<n;i++)
	{
		if (!arr[i].second)
		continue;
		if (arr[i].first>=maxi)
		{
			maxi=arr[i].first;
			pos=i;
		}
	}
	return pos;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,k,ans=0;
	cin >> n >> k;
	pair <int,int> arr[n];
	int j=n;
	for (int i=0;i<n;i++)
	{
		cin >> arr[i].first;
		arr[i].second=3;
	}
	int pos=maximum(arr,n);
	while (arr[pos].first>=k && j)
	{
		arr[pos].first-=k;
		arr[pos].second--;
		if (!arr[pos].second)
		j--;
		pos=maximum(arr,n);
	}
	for (int i=0;i<n;i++)
	ans+=arr[i].first;
	cout << ans;
}
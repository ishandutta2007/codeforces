#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int n,i,x;
	cin >> n;
	int arr[n];
	pair <int,int> c[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		c[i].first=arr[i];
		c[i].second=0;
	}
	sort (c,c+n);
	reverse(c,c+n);
	for (i=0;i<n;i++)
	{
		if (i!=0)
		{
			if (c[i].first==c[i-1].first)
			c[i].second=c[i-1].second;
			else
			c[i].second=i+1;
		}
		else
		c[i].second=i+1;
	}
	for (i=0;i<n;i++)
	{
		for (x=0;x<n;x++)
		{
			if (arr[i]==c[x].first)
			{
				cout << c[x].second << " ";
				goto out;
			}
		}
		out: int tmp;
	}
}
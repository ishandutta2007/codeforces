#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,k,i,x,ans=0,res=0;
	cin >> n >> k;
	int arr[n],copy[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		copy[i]=arr[i];
	}
	sort (arr,arr+n);
	for (i=0;i<n && ans+arr[i]<=k;i++)
	{
		ans+=arr[i];
		res++;
	}
	cout << res << endl;
	for (i=0;i<res;i++)
	{
		for (x=0;x<n;x++)
		{
			if (arr[i]==copy[x])
			{
				copy[x]=0;
				goto out;
			}
		}
		out: cout << x+1 << " ";
	}
}
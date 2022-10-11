#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,x,c,ci=0,j=0,k=0,f[]={0,0,0};
	cin >> n;
	int arr[n],copy[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		copy[i]=arr[i];
	}
	sort (arr,arr+n);
	for (i=0;i<n-2;i++)
	{
		for (x=i+1;x<n-1;x++)
		{
			for (c=x+1;c<n;c++)
			{
				if (arr[i]+arr[x]==arr[c])
				{
					ci=arr[i];
					j=arr[x];
					k=arr[c];
					goto out;
				}
			}
		}
	}
	out: if (ci==0)
	cout << -1;
	else
	{
		for (i=0;i<n;i++)
		{
			if (copy[i]==ci && f[0]==0)
			{
				ci=i+1;
				f[0]=1;
			}
			else if (copy[i]==j && f[1]==0)
			{
				j=i+1;
				f[1]=1;
			}
			else if (copy[i]==k && f[2]==0)
			{
				k=i+1;
				f[2]=1;
			}
		}
		cout << k << " " << j << " " << ci;
	}
}
#include <bits/stdc++.h>

using namespace std;

int a[2000005];

signed main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		a[i]=i;
	}
	for(int ii=2; ii<=n; ii++)
	{
		int i=ii-1;
		a[i+n]=a[i+(n/ii)*ii];
		for(int j=i+(n/ii)*ii; j>=i; j-=ii)
		{
			a[j]=a[j-ii];
		}
	}
	for(int i=1; i<=n; i++)
	{
		cout<<a[n+i-1]<<" ";
	}
}
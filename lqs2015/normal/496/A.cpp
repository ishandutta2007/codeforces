#include<iostream>
using namespace std;
int n,x;
int a[10000],ans,mx;
int main()
{
	cin>>n;
	ans=1e9;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	for (int i=2;i<n;i++)
	{
		mx=0;
		for (int j=1;j<n;j++)
		{
			if (j==i-1) 
			{
				x=a[j+2]-a[j];
				j++;
			}
			else x=a[j+1]-a[j];
			if (mx<x) mx=x;  
		}
		if (ans>mx) ans=mx;
	}
	cout<<ans;
	return 0;
}
#include<iostream>

using namespace std;

int main()
{
	int n,k;
	int a[500];
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int f;
	int sum=0;
	for(int i=1;i<n;i++)
	{
		f=k-a[i-1]-a[i];
		if(f>0)
		{
			a[i]+=f;
			sum+=f;
		}
	}
	cout<<sum<<endl;
	for(int i=0;i<n;i++)
	{
		if(i)cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
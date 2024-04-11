#include<iostream>
using namespace std;
int a[111];
int n,t;
bool check()
{
	for (int i=1;i<=n-1;i++)
	{
		if (a[i+1]<a[i]) return 0;
	}
	return 1;
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	cin>>a[i];
	while(1)
	{
		if (check()) return 0;
		for (int i=1;i<=n-1;i++)
		{
			if (check()) return 0;
			if (a[i]>a[i+1]) 
			{
				cout<<i<<" "<<i+1<<endl;
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}
	return 0;
}
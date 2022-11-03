#include<iostream>
using namespace std;
int main()
{
	int a[100],n,x=0,y=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]=a[i]%2;
		if(a[i]==0)
		x++;
		else
		y++;
	}
	if(x>y)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==1)
			{cout<<i+1;
			break;}
	
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
			{cout<<i+1;
			break;}
		}
	}
}
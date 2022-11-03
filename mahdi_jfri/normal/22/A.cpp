#include<iostream>
using namespace std;
int main()
{
	int min,min1,n,a,i;
	cin>>n;
	cin>>min;
	for(i=1;i<n;i++)
	{
		cin>>a;
		if(a>min)
		{
			min1=a;
			break;
		}
		else if(a<min)
		{
			min1=min;
			min=a;
			break;
		}
	}
	if(i>=n)
	{
		cout<<"NO";
		return 0;
	}
	for(;i<n-1;i++)
	{
		cin>>a;
		if((a>min)&&(a<min1))
		min1=a;
		else if(a<min)
		{
			min1=min;
			min=a;
		}
	}
	cout<<min1;
}
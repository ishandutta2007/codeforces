#include<iostream>
using namespace std;
int h,m,x;
bool can(int h,int m)
{
	return (h%10==7 || m%10==7);
}
int main()
{
	cin>>x;
	cin>>h>>m;
	if (can(h,m))
	{
		cout<<0<<endl;
		return 0;
	}
	for (int i=1;i<=1000;i++)
	{
		while(m<x)
		{
			h--;
			if (h<0) h+=24;
			m+=60;
		}
		m-=x;
		if (can(h,m)) 
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}
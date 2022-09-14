#include<iostream>

#define ll __int64

using namespace std;

int main()
{
	ll a,b,c,sum;
	cin>>a>>b>>c;
	if(b==c)
	{
		if(a==b)sum=0;
		else if(a<b)sum=b-a-1;
		else sum=2*(a-b-1);
	}
	else if(b<c)
	{
		if(a==b)sum=2*(c-a-1);
		else if(a<b)sum=2*(c-1)-(a+b);
		else//a>b,b<c
		{
			if(a==c)sum=a-b-1;
			else if(a<c)sum=2*(c-1)-(a+b);
			else sum=2*(a-1)-(b+c);
		}
	}
	else//b>c
	{
		if(a==b)sum=b-c-1;
		else if(a<b)sum=2*(b-1)-(a+c);
		else sum=2*(a-1)-(b+c);
	}
	cout<<sum<<endl;
	return 0;
}
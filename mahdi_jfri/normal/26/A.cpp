#include<iostream>
#include<math.h>
using namespace std;
int test(int a)
{
	int z=0;
	for(int i=2;i<=a;i++)
	{
		if(a%i==0)
		{
			z++;
			while(a%i==0)
			{
				a/=i;
			}
		}
	}
	return z;
}
int main()
{
	int a,b,count=0;
	cin>>a;
	for(int i=6;i<=a;i++)
	{
		b=test(i);
		if(b==2)
		count++;
	}
	cout<<count;
}
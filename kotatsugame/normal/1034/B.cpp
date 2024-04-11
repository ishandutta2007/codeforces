#include<iostream>
#include<algorithm>
using namespace std;
long long N,M;
main()
{
	cin>>N>>M;
	int x=N%6,y=M%6;
	if(x>y)swap(x,y),swap(N,M);
	int sub=0;
	if(x==0)sub=0;
	else if(x==1)
	{
		if(y==1||y==5)sub=1;
		else
		{
			if(N==1)
			{
				if(y==3)sub=3;
				else sub=2;
			}
			else
			{
				if(y==2)
				{
					if(N==7&&M==2)sub=2;
					else sub=0;
				}
				else if(y==3)sub=1;
				else sub=0;
			}
		}
	}
	else if(x==2)
	{
		if(y>=4)sub=0;
		else if(y==3)
		{
			if(N==2&&M==3)sub=2;
			else sub=0;
		}
		else if(y==2)
		{
			if(N==2&&M==2)sub=4;
			else sub=0;
		}
	}
	else
	{
		sub=x*y%2;
	}
	printf("%lld\n",N*M-sub);
}
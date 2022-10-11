#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
long long a1,b1,a2,b2,l,r;
long long mygcd(long long x,long long y)
{
	if(y==0)return x;else return mygcd(y,x%y);
}
int main()
{
	cin>>a1>>b1>>a2>>b2>>l>>r;
	if(a1>a2)
	{
		swap(a1,a2);
		swap(b1,b2);
	}
	if(b1>r || b2>r || l>r)
	{
		cout<<0;
		return 0;
	}
	long long t=a1/mygcd(a1,a2)*a2;
	long long res=0;
	bool f=false;
	long long tt;
	for(long long i=0;i<=t;i+=a2)
	{
		if(i+b2>r)break;
		if((i+b2-b1)%a1==0)
		{
			tt=(i+b2-b1)/a1;
			res=i+b2;
			f=true;
			break;
		}
	}
	if(!f)
	{
		cout<<0;
		return 0;
	}
	if(tt<0)
	{
		res+=((-tt-1)/(t/a1)+1)*t;
	}
	if(res<l)
	{
		res+=((l-res-1)/t+1)*t;
	}
	if(res>r)
	{
		cout<<0;
		return 0;
	}
	cout<<(r-res)/t+1;
	return 0;
}
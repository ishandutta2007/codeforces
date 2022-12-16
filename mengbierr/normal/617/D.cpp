#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
int x[5],y[5];
int main()
{
	cin>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3];
	if(x[1]==x[2]&&x[2]==x[3])
	{
		cout<<"1";
		return 0;
	}
	else if(y[1]==y[2]&&y[2]==y[3])
	{
		cout<<"1";
		return 0;
	}
	if(y[1]==y[2])
	{
		if(x[3]>min(x[1],x[2])&&x[3]<max(x[1],x[2]));
		else
		{
			cout<<"2";
			return 0;
		}
	}
	if(y[1]==y[3])
	{
		if(x[2]>min(x[1],x[3])&&x[2]<max(x[1],x[3]));
		else
		{
			cout<<"2";
			return 0;
		}
	}
	if(y[3]==y[2])
	{
		if(x[1]>min(x[3],x[2])&&x[1]<max(x[3],x[2]));
		else
		{
			cout<<"2";
			return 0;
		}
	}
		if(x[1]==x[2])
	{
		if(y[3]>min(y[1],y[2])&&y[3]<max(y[1],y[2]));
		else
		{
			cout<<"2";
			return 0;
		}
	}
	if(x[1]==x[3])
	{
		if(y[2]>min(y[1],y[3])&&y[2]<max(y[1],y[3]));
		else
		{
			cout<<"2";
			return 0;
		}
	}
	if(x[3]==x[2])
	{
		if(y[1]>min(y[3],y[2])&&y[1]<max(y[3],y[2]));
		else
		{
			cout<<"2";
			return 0;
		}
	}
	cout<<"3";
}
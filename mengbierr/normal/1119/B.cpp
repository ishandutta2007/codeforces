#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int a[5005],b[5005];
bool cmp(const int &x,const int &y)
{
	return x>y;
}
int main()
{
	int n=read(),h=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	int ans=0,now=0;
	for(int ii=1;ii<=n;ii++)
	{
		now=0;
		sort(a+1,a+ii+1,cmp);
		for(int i=1;i<=ii;i++)
		{
			if(i%2==1)
			{
				now+=a[i];
				if(now>h) break;
			}
		}
		if(now<=h)
		{
			ans=ii;
		}
	}
	cout<<ans;
}
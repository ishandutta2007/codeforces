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
int n,p;
ll a[100005],sum,maxx;
int main()
{
	n=read();p=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i];
	}
	ll temp=0;
	for(int i=1;i<=n;i++)
	{
		temp+=a[i];
		maxx=max(maxx,temp%p+(sum-temp)%p);
	}
	cout<<maxx;
	
}
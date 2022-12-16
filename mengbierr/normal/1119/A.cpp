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
int a[300005],ans=0;
int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[n])
		{
			ans=n-i;
			break;
		}
	}
	for(int i=n;i;i--)
	{
		if(a[i]!=a[1])
		{
			ans=max(ans,i-1);
			break;
		}
	}
	cout<<ans;
}
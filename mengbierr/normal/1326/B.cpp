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
int a[500005];
int main()
{
	int n=read();int maxx=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]>0)
		{
			maxx+=a[i];
			printf("%d ",maxx);
		}
		else printf("%d ",maxx+a[i]);
	}
}
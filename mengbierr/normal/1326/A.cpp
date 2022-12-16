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
int a[100005];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		if(n==1) puts("-1");
		else
		{
			a[1]=2;
			for(int i=2;i<=n;i++) a[i]=9;
			for(int i=1;i<=n;i++) printf("%d",a[i]);
			puts("");
		}
	}
}
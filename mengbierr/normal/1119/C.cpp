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
int a[505][505],b[505][505],n,m;
int numx[505],numy[505];
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) a[i][j]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) a[i][j]^=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]) numx[i]++,numy[j]++;
		}
	}
	bool ac=1;
	for(int i=1;i<=n;i++)
	{
		if(numx[i]&1) ac=0;
	}
	for(int i=1;i<=m;i++)
	{
		if(numy[i]&1) ac=0;
	}
	if(ac) puts("Yes");
	else puts("No");
}
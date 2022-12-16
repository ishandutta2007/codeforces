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
int a[500005],sum;
int main()
{
	int n=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	while(q--)
	{
		int op=read();
		if(op==2)
		{
			int x=read();
			if(x<=sum) puts("1");
			else puts("0");
		}
		else
		{
			int x=read();
			sum-=a[x];a[x]^=1;
			sum+=a[x];
		}
	}
}
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
int f[100005],a[100005],n,k;
int main()
{
	n=read();k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			f[i]=1+min(k,i-1)+min(k,n-i);
		}
		else
		{
			int pla=min(a[i]+k,n);
			f[i]=f[a[i]]+min(k,n-i)+min(k,i-pla-1)+1;
		}
		printf("%d ",f[i]);
	}
}
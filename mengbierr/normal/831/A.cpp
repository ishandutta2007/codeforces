#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{f=(f<<1)+(f<<3)+ch-'0';
	ch=getchar();}
	return f;
}
int a[1005];
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			bool ac=1;
			for(int k=1;k<=i;k++)
			{
				if(a[k]<=a[k-1])
				{
					ac=0;
					break;
				}
			}
			if(!ac)
			continue;
			for(int k=i+1;k<=j;k++)
			{
				if(a[k]!=a[k-1])
				{
					ac=0;
					break;
				}
			}
			if(!ac)
			continue;
			for(int k=j+1;k<=n;k++)
			{
				if(a[k]>=a[k-1])
				{
					ac=0;
					break;
				}
			}
			if(ac)
			{
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
}
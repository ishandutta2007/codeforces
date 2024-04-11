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
int a[55][55];
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		a[i][j]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]!=1)
			{
				bool ac=0;
				for(int k=1;k<=n;k++)
				{
					if(k==j)
					continue;
					for(int l=1;l<=n;l++)
					{
						if(i==l)
						continue;
						if(a[i][k]+a[l][j]==a[i][j])
						{
							ac=1;
							break;
						}
					}
					if(ac==1)
					{
						break;
					}
				}
				if(!ac)
				{
					printf("No");
					return 0;
				}
			}
		}
	}
	printf("Yes");
	return 0;
}
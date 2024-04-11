#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
long long c[55][55],ans;long long a[55][55],b[55],d[55];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=read();
			if(a[i][j])
			{
				b[i]++;
				d[j]++;
			}
		}
	}
	for(int i=0;i<=50;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=b[i];j++)
		{
			ans+=c[b[i]][j];
		}
		for(int j=1;j<=m-b[i];j++)
		{
			ans+=c[m-b[i]][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=2;j<=d[i];j++)
		{
			ans+=c[d[i]][j];
		}
		for(int j=2;j<=n-d[i];j++)
		{
			ans+=c[n-d[i]][j];
		}
	}
	cout<<ans;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inline  __attribute__((always_inline))
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int f[300005][45];
int n,a[300005];
int main()
{
	memset(f,0x7f7f7f7f,sizeof(f));
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read()/100;
	}
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=40;j++)
		{
			if(a[i]<j)
			{
				f[i][j-a[i]]=min(f[i][j-a[i]],f[i-1][j]);
			}
			else
			{
				f[i][0]=min(f[i][0],f[i-1][j]+a[i]-j);
			}
			f[i][j+a[i]/10]=min(f[i][j+a[i]/10],f[i-1][j]+a[i]);
		}
	}
	int ans=2000000000;
	for(int i=0;i<=40;i++) ans=min(ans,f[n][i]);
	cout<<1LL*ans*100;
}
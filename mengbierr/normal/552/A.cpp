#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
int a[105][105],n;
int main()
{
	n=read();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int xa=read(),ya=read(),xb=read(),yb=read();
		ans+=(xb-xa+1)*(yb-ya+1);
	}
	cout<<ans;
}
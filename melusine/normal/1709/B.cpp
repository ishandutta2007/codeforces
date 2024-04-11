#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[200005];
int qzh1[200005],qzh2[200005];
signed main()
{
	int n,m,x,y;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n-1;i++)
	{
		qzh1[i]=qzh1[i-1];
		qzh2[i]=qzh2[i-1];
		if(a[i+1]<a[i])qzh1[i]+=a[i]-a[i+1];
		else qzh2[i]+=a[i+1]-a[i];
	}
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		if(x<y)printf("%lld\n",qzh1[y-1]-qzh1[x-1]);
		else printf("%lld\n",qzh2[x-1]-qzh2[y-1]);
	}
	return 0;
}
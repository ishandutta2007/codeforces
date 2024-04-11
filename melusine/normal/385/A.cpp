#include<iostream>
#include<cstdio>
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
int a[1000005];
int main()
{
	int n,c,ans=0;
	n=read();
	c=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=2;i<=n;i++)ans=max(ans,a[i-1]-a[i]-c);
	printf("%d\n",ans);
	return 0;
}
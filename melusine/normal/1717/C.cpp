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
int a[200005],b[200005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			if(b[i]<a[i]||(b[i]!=a[i]&&b[i]-b[i%n+1]>=2))
			{
				flag=false;
				break;
			}
		}
		if(flag==false)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
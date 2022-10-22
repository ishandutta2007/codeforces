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
int a[100005],qzh[100005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		bool flag=false;
		for(int i=1;i<=n;i++)a[i]=read(),qzh[i]=qzh[i-1]+a[i];
		int ans=n;
		for(int i=0;i<=n;i++)
		{
			ans=min(ans,max(qzh[i],n-i-qzh[n]+qzh[i]));
		}
		printf("%d\n",ans);
	}
	return 0;
}
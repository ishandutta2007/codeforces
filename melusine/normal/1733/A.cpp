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
int a[105],maxn[105];
int main()
{
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		for(int i=0;i<=k;i++)maxn[i]=0;
		for(int i=1;i<=n;i++)maxn[i%k]=max(maxn[i%k],a[i]);
		long long ans=0;
		for(int i=0;i<k;i++)ans+=maxn[i];
		printf("%lld\n",ans);
	}
	return 0;
}
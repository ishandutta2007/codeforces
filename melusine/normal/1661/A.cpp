#include<iostream>
#include<cstdio>
#include<vector>
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
int a[1005],b[1005];
int jdz(int x)
{
	if(x>0)return x;
	return -x;
}
signed main()
{
	int t,n,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		for(int i=1;i<=n;i++)b[i]=read();
		ans=0;
		for(int i=2;i<=n;i++)
		{
			ans+=jdz(max(a[i],b[i])-max(a[i-1],b[i-1]))+jdz(min(a[i],b[i])-min(a[i-1],b[i-1]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
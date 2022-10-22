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
int qans[200005];
int a[200005],pre[200005];
int qz[200005],hz[200005];
signed main()
{
	int t,n,m,ans1,ans2;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(n%2==1)
		{
			ans1=0;
			for(int i=2;i<=n;i+=2)
			{
				if(a[i]<=max(a[i-1],a[i+1]))ans1+=max(a[i-1],a[i+1])-a[i]+1;
			}
			printf("%lld\n",ans1);
			continue;
		}
		ans1=1121131433448687LL;
		for(int i=2;i<=n-2;i+=2)
		{
			qz[i]=qz[i-2];
			if(a[i]<=max(a[i-1],a[i+1]))qz[i]+=max(a[i-1],a[i+1])-a[i]+1;
		}
		hz[n+1]=0;
		for(int i=n-1;i>=3;i-=2)
		{
			hz[i]=hz[i+2]; 
			if(a[i]<=max(a[i-1],a[i+1]))hz[i]+=max(a[i-1],a[i+1])-a[i]+1;
		}
		for(int i=0;i<=n-2;i+=2)
		{
			//printf("%lld %lld\n",qz[i],hz[i+3]);
			ans1=min(ans1,qz[i]+hz[i+3]);
		}
		printf("%lld\n",ans1);
	}
	return 0;
}
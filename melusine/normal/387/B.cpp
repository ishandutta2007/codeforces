#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
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
int a[100005],b[100005];
signed main()
{
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=m;i++)
	{
		b[i]=read();
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	int x=m,ans=0;
	for(int i=n;i>=1;i--)
	{
		if(x>=1&&b[x]>=a[i])
		{
			x--;
		}
		else ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
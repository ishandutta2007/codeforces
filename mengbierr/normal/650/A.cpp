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
int n;
struct data
{
	int x;
	int y;
}a[200005];
bool cmp1(const data &x,const data &y)
{
	if(x.x!=y.x) return x.x<y.x;
	return x.y<y.y;
}
bool cmp2(const data &x,const data &y)
{
	return x.y<y.y;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	long long ans=0;
	sort(a+1,a+n+1,cmp2);
	long long last=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i].y!=a[i-1].y)
		{
			ans+=(last*(last-1)/2LL);
			last=1;
		}
		else last++;
	}
	ans+=last*(last-1)/2;
	sort(a+1,a+n+1,cmp1);
	last=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i].x!=a[i-1].x)
		{
			ans+=(last*(last-1)/2LL);
			last=1;
		}
		else last++;
	}
	ans+=(last*(last-1)/2LL);
	last=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i].x==a[i-1].x&&a[i].y==a[i-1].y)
		{
			last++;
		}
		else
		{
			ans-=(last*(last-1)/2LL);
			last=1;
		}
	}ans-=(last*(last-1)/2LL);
	cout<<ans;
}
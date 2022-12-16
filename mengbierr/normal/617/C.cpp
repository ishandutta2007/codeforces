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
struct data
{
	int id;
	long long x,y;
	long long dis;
}a[2005];
long long inf=90000000000000000LL;
long long x1,y1,x2,y2,ans=900000000000000000LL;
long long x[2005],y[2005];
bool cmp(data x,data y)
{
	return x.dis<y.dis;
}
int main()
{
	int n=read();
	cin>>x1>>y1>>x2>>y2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=n;i++)
	{
		a[i].id=i;
		a[i].dis=(a[i].x-x1)*(a[i].x-x1)+(a[i].y-y1)*(a[i].y-y1);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=0;i<=n;i++)
	{
		long long temp=a[i].dis;long long maxx=0;
		for(int j=i+1;j<=n;j++)
		{
			maxx=max(maxx,(a[j].x-x2)*(a[j].x-x2)+(a[j].y-y2)*(a[j].y-y2));
		}
		ans=min(ans,temp+maxx);
	}
	cout<<ans;
}
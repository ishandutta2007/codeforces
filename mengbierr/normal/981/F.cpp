#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int a[200005],b[600005],m,n;
bool check(int x)
{
	int l=1,r=3*n;
	for(int i=1;i<=n;i++)
	{
		while(a[i]-b[l]>x) l++;
		while(b[r]-a[i]>x) r--;
		l++;r++;
	}
	return l<=r;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=n;i++)
	{
		b[i+n]=b[i]-m;
		b[i+2*n]=b[i]+m;
	}
	sort(b+1,b+3*n+1);
	sort(a+1,a+n+1);
	int l=0,r=(m+1)>>1,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans;
}
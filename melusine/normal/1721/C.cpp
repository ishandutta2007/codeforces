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
int sl[200005],slz[200005],slf[200005];
int n;
bool check(int x,int y)
{
	if(b[y]-a[x]<0)return false;
	if(x==y)
	{
		if(sl[n]==n)return true;
		return false;
	}
	if(x>y)
	{
		if(sl[y-1]!=y-1)return false;
		if(slf[x-1]-slf[y-1]!=x-y)return false;
		if(sl[n]-sl[x]!=n-x)return false;
		return true;
	}
	else
	{
		if(sl[x-1]!=x-1)return false;
		if(slz[y-1]-slz[x-1]!=y-x)return false;
		if(sl[n]-sl[y]!=n-y)return false;
		return true;
	}
}
int main()
{
	int t,l,r,mid;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		sl[0]=0;
		for(int i=1;i<=n;i++)
		{
			sl[i]=sl[i-1];
			if(a[i]<=b[i])sl[i]++;
		}
		slz[0]=0;
		for(int i=1;i<=n;i++)
		{
			slz[i]=slz[i-1];
			if(a[i+1]<=b[i])slz[i]++;
		}
		slf[0]=0;
		for(int i=1;i<=n;i++)
		{
			slf[i]=slf[i-1];
			if(a[i]<=b[i+1])slf[i]++;
		}
		for(int i=1;i<=n;i++)
		{
			l=1;
			r=i;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(check(i,mid))r=mid-1;
				else l=mid+1;
			}
			printf("%d ",b[l]-a[i]);
		}
		printf("\n");
		for(int i=1;i<=n;i++)
		{
			l=i;
			r=n;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(check(i,mid))l=mid+1;
				else r=mid-1;
			}
			printf("%d ",b[r]-a[i]);
		}
		printf("\n");
	} 
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define int unsigned long long
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
int findgh(int x)
{
	int l=1,r=x,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(mid<=x/mid)l=mid+1;
		else r=mid-1;
	}
	return r;
}
signed main()
{
	int t,l,r,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		l=read()-1;
		r=read();
		ans=(findgh(r))+((findgh(4*r+1))-1)/2+(findgh(r+1))-1;
		ans-=(findgh(l))+((findgh(4*l+1))-1)/2+(findgh(l+1))-1;
		printf("%llu\n",ans);
	}
	return 0;
}
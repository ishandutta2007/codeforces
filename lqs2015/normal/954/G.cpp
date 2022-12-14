#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,r,k,l,ro,mid,a[555555],sz,cnt,pt,b[555555],del;
bool flag;
long long Max(long long a,long long b)
{
	if (a>b) return a;
	return b;
}
long long Min(long long a,long long b)
{
	if (a<b) return a;
	return b; 
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&r,&k);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	l=0;ro=7e18;
	while(l<=ro)
	{
		flag=cnt=0;
		mid=(l+ro)/2;
		for (long long i=1;i<=n;i++)
		{
			b[i]=a[i];
		}
		pt=0;
		for (long long i=1;i<=r;i++) pt+=b[i];
		for (long long i=1;i<=n;i++)
		{
			if (i+r<=n) pt+=b[i+r];
			if (i-r-1>0) pt-=b[i-r-1];
			if (cnt>k) 
			{
				flag=1;
				break;
			}
			if (pt<mid) 
			{
				del=mid-pt;
				if (cnt>8e18-del)
				{
					flag=1;
					break;
				}
				cnt+=del;
				b[Min(n,i+r)]+=del;
				pt+=del;
			}
		}
		if (flag) 
		{
			ro=mid-1;
			continue;
		}
		if (cnt>k) ro=mid-1;
		else l=mid+1;
	}
	printf("%I64d\n",ro);
	return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;
long long n,a[555555],mx,mn,ans;
bool f0,f1;
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	mn=1e9;mx=-1e9;
	for (long long i=1;i<=n;i++)
	{
		if (a[i]<0) 
		{
			f0=1;
			ans-=a[i];
		}
		else 
		{
			f1=1;
			ans+=a[i];
		}
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	if (n==1)
	{
		printf("%I64d\n",a[1]);
		return 0;
	}
	if (f0 && f1)
	{
		printf("%I64d\n",ans);
		return 0;
	}
	if (f0) 
	{
		printf("%I64d\n",ans+2*mx);
		return 0;
	}
	if (f1)
	{
		printf("%I64d\n",ans-2*mn);
		return 0;
	}
	return 0;
}
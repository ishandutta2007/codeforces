#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a[111111],ans,sum[111111],cur;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	a[1]=0;
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i+1]);
	if ((n+1)&1)
	{
		a[n+2]=m;
		for (long long i=1;i<=n+2;i+=2)
		{
			ans+=(a[i+1]-a[i]);
		}
		for (long long i=n+2;i>=1;i--)
		{
			if (i&1) sum[i]=sum[i+1]-a[i];
			else sum[i]=sum[i+1]+a[i];
		}
		cur=ans;
		for (long long i=1;i<=n+2;i+=2)
		{
			cur=max(cur,-sum[i+1]+m+ans-sum[i]+(a[i+1]-a[i]-1));
			cur=max(cur,-sum[i+2]+m+ans-sum[i+2]-(a[i+1]+1));
		}
		printf("%I64d\n",cur);
	}
	else
	{
		a[n+2]=m;
		for (long long i=1;i<=n+1;i+=2)
		{
			ans+=(a[i+1]-a[i]);
		}
		for (long long i=n+1;i>=1;i--)
		{
			if (i&1) sum[i]=sum[i+1]-a[i];
			else sum[i]=sum[i+1]+a[i];
		}
		cur=ans;
		for (long long i=1;i<=n+1;i+=2)
		{
			cur=max(cur,-sum[i+1]+m+ans-sum[i]+(a[i+1]-a[i]-1));
			cur=max(cur,-sum[i+2]+m+ans-sum[i+2]-(a[i+1]+1));
		}
		printf("%I64d\n",cur);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;
long long n,h;
long long l[222222],r[222222],sb[222222],sq[222222],x,ans,L,R,rest;
int main()
{
	scanf("%I64d%I64d",&n,&h);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&l[i],&r[i]);
	}
	for (long long i=1;i<=n;i++)
	{
		x=r[i]-l[i];
		sq[i]=sq[i-1]+x;
		if (i<n)
		{
			x=l[i+1]-r[i];
			sb[i]=sb[i-1]+x;
		}
	}
	for (long long i=1;i<=n;i++)
	{
		L=1;R=n;
		while(L<=R)
		{
			long long mid=(L+R)/2;
			if (sb[mid-1]-sb[i-1]<h) L=mid+1;
			else R=mid-1;
		}
		ans=max(ans,h+sq[R]-sq[i-1]);
	}
	printf("%I64d\n",ans);
	return 0;
}
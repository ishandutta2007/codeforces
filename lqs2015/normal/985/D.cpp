#include<iostream>
#include<cstdio>
using namespace std;
long long l,r,n,h,mid;
int main()
{
	scanf("%I64d%I64d",&n,&h);
	l=1;r=2000000000ll;
	if (h>2e9 || (h+2)*(h+1)/2>n)
	{
		while(l<=r)
		{
			mid=(l+r)/2;
			if (mid*(mid+1)/2<=n) l=mid+1;
			else r=mid-1;
		}
		n-=r*(r+1)/2;
		if (!n) printf("%I64d\n",r);
		else printf("%I64d\n",r+1);
		return 0;
	}
	l=h+1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if (mid*(mid+1)-mid-(h-1)*h/2<=n) l=mid+1;
		else r=mid-1;
	}
	n-=r*(r+1);
	n+=(r+(h-1)*h/2);
	if (!n) printf("%I64d\n",r*2-h);
	else if (n<=r) printf("%I64d\n",r*2-h+1);
	else printf("%I64d\n",r*2-h+2);
	return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;
long long n,q,a[222222],x,pos,sum[222222],lst;
int main() 
{
	scanf("%I64d%I64d",&n,&q);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	while(q--)
	{
		scanf("%I64d",&x);
		x-=lst;
		if (x+sum[pos]>=sum[n])
		{
			pos=0;
			printf("%I64d\n",n);
			lst=0;
			continue;
		}
		long long t=x+sum[pos];
		pos=lower_bound(sum+1,sum+n+1,t)-sum;
		if (sum[pos]==t) 
		{
			lst=0;
			printf("%I64d\n",n-pos);
		}
		else 
		{
			lst=sum[pos]-t;
			printf("%I64d\n",n-pos+1);
		}
	}
	return 0;
}
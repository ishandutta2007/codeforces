#include<iostream>
#include<cstdio>
using namespace std;
long long n,a[333333],b[333333],sum1[333333],sum2[333333],ans,cur;
long long cura[333333],curb[333333];
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (long long i=1;i<=n;i++) scanf("%I64d",&b[i]);
	for (long long i=1;i<=n;i++) cura[i]=a[i]*(i-1);
	for (long long i=1;i<=n;i++) curb[i]=b[i]*(n+n-i);
	for (long long i=n;i>=1;i--)
	{
		sum1[i]=sum1[i+1]+cura[i]+curb[i];
		sum2[i]=sum2[i+1]+a[i]+b[i];
	}
	ans=sum1[1];
	for (long long i=1;i<=n;i++)
	{
		if (i&1) cur=cur+a[i]*(2*i-2)+b[i]*(2*i-1);
		else cur=cur+a[i]*(2*i-1)+b[i]*(2*i-2);
		if (i%2==0) ans=max(ans,cur+sum1[i+1]+i*sum2[i+1]);
	}
	for (long long i=1;i<=n;i++) cura[i]=a[i]*(n+n-i);
	for (long long i=1;i<=n;i++) curb[i]=b[i]*(i-1);
	cur=0;
	for (long long i=n;i>=1;i--)
	{
		sum1[i]=sum1[i+1]+cura[i]+curb[i];
		sum2[i]=sum2[i+1]+a[i]+b[i];
	}
	for (long long i=1;i<=n;i++)
	{
		if (i&1) cur=cur+a[i]*(2*i-2)+b[i]*(2*i-1);
		else cur=cur+a[i]*(2*i-1)+b[i]*(2*i-2);
		if (i&1) ans=max(ans,cur+sum1[i+1]+i*sum2[i+1]);
	}
	printf("%I64d\n",ans);
	return 0;
}
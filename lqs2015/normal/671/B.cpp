#include<bits/stdc++.h>
using namespace std;
long long n,k,a[555555],l,r,sum,L,R,mid;
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	L=0;R=1e9;
	while(L<=R)
	{
		long long mid=(L+R)/2;
		sum=0;
		for (long long i=1;i<=n;i++) sum+=max(0ll,mid-a[i]);
		if (sum<=k) L=mid+1;
		else R=mid-1;
	}
	l=R;
	L=0;R=1e9;
	while(L<=R)
	{
		long long mid=(L+R)/2;
		sum=0;
		for (long long i=1;i<=n;i++) sum+=max(0ll,a[i]-mid);
		if (sum<=k) R=mid-1;
		else L=mid+1;
	}
	r=L;
	if (l<r) printf("%I64d\n",r-l);
	else
	{
		sum=0;
		for (long long i=1;i<=n;i++) sum+=a[i];
		if (sum%n==0) printf("0\n");
		else printf("1\n");
	}
	return 0;
}
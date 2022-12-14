#include<iostream>
#include<cstdio>
using namespace std;
long long n,a[222222],pos,mx,sum,ans[222222];
pair<long long,long long> b[222222];
bool f;
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (long long i=2;i<=n;i++)
	{
		if (a[i]!=a[1])
		{
			f=1;
			break;
		}
	}
	if (!f)
	{
		if (a[1]==0)
		{
			printf("YES\n");
			for (long long i=1;i<=n;i++) printf("1 ");
			printf("\n");
		}
		else printf("NO\n");
		return 0;
	}
	for (long long i=1;i<=n;i++)
	{
		mx=max(mx,a[i]);
	}
	for (long long i=1;i<=n;i++)
	{
		if (a[i]==mx && a[(i-2+n)%n+1]<a[i])
		{
			pos=i%n+1;
			break;
		}
	}
	for (long long i=1;i<=n;i++)
	{
		b[i]=make_pair(a[pos],pos);
		pos=pos%n+1;
	}
	for (long long i=1;i<n;i++) sum+=b[i].first;
	for (long long i=1;i<n;i++)
	{
		ans[b[i].second]=sum+100*b[n].first;
		sum-=b[i].first;
	}
	ans[b[n].second]=b[n].first;
	printf("YES\n");
	for (long long i=1;i<=n;i++) printf("%I64d ",ans[i]);
	printf("\n");
	return 0;
}
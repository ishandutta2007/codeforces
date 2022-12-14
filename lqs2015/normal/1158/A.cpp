#include<bits/stdc++.h>
using namespace std;
int n,m,a[111111],b[111111];
long long sum;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	if (a[n]>b[1])
	{
		printf("-1\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	sum=sum*m;
	if (a[n]!=b[1])
	{
		for (int i=1;i<m;i++)
		{
			sum+=b[i];
			sum-=a[n];
		}
		sum+=b[m];sum-=a[n-1];
	}
	else
	{
		for (int i=1;i<=m;i++)
		{
			sum+=b[i];
			sum-=a[n];
		}
	}
	printf("%lld\n",sum);
	return 0;
}
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[222222],n,ans[222222];
pair<int,int> b[222222];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i].first);
		b[i].second=i;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
	{
		ans[b[i].second]=a[i];
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
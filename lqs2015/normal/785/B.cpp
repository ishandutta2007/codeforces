#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[222222],b[222222],c[222222],d[222222];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&c[i],&d[i]);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+m+1);
	sort(d+1,d+m+1);
	printf("%d\n",max(max(c[m]-b[1],a[n]-d[1]),0));
	return 0;
}
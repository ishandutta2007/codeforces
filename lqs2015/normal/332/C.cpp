#include<bits/stdc++.h>
using namespace std;
int n,p,k,mn;
pair<pair<int,int>,int> a[111111],b[111111];
int main()
{
	scanf("%d%d%d",&n,&p,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].first.second,&a[i].first.first);
		a[i].first.second=-a[i].first.second;
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	for (int i=p-k+1;i<=n;i++)
	{
		b[i]=make_pair(make_pair(a[i].first.second,-i),a[i].second);
	}
	sort(b+p-k+1,b+n+1);
	mn=1e9;
	for (int i=p-k+1;i<=p;i++)
	{
		printf("%d ",b[i].second);
		mn=min(mn,-b[i].first.second);
	}
	for (int i=1;i<mn;i++)
	{
		b[i]=make_pair(make_pair(-a[i].first.first,a[i].first.second),a[i].second);
	}
	sort(b+1,b+mn);
	for (int i=1;i<=p-k;i++) printf("%d ",b[i].second);
	printf("\n");
	return 0;
}
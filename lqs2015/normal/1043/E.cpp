#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,x[333333],y[333333],pre[333333],suf[333333],ans[333333],xx,yy,cur;
pair<pair<long long,long long>,pair<long long,long long> > a[333333];
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&x[i],&y[i]);
		a[i]=make_pair(make_pair(x[i]-y[i],i),make_pair(x[i],y[i]));
	}
	sort(a+1,a+1+n);
	for (long long i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i].second.first;
	}
	for (long long i=n;i>=1;i--) 
	{
		suf[i]=suf[i+1]+a[i].second.second;
	}
	for (long long i=1;i<=n;i++)
	{
		ans[a[i].first.second]=(y[a[i].first.second]*(i-1)+pre[i-1]+x[a[i].first.second]*(n-i)+suf[i+1]);
	}
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d",&xx,&yy);
		cur=min(x[xx]+y[yy],y[xx]+x[yy]);
		ans[xx]-=cur;ans[yy]-=cur;
	}
	for (long long i=1;i<=n;i++) printf("%I64d ",ans[i]);
	printf("\n");
	return 0;
}
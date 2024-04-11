#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200000;
const int inf=100000000;
struct trap
{
	int l,r,d;
}t[maxn+5];
int n,m,tim,k;
int a[maxn+5],id[maxn+5],tot=0;
int cmp(trap a,trap b)
{
	if(a.l!=b.l) return a.l<b.l;
	return a.r<b.r;
}
int Ca(int va)
{
	tot=0;
	for(int i=1;i<=k;i++)
	{
		if(t[i].d<=va) continue;
		id[++tot]=i;
	}
	if(tot==0) return n+1;
	int sum=0,mr=t[id[1]].r,ml=t[id[1]].l;
	for(int i=2;i<=tot;i++)
	{
		if(t[id[i]].l<=mr) mr=max(mr,t[id[i]].r);
		else
		{
			sum+=mr-ml+1;
			ml=t[id[i]].l;
			mr=t[id[i]].r;
		}
	}
	sum+=mr-ml+1;
	return sum*2+n+1;
}
signed main()
{
	scanf("%lld%lld%lld%lld",&m,&n,&k,&tim);
	for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
	sort(a+1,a+m+1);
	for(int i=1;i<=k;i++) scanf("%lld%lld%lld",&t[i].l,&t[i].r,&t[i].d);
	sort(t+1,t+k+1,cmp);
	int l=1,r=m,best=m+1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(Ca(a[mid])<=tim) best=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",m+1-best);
	return 0;
}
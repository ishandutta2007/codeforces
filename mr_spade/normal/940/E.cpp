#include<cstdio>
#include<iostream>
using std::min;
typedef long long ll;
const int N=1e5+5,inf=1e9+5;
int n,c;
int a[N];
ll dp[N];
struct node
{
	int l,r,Min;
	ll sum;
}sgt[N<<2];
void build(int now,int l,int r)
{
	sgt[now].l=l;sgt[now].r=r;
	if(l==r)
	{
		sgt[now].sum=a[l];
		sgt[now].Min=a[l];
		return;
	}
	int mid=l+r>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	sgt[now].sum=sgt[now<<1].sum+sgt[now<<1|1].sum;
	sgt[now].Min=min(sgt[now<<1].Min,sgt[now<<1|1].Min);
	return;
}
ll query_sum(int now,int l,int r)
{
	if(sgt[now].l>r||sgt[now].r<l)
		return 0;
	if(sgt[now].l>=l&&sgt[now].r<=r)
		return sgt[now].sum;
	return query_sum(now<<1,l,r)+query_sum(now<<1|1,l,r);
}
int query_min(int now,int l,int r)
{
	if(sgt[now].l>r||sgt[now].r<l)
		return inf;
	if(sgt[now].l>=l&&sgt[now].r<=r)
		return sgt[now].Min;
	return min(query_min(now<<1,l,r),query_min(now<<1|1,l,r));
}
signed main()
{
	register int i;
	scanf("%d%d",&n,&c);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+a[i];
		if(i-c>=0)
			dp[i]=min(dp[i],dp[i-c]+query_sum(1,i-c+1,i)-query_min(1,i-c+1,i));
	}
	printf("%I64d\n",dp[n]);
	return 0;
}
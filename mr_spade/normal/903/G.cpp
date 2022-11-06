#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<algorithm>
#include<ext/pb_ds/priority_queue.hpp>
#define int long long
using __gnu_pbds::priority_queue;
using std::min;
const int N=2e5+5;
int n,m,q;
int a[N],b[N],c[N];
int v[N],w[N],first[N],next[N];
int Min[N<<2],lazy[N<<2];
priority_queue<int> Q;
priority_queue<int>::point_iterator it[N];
inline void push_down(int x)
{
	if(!lazy[x])
		return;
	Min[x<<1]+=lazy[x];
	lazy[x<<1]+=lazy[x];
	Min[x<<1|1]+=lazy[x];
	lazy[x<<1|1]+=lazy[x];
	lazy[x]=0;
	return;
}
inline void push_up(int x)
{
	Min[x]=min(Min[x<<1],Min[x<<1|1]);
	return;
}
void build(int x,int lp,int rp)
{
	if(lp==rp)
		return Min[x]=b[lp],void();
	int mid=(lp+rp)>>1;
	build(x<<1,lp,mid);
	build(x<<1|1,mid+1,rp);
	push_up(x);
	return;
}
void modify(int x,int lp,int rp,int l,int r,int k)
{
	if(l>r)
		return;
	if(lp==l&&rp==r)
		return Min[x]+=k,lazy[x]+=k,void();
	int mid=(lp+rp)>>1;
	push_down(x);
	if(r<=mid)
		modify(x<<1,lp,mid,l,r,k);
	else if(l>=mid+1)
		modify(x<<1,mid+1,rp,l,r,k);
	else
		modify(x<<1,lp,mid,l,mid,k),modify(x<<1|1,mid+1,rp,mid+1,r,k);
	push_up(x);
	return;
}
signed main()
{
	int x,y;
	register int i,go;
	scanf("%lld%lld%lld",&n,&m,&q);
	for(i=1;i<n;i++)
		scanf("%lld%lld",&a[i],&b[i]);
	build(1,0,n-1);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&v[i],&w[i]);
		next[i]=first[x];first[x]=i;
	}
	for(i=1;i<=n;i++)
	{
		for(go=first[i];go;go=next[go])
			modify(1,0,n-1,0,v[go]-1,w[go]);
		c[i]=Min[1];
	}
	for(i=1;i<=n;i++)
		it[i]=Q.push(-a[i]-c[i]);
	printf("%lld\n",-Q.top());
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		a[x]=y;Q.modify(it[x],-a[x]-c[x]);
		printf("%lld\n",-Q.top());
	}
	return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;
const long long mod=1e9;
long long f[444444],qz[444444],n,m,a[444444],sz,tp,l,r,d,lazy[888888];
pair<long long,long long> tree[888888];
long long get(long long i)
{
	if (i<0) return 0;
	return f[i];
}
void add(long long len,long long node)
{
	tree[node].first=((tree[node*2].first+get(len-2)*tree[node*2+1].first)%mod+get(len-1)*tree[node*2+1].second)%mod;
	tree[node].second=((tree[node*2].second+get(len-1)*tree[node*2+1].first)%mod+get(len)*tree[node*2+1].second)%mod;
}
void pushdown(long long node,long long s)
{
	if (lazy[node])
	{
		lazy[node*2]=(lazy[node*2]+lazy[node])%mod;
		lazy[node*2+1]=(lazy[node*2+1]+lazy[node])%mod;
		tree[node*2].first=(tree[node*2].first+lazy[node]*qz[s-1])%mod;
		tree[node*2].second=(tree[node*2].second+lazy[node]*qz[s]-lazy[node])%mod;
		tree[node*2+1].first=(tree[node*2+1].first+lazy[node]*qz[s-1])%mod;
		tree[node*2+1].second=(tree[node*2+1].second+lazy[node]*qz[s]-lazy[node])%mod;
		lazy[node]=0;
	}
}
void build(long long l,long long r,long long node)
{
	if (l==r)
	{
		tree[node]=make_pair(a[l],a[l]);
		return;
	}
	long long mid=(l+r)/2,len=(r-l+1)/2;
	build(l,mid,node*2);
	build(mid+1,r,node*2+1);
	add(len,node);
}
void upd(long long x,long long y,long long l,long long r,long long node)
{
	if (l>x || r<x) return;
	if (l==r)
	{
		tree[node].first=y;tree[node].second=y;
		lazy[node]=0;
		return;
	}
	long long mid=(l+r)/2;
	pushdown(node,(r-l+1)/2);
	upd(x,y,l,mid,node*2);
	upd(x,y,mid+1,r,node*2+1);
	add((r-l+1)/2,node);
}
void update(long long beg,long long en,long long l,long long r,long long node,long long x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		lazy[node]=(lazy[node]+x)%mod;
		tree[node].first=(tree[node].first+x*qz[r-l])%mod;
		tree[node].second=(tree[node].second+x*qz[r-l+1]-x)%mod;
		return;
	}
	long long mid=(l+r)/2;
	pushdown(node,(r-l+1)/2);
	update(beg,en,l,mid,node*2,x);
	update(beg,en,mid+1,r,node*2+1,x);
	add((r-l+1)/2,node);
}
long long query(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return 0;
	if (l>=beg && r<=en) 
	{
		if (l==beg) return tree[node].first;
		return (tree[node].first*get(l-beg-2)+tree[node].second*get(l-beg-1))%mod;
	}
	pushdown(node,(r-l+1)/2);
	long long mid=(l+r)/2;
	return (query(beg,en,l,mid,node*2)+query(beg,en,mid+1,r,node*2+1))%mod;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	f[0]=f[1]=1;
	for (long long i=2;i<=2*n;i++) f[i]=(f[i-1]+f[i-2])%mod;
	qz[0]=1;
	for (long long i=1;i<=2*n;i++) qz[i]=(qz[i-1]+f[i])%mod;
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	sz=1;
	while(sz<n) sz*=2;
	build(1,sz,1);
	while(m--)
	{
		scanf("%I64d",&tp);
		if (tp==1) 
		{
			scanf("%I64d%I64d",&l,&r);
			upd(l,r,1,sz,1);
		}
		else if (tp==2)
		{
			scanf("%I64d%I64d",&l,&r);
			long long ans=query(l,r,1,sz,1);
			if (ans<0) ans+=mod;
			printf("%I64d\n",ans);
		}
		else
		{
			scanf("%I64d%I64d%I64d",&l,&r,&d);
			update(l,r,1,sz,1,d);
		}
	}
	return 0;
}
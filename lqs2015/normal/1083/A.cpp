#include<bits/stdc++.h>
using namespace std;
long long n,w[333333],x,y,z,dep[333333],tree[2222222],ans,d[333333],beg[333333],en[333333],lazy[2222222],ct;
vector<pair<long long,long long> > g[333333];
void dfs(long long i,long long fa)
{
	beg[i]=++ct;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		dep[to]=dep[i]+w[to]-val;
		dfs(to,i);
	}
	en[i]=ct;
}
void build(long long l,long long r,long long node)
{
	if (l==r)
	{
		tree[node]=d[l];
		return;
	}
	long long mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	tree[node]=max(tree[node<<1],tree[(node<<1)|1]);
}
void pushdown(int node)
{
	if (lazy[node])
	{
		lazy[node<<1]+=lazy[node];lazy[(node<<1)|1]+=lazy[node];
		tree[node<<1]+=lazy[node];tree[(node<<1)|1]+=lazy[node];
		lazy[node]=0;
	}
}
void update(long long beg,long long en,long long l,long long r,long long node,long long x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		tree[node]+=x;
		lazy[node]+=x;
		return;
	}
	pushdown(node);
	long long mid=(l+r)>>1;
	update(beg,en,l,mid,node<<1,x);
	update(beg,en,mid+1,r,(node<<1)|1,x);
	tree[node]=max(tree[node<<1],tree[(node<<1)|1]);
}
void dft(long long i,long long fa)
{
	ans=max(ans,w[i]+tree[1]);
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		update(beg[to],en[to],1,n,1,val-w[to]);
		update(1,beg[to]-1,1,n,1,w[i]-val);
		update(en[to]+1,n,1,n,1,w[i]-val);
		dft(to,i);
		update(beg[to],en[to],1,n,1,w[to]-val);
		update(1,beg[to]-1,1,n,1,val-w[i]);
		update(en[to]+1,n,1,n,1,val-w[i]);
	}
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&w[i]);
	}
	for (long long i=1;i<n;i++)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));  
	}
	dfs(1,0);
	for (long long i=1;i<=n;i++) d[beg[i]]=dep[i];
	build(1,n,1);
	dft(1,0);
	printf("%I64d\n",ans);
	return 0;
}
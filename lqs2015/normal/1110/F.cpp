#include<bits/stdc++.h>
using namespace std;
long long n,q,en[555555],x,y,dep[555555],ans[555555],v,tree[2222222],sz,lazy[2222222];
vector<pair<long long,long long> > g[555555];
vector<pair<long long,pair<long long,long long> > > que[555555];
void dfs(long long i)
{
	en[i]=i;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		dep[to]=dep[i]+val;
		dfs(to);
		en[i]=max(en[i],en[to]);
	}
}
void push(long long node,long long x)
{
	tree[node]+=x;
	lazy[node]+=x;
}
void pushdown(long long node)
{
	if (lazy[node])
	{
		push(node<<1,lazy[node]);
		push((node<<1)|1,lazy[node]);
		lazy[node]=0;
	}
}
void update(long long beg,long long en,long long l,long long r,long long node,long long x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		push(node,x);
		return;
	}
	long long mid=(l+r)>>1;
	pushdown(node);
	update(beg,en,l,mid,node<<1,x);
	update(beg,en,mid+1,r,(node<<1)|1,x);
	tree[node]=min(tree[node<<1],tree[(node<<1)|1]);
}
long long query(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return 1e18;
	if (l>=beg && r<=en) return tree[node];
	pushdown(node);
	long long mid=(l+r)>>1;
	return min(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1));
}
void proc(long long i)
{
	for (long long j=0;j<que[i].size();j++)
	{
		ans[que[i][j].first]=query(que[i][j].second.first,que[i][j].second.second,1,sz,1);
	}
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		update(to,en[to],1,sz,1,-val);
		update(1,to-1,1,sz,1,val);update(en[to]+1,n,1,sz,1,val);
		proc(to);
		update(to,en[to],1,sz,1,val);
		update(1,to-1,1,sz,1,-val);update(en[to]+1,n,1,sz,1,-val);
	}
}
int main()
{
	scanf("%lld%lld",&n,&q);
	for (long long i=2;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		g[x].push_back(make_pair(i,y));
	}
	dfs(1);
	for (long long i=1;i<=q;i++)
	{
		scanf("%lld%lld%lld",&v,&x,&y);
		que[v].push_back(make_pair(i,make_pair(x,y))); 
	}
	sz=1;
	while(sz<n) sz*=2;
	for (long long i=1;i<=n;i++)
	{
		if (!g[i].size()) tree[sz-1+i]=dep[i];
		else tree[sz-1+i]=1e18;
	}
	for (long long i=n+1;i<=sz;i++) tree[sz-1+i]=1e18;
	for (long long i=sz-1;i>=1;i--) tree[i]=min(tree[i<<1],tree[(i<<1)|1]);
	proc(1);
	for (long long i=1;i<=q;i++)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}
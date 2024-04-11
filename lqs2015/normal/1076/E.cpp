#include<bits/stdc++.h>
using namespace std;
long long n,m,dep[333333],cnt,beg[333333],en[333333],x,y,z,tree[2222222],lazy[2222222],sz,pos,ans[333333];
vector<long long> g[333333];
vector<long long> d[2222222];
pair<pair<long long,long long>,pair<long long,long long> > que[333333];
void dfs(long long i,long long fa)
{
	beg[i]=++cnt;dep[i]=dep[fa]+1;
	d[dep[i]].push_back(i); 
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
	}
	en[i]=cnt;
}
void pushdown(long long node,long long s)
{
	if (lazy[node])
	{
		lazy[node*2]+=lazy[node];lazy[node*2+1]+=lazy[node];
		tree[node*2]+=lazy[node]*s;tree[node*2+1]+=lazy[node]*s;
		lazy[node]=0;
	}
}
void update(long long beg,long long en,long long l,long long r,long long node,long long x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		tree[node]+=(r-l+1)*x;
		lazy[node]+=x;
		return;
	}
	pushdown(node,(r-l+1)/2);
	long long mid=(l+r)/2;
	update(beg,en,l,mid,node*2,x);
	update(beg,en,mid+1,r,node*2+1,x);
	tree[node]=tree[node*2]+tree[node*2+1];
}
long long query(long long x,long long l,long long r,long long node)
{
	if (l==r) return tree[node];
	pushdown(node,(r-l+1)/2);
	long long mid=(l+r)/2;
	if (x>mid) return query(x,mid+1,r,node*2+1);
	return query(x,l,mid,node*2);
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	dfs(1,0);
	scanf("%I64d",&m);
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		que[i]=make_pair(make_pair(min(dep[x]+y,n),z),make_pair(beg[x],en[x]));
	}
	sort(que+1,que+m+1);
	sz=1;
	while(sz<n) sz*=2;
	pos=1;
	for (long long i=1;i<=m;i++)
	{
		while(pos<=n && pos<=que[i].first.first)
		{
			for (long long j=0;j<d[pos].size();j++)
			{
				x=query(beg[d[pos][j]],1,sz,1);
				update(beg[d[pos][j]],beg[d[pos][j]],1,sz,1,-x);
			}
			pos++;
		}
		update(que[i].second.first,que[i].second.second,1,sz,1,que[i].first.second);
	}
	while(pos<=n)
	{
		for (long long j=0;j<d[pos].size();j++)
		{
			x=query(beg[d[pos][j]],1,sz,1);
			update(beg[d[pos][j]],beg[d[pos][j]],1,sz,1,-x);
		}
		pos++;
	}
	for (long long i=1;i<=n;i++) ans[i]=query(i,1,sz,1);
	for (long long i=1;i<=n;i++) printf("%I64d ",ans[beg[i]]);
	return 0;
}
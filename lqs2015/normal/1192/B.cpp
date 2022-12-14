#include<bits/stdc++.h>
using namespace std;
int n,q,x[111111],y[111111],deep[111111],an[111111][22],beg[111111],en[111111],rbeg[111111],cnt,d;
long long w,dep[111111],dtree[444444],e,lans,del,W[111111];
vector<pair<int,long long> > g[111111];
struct treenode
{
	int a,b;
	long long dis;
	treenode()
	{
		dis=0;a=b=0;
	}
}tree[444444];
void dfs(int i,int fa)
{
	deep[i]=deep[fa]+1;
	an[i][0]=fa;beg[i]=++cnt;
	for (int j=1;j<=17;j++) an[i][j]=an[an[i][j-1]][j-1];
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;long long val=g[i][j].second;
		if (to==fa) continue;
		dep[to]=dep[i]+val;
		dfs(to,i);
	}
	en[i]=cnt;
}
void update(int beg,int en,int l,int r,int node,long long x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		dtree[node]+=x;
		return;
	}
	int mid=(l+r)>>1;
	update(beg,en,l,mid,node<<1,x);
	update(beg,en,mid+1,r,(node<<1)|1,x);
}
long long query(int x,int l,int r,int node)
{
	if (l==r) return dtree[node];
	int mid=(l+r)>>1;
	if (x>mid) return query(x,mid+1,r,(node<<1)|1)+dtree[node];
	return query(x,l,mid,node<<1)+dtree[node];
}
int lca(int x,int y)
{
	if (deep[x]<deep[y]) swap(x,y);
	for (int i=17;i>=0;i--)
	{
		if (deep[an[x][i]]>=deep[y]) x=an[x][i];
	}
	if (x==y) return x;
	for (int i=17;i>=0;i--)
	{
		if (an[x][i]!=an[y][i])
		{
			x=an[x][i];
			y=an[y][i];
		}
	}
	return an[x][0];
}
long long dist(int x,int y)
{
	return query(beg[x],1,n,1)+query(beg[y],1,n,1)-query(beg[lca(x,y)],1,n,1)*2;
}
void updt(int node,int x,int y,long long xx,long long yy)
{
	long long d=xx+yy-query(beg[lca(x,y)],1,n,1)*2;
	if (d>tree[node].dis)
	{
		tree[node].dis=d;
		tree[node].a=x;tree[node].b=y;
	}
}
void pushup(int node)
{
	tree[node].dis=-1e18;
	long long da=query(beg[tree[node<<1].a],1,n,1),db=query(beg[tree[node<<1].b],1,n,1),daa=query(beg[tree[(node<<1)|1].a],1,n,1),dbb=query(beg[tree[(node<<1)|1].b],1,n,1);
	updt(node,tree[node<<1].a,tree[node<<1].b,da,db);
	updt(node,tree[(node<<1)|1].a,tree[(node<<1)|1].b,daa,dbb);
	updt(node,tree[node<<1].a,tree[(node<<1)|1].a,da,daa);
	updt(node,tree[node<<1].a,tree[(node<<1)|1].b,da,dbb);
	updt(node,tree[node<<1].b,tree[(node<<1)|1].a,db,daa);
	updt(node,tree[node<<1].b,tree[(node<<1)|1].b,db,dbb);
}
void build(int l,int r,int node)
{
	if (l==r)
	{
		dtree[node]=dep[rbeg[l]];
		tree[node].a=tree[node].b=rbeg[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	pushup(node);
}
void upd(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) return;
	int mid=(l+r)>>1;
	upd(beg,en,l,mid,node<<1);
	upd(beg,en,mid+1,r,(node<<1)|1);
	pushup(node);
}
int main()
{
	scanf("%d%d",&n,&q);
	scanf("%lld",&w);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%lld",&x[i],&y[i],&W[i]);
		g[x[i]].push_back(make_pair(y[i],W[i]));
		g[y[i]].push_back(make_pair(x[i],W[i]));
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) rbeg[beg[i]]=i;
	for (int i=1;i<n;i++)
	{
		if (an[y[i]][0]==x[i]) swap(x[i],y[i]);
	}
	build(1,n,1);
	while(q--)
	{
		scanf("%d%lld",&d,&e);
		d=(lans+d)%(n-1)+1;
		e=(e+lans)%w;
		del=e-W[d];
		W[d]=e;
		update(beg[x[d]],en[x[d]],1,n,1,del);
		upd(beg[x[d]],en[x[d]],1,n,1);
		printf("%lld\n",lans=tree[1].dis);
	}
	return 0;
}
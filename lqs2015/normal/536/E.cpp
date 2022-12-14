#include<bits/stdc++.h>
using namespace std;
int n,q,f[111111],beg[111111],dep[111111],ct,cnt,head[111111],fa[111111],fal[111111],pos[111111],x,y,z,sub[111111],wson[111111],ans[111111],fg;
vector<pair<int,int> > g[111111];
pair<int,int> edge[111111];
struct query
{
	int u,v,w,id;
	bool operator < (const query &u) const
	{
		return w>u.w;
	}
}que[111111];
struct segtree
{
	int ls,rs,sum,len;
	void Init()
	{
		ls=rs=sum=len=0;
	}
}tree[888888];
void merge(segtree &x,segtree l,segtree r)
{
	if (l.ls==l.len) x.ls=l.ls+r.ls;
	else x.ls=l.ls;
	if (r.rs==r.len) x.rs=r.rs+l.rs;
	else x.rs=r.rs;
	x.sum=l.sum+r.sum;
	if (l.rs!=l.len && r.ls!=r.len) x.sum+=f[l.rs+r.ls];
	x.len=l.len+r.len;
}
void build(int l,int r,int node)
{
	tree[node].ls=tree[node].rs=tree[node].sum=0;
	tree[node].len=r-l+1;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
}
void pushup(int node)
{
	merge(tree[node],tree[node<<1],tree[(node<<1)|1]);
}
void update(int x,int l,int r,int node)
{
	if (l==r)
	{
		tree[node].ls=tree[node].rs=1;tree[node].sum=0;
		return;
	}
	int mid=(l+r)>>1;
	if (x>mid) update(x,mid+1,r,(node<<1)|1);
	else update(x,l,mid,node<<1);
	pushup(node);
}
segtree qry(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return (segtree){0,0,0,0};
	if (l>=beg && r<=en) 
	{
		return tree[node];
	}
	int mid=(l+r)>>1;
	segtree a,b,c;
	a=qry(beg,en,l,mid,node<<1);b=qry(beg,en,mid+1,r,(node<<1)|1);
	merge(c,a,b);
	return c;
}
int lca(int u,int v)
{
	while(pos[u]!=pos[v])
	{
		if (dep[head[pos[u]]]>dep[head[pos[v]]]) u=fa[head[pos[u]]];
		else v=fa[head[pos[v]]];
	}
	if (dep[u]>dep[v]) return v;
	return u;
}
int query(int u,int v)
{
	segtree a,b;
	a.Init();b.Init();
	while(pos[u]!=pos[v])
	{
		if (dep[head[pos[u]]]>dep[head[pos[v]]])
		{
			merge(a,qry(beg[head[pos[u]]],beg[u],1,n,1),a);
			u=fa[head[pos[u]]];
		}
		else
		{
			merge(b,qry(beg[head[pos[v]]],beg[v],1,n,1),b);
			v=fa[head[pos[v]]];
		}
	}
	if (dep[u]>dep[v])
	{
		merge(a,qry(beg[v]+1,beg[u],1,n,1),a);
	}
	else
	{
		merge(b,qry(beg[u]+1,beg[v],1,n,1),b);
	}
	int res=0;
	if (a.ls==a.len && b.ls==b.len) return f[a.len+b.len];
	if (a.ls==a.len) return f[a.len+b.ls]+b.sum+f[b.rs];
	if (b.ls==b.len) return f[b.len+a.ls]+a.sum+f[a.rs];
	return f[a.ls+b.ls]+a.sum+b.sum+f[a.rs]+f[b.rs];
}
void Init(int i,int f)
{
	fa[i]=f;sub[i]=1;dep[i]=dep[f]+1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (to==f) continue;
		fal[to]=val;
		Init(to,i);
		sub[i]+=sub[to];
		if (sub[wson[i]]<sub[to]) wson[i]=to;
	}
}
void dfs(int i,int fa)
{
	beg[i]=++ct;pos[i]=cnt;
	if (wson[i]) dfs(wson[i],i);
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;
		if (to==fa || to==wson[i]) continue;
		head[++cnt]=to;dfs(to,i);
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i++) scanf("%d",&f[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));  
	}
	Init(1,0);
	for (int i=2;i<=n;i++) edge[i-1]=make_pair(fal[i],i);
	sort(edge+1,edge+n);
	reverse(edge+1,edge+n);
	cnt=1;head[1]=1;
	dfs(1,0);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&que[i].u,&que[i].v,&que[i].w);
		que[i].id=i;
	}
	sort(que+1,que+q+1);
	build(1,n,1);
	fg=1;
	for (int i=1;i<=q;i++)
	{
		while(fg<n && edge[fg].first>=que[i].w)
		{
			update(beg[edge[fg].second],1,n,1);
			fg++;
		}
		ans[que[i].id]=query(que[i].u,que[i].v);
	}
	for (int i=1;i<=q;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
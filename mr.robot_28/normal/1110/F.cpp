#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<ll,ll>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const ll INF=4611686018427387904,N=5e5+5;
struct node{
	ll delta,mv;
	int l,r;
}tree[4*N];
vector<pii> v[N];
inline ll ls(ll x)
{
    return x<<1;
}
inline ll rs(ll x)
{
    return x<<1|1;
}
void pushup(int x)
{
	tree[x].mv=min(tree[ls(x)].mv+tree[ls(x)].delta,tree[rs(x)].mv+tree[rs(x)].delta);
}
void build(int x,int l,int r)
{
	tree[x].delta=0;tree[x].l=l;tree[x].r=r;tree[x].mv=0;
	int mid=(l+r)/2;
	if(l!=r)
	{
		build(ls(x),l,mid);
		build(rs(x),mid+1,r);	
		pushup(x);	
	}
	else {
		if(v[l].size())
			tree[x].delta=INF;
		else 
			tree[x].delta=0;
	}
}
void update(int x,int l,int r,ll num)
{
	if(l>r) return;
	if(tree[x].l>=l&&tree[x].r<=r)
	{
		tree[x].delta+=num;
	}
	else
	{
		tree[ls(x)].delta+=tree[x].delta;
		tree[rs(x)].delta+=tree[x].delta;
		tree[x].delta=0;
		if(l<=tree[ls(x)].r) update(ls(x),l,r,num);
		if(r>=tree[rs(x)].l) update(rs(x),l,r,num);
		pushup(x);
	}
	
}
ll query(int x,int l,int r)
{
	ll s=INF;
	if(tree[x].l>=l&&tree[x].r<=r)
	{
		return tree[x].mv+tree[x].delta;
	}
	else
	{
		tree[ls(x)].delta+=tree[x].delta;
		tree[rs(x)].delta+=tree[x].delta;
		tree[x].delta=0;
		if(l<=tree[ls(x)].r) s=min(s,query(ls(x),l,r));
		if(r>=tree[rs(x)].l) s=min(s,query(rs(x),l,r));
		pushup(x);
		return s;
	}
	
}
int n,q;
int fa[N];
ll dfn[N],low[N],num;
struct node1{
	int x,l,r,index;
	ll ans;
};
vector<node1> qu[N];
vector<node1> an;
bool cmp(node1 x,node1 y)
{
	return x.index<y.index;
}
void dfs1(int x)
{
	dfn[x]=low[x]=++num;
	for(int i=0;i<v[x].size();i++)
	{
		int u=v[x][i].fi;
		if(!dfn[u])
		{
			dfs1(u);
			low[x]=max(low[x],low[u]);
		}
	}
}
void dfs2(int x)
{
	for(int i=0;i<v[x].size();i++)
	{
		int u=v[x][i].fi;
		if(u==fa[x]) continue;
		dfs2(u);
//		cout<<dfn[u]<<" "<<low[u]<<" "<<v[x][i].se<<endl;
		update(1,dfn[u],low[u],v[x][i].se);
	}
}
void dfs3(int x)
{
	int i;
	for(i=0;i<qu[x].size();i++)
	{
		int l=qu[x][i].l,r=qu[x][i].r;
		qu[x][i].ans=query(1,l,r);
	}
	for(i=0;i<v[x].size();i++)
	{
		int u=v[x][i].fi;
		if(u==fa[x]) continue;
		update(1,dfn[u],low[u],-v[x][i].se);
		update(1,1,dfn[u]-1,v[x][i].se);
		update(1,low[u]+1,n,v[x][i].se);
		dfs3(u);
		update(1,dfn[u],low[u],v[x][i].se);
		update(1,1,dfn[u]-1,-v[x][i].se);
		update(1,low[u]+1,n,-v[x][i].se);
	}
}
int main()
{
	int i;
	cin>>n>>q;
	for(i=2;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(mp(i,y));fa[i]=x;
	}
	dfs1(1);
	build(1,1,n);
	dfs2(1);
	
	for(i=1;i<=q;i++)
	{
		ll x,l,r;
		scanf("%lld%lld%lld",&x,&l,&r);
		node1 tmp;
		tmp.x=x;tmp.l=l;tmp.r=r;tmp.index=i;
		qu[x].pb(tmp);
	}
	dfs3(1);
	
	for(i=1;i<=n;i++)
	{
		for(int j=0;j<qu[i].size();j++)
			an.pb(qu[i][j]);
	}
	sort(an.begin(),an.end(),cmp);
	for(i=0;i<an.size();i++)
	{
		printf("%lld\n",an[i].ans);
	}
}
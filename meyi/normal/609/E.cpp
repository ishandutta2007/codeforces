#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
struct edge{
	int fr,to,v;
	bool mst;
}e[maxn];
int id[maxn],m,n;
struct dsu{
	int fa[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
}d;
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>g[maxn];
int a[maxn],cnt,dep[maxn],fa[maxn],rev[maxn],seg[maxn],siz[maxn],son[maxn],top[maxn];
void dfs1(int p,int f){
	dep[p]=dep[f]+1;
	fa[p]=f;
	siz[p]=1;
	for(auto i:g[p])
		if(i.fi!=f){
			a[i.fi]=i.se;
			dfs1(i.fi,p);
			siz[p]+=siz[i.fi];
			if(siz[i.fi]>siz[son[p]])son[p]=i.fi;
		}
}
void dfs2(int p,int k){
	seg[p]=++cnt;
	rev[cnt]=p;
	top[p]=k;
	if(son[p]){
		dfs2(son[p],k);
		for(auto i:g[p])
			if(!top[i.fi])
				dfs2(i.fi,i.fi);
	}
}
struct SGT{
	int l,r,mx;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].mx=max(t[ls(p)].mx,t[rs(p)].mx);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].mx=a[rev[l]];
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline int query(int p,int l,int r){
	if(l>t[p].r||t[p].l>r)return 0;
	if(l<=t[p].l&&t[p].r<=r)return t[p].mx;
	return max(query(ls(p),l,r),query(rs(p),l,r));
}
inline int query_chain(int x,int y){
	ri ret=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ckmax(ret,query(1,seg[top[x]],seg[x]));
		x=fa[top[x]];
	}
	if(x!=y){
		if(dep[x]>dep[y])swap(x,y);
		ckmax(ret,query(1,seg[x]+1,seg[y]));
	}
	return ret;
}
ll ans;
signed main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=m;++i){
		scanf("%d%d%d",&e[i].fr,&e[i].to,&e[i].v);
		id[i]=i;
	}
	sort(id+1,id+m+1,[&](const int &x,const int &y){return e[x].v<e[y].v;});
	d.init(n);
	for(ri i=1;i<=m;++i){
		ri u=e[id[i]].fr,v=e[id[i]].to,w=e[id[i]].v,x=d.find(u),y=d.find(v);
		if(x!=y){
			ans+=w;
			d.fa[x]=y;
			e[id[i]].mst=true;
			g[u].emplace_back(v,w);
			g[v].emplace_back(u,w);
		}
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,cnt);
	for(ri i=1;i<=m;++i)
		if(e[i].mst)printf("%lld\n",ans);
		else printf("%lld\n",ans-query_chain(e[i].fr,e[i].to)+e[i].v);
	return 0;
}
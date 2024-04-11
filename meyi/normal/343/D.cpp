#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int cnt,dep[maxn],fa[maxn],rev[maxn],seg[maxn],siz[maxn],son[maxn],top[maxn];
void dfs1(int p,int f){
	dep[p]=dep[f]+1;
	fa[p]=f;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs1(e[i].to,p);
			siz[p]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
		}
}
void dfs2(int p,int k){
	seg[p]=++cnt;
	rev[cnt]=p;
	top[p]=k;
	if(son[p]){
		dfs2(son[p],k);
		for(ri i=hd[p];i;i=e[i].nxt)
			if(!top[e[i].to])
				dfs2(e[i].to,e[i].to);
	}
}
struct segment_tree{
	int l,r,v,tag;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].tag=-1;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
inline void add_tag(int p,int v){
	t[p].v=t[p].tag=v;
}
inline void push_down(int p){
	if(t[p].tag==-1)return;
	add_tag(ls(p),t[p].tag);
	add_tag(rs(p),t[p].tag);
	t[p].tag=-1;
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
void modify(int p,int l,int r,int v){
	if(no_intersection)return;
	if(is_subset){
		add_tag(p,v);
		return;
	}
	push_down(p);
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
}
inline void modify_chain(int x,int y,int v){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		modify(1,seg[top[x]],seg[x],v);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	modify(1,seg[x],seg[y],v);
}
inline int query(int p,int l,int r){
	if(no_intersection)return 0;
	if(is_subset)return t[p].v;
	push_down(p);
	return query(ls(p),l,r)+query(rs(p),l,r);
}
int m,n;
signed main(){
	scanf("%d",&n);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	scanf("%d",&m);
	while(m--){
		ri op,x;
		scanf("%d%d",&op,&x);
		if(op==1)modify(1,seg[x],seg[x]+siz[x]-1,1);
		else if(op==2)modify_chain(1,x,0);
		else printf("%d\n",query(1,seg[x],seg[x]));
	}
	return 0;
}
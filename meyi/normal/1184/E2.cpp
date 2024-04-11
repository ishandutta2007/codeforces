#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int inf=1e9,maxn=1e5+10,maxm=1e6+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;register char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
struct edge{
	int fr,to,v;
	bool mst;
}e[maxm];
int id[maxm],m,n;
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
	int l,r,mn,mx,tag;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].mx=max(t[ls(p)].mx,t[rs(p)].mx);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].mn=t[p].tag=inf;
	if(l==r){
		t[p].mx=a[rev[l]];
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline int query_mx(int p,int l,int r){
	if(l>t[p].r||t[p].l>r)return 0;
	if(l<=t[p].l&&t[p].r<=r)return t[p].mx;
	return max(query_mx(ls(p),l,r),query_mx(rs(p),l,r));
}
inline int query_chain(int x,int y){
	ri ret=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ckmax(ret,query_mx(1,seg[top[x]],seg[x]));
		x=fa[top[x]];
	}
	if(x!=y){
		if(dep[x]>dep[y])swap(x,y);
		ckmax(ret,query_mx(1,seg[x]+1,seg[y]));
	}
	return ret;
}
inline void add_tag(int p,int v){
	ckmin(t[p].mn,v);
	ckmin(t[p].tag,v);
}
inline void push_down(int p){
	if(t[p].tag==inf)return;
	add_tag(ls(p),t[p].tag);
	add_tag(rs(p),t[p].tag);
	t[p].tag=inf;
}
inline void modify(int p,int l,int r,int v){
	if(l>t[p].r||t[p].l>r)return;
	if(l<=t[p].l&&t[p].r<=r){
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
	if(x!=y){
		if(dep[x]>dep[y])swap(x,y);
		modify(1,seg[x]+1,seg[y],v);
	}
}
inline int query_mn(int p,int k){
	if(t[p].l>k||k>t[p].r)return 0;
	if(t[p].l==t[p].r)return t[p].mn;
	push_down(p);
	return query_mn(ls(p),k)+query_mn(rs(p),k);
}
int ans[maxm];
int main(){
	n=qr(),m=qr();
	for(ri i=1;i<=m;++i){
		e[i].fr=qr(),e[i].to=qr(),e[i].v=qr();
		id[i]=i;
	}
	sort(id+1,id+m+1,[&](const int &x,const int &y){return e[x].v<e[y].v;});
	d.init(n);
	for(ri i=1;i<=m;++i){
		ri u=e[id[i]].fr,v=e[id[i]].to,w=e[id[i]].v,x=d.find(u),y=d.find(v);
		if(x!=y){
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
		if(!e[i].mst)
			qw(query_chain(e[i].fr,e[i].to)),putchar(10);
	return 0;
}
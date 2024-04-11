#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;char ch;
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
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int dep[maxn],dfn,fa[maxn],rev[maxn],seg[maxn],siz[maxn],son[maxn],top[maxn];
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
	seg[p]=++dfn;
	rev[dfn]=p;
	top[p]=k;
	if(son[p]){
		dfs2(son[p],k);
		for(ri i=hd[p];i;i=e[i].nxt)
			if(!top[e[i].to])
				dfs2(e[i].to,e[i].to);
	}
}
int lim=10;
typedef vector<int> vi;
inline vi merge(const vi &x,const vi &y){
	vi z(x.size()+y.size());
	merge(x.begin(),x.end(),y.begin(),y.end(),z.begin());
	if(z.size()>lim)z.erase(z.begin()+lim,z.end());
	return z;
};
struct segment_tree{
	int l,r;
	vi v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].v=merge(t[ls(p)].v,t[rs(p)].v);
}
vi v[maxn];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].v=v[rev[l]];
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subseg (l<=t[p].l&&t[p].r<=r)
vi query(int p,int l,int r){
	if(no_intersection)return vi();
	if(is_subseg)return t[p].v;
	return merge(query(ls(p),l,r),query(rs(p),l,r));
}
inline vi query_chain(int x,int y){
	vi ret;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ret=merge(ret,query(1,seg[top[x]],seg[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return merge(ret,query(1,seg[x],seg[y]));
}
int m,n,q;
int main(){
	n=qr(),m=qr(),q=qr();
	for(ri i=1;i<n;++i){
		ri x=qr(),y=qr();
		addedge(x,y),addedge(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(ri i=1;i<=m;++i){
		ri x=qr();
		if(v[x].size()<lim)v[x].push_back(i);
	}
	build(1,1,n);
	while(q--){
		ri x=qr(),y=qr();lim=qr();
		vi ans=query_chain(x,y);
		qw(ans.size());
		for(ri i:ans)putchar(32),qw(i);
		putchar(10);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=6e5+9;
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
namespace LCA{
	int cnt,dep[maxn],fir[maxn],lg,lg2[maxn<<1],st[(int)log2(maxn)+2][maxn<<1];
	void dfs(int p,int f){
		dep[p]=dep[f]+1;
		st[0][++cnt]=p;
		fir[p]=cnt;
		for(ri i=hd[p];i;i=e[i].nxt)
			if(e[i].to!=f)
				dfs(e[i].to,p),st[0][++cnt]=p;
	}
	inline int ptmin(const int &x,const int &y){
		return dep[x]<dep[y]?x:y;
	}
	inline void build_st(){
		for(ri i=1;i<=cnt;++i)lg2[i]=lg2[i-1]+((2<<lg2[i-1])==i);
		lg=lg2[cnt];
		for(ri i=1;i<=lg;++i)
			for(ri j=1;j+(1<<i)-1<=cnt;++j)
				st[i][j]=ptmin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	inline int lca(int x,int y){
		if(!x||!y)return x+y;
		ri l=fir[x],r=fir[y];
		if(l>r)swap(l,r);
		ri k=lg2[r-l+1];
		return ptmin(st[k][l],st[k][r-(1<<k)+1]);
	}
	inline void init(int rt){
		dfs(rt,0);
		build_st();
	}
}
using LCA::lca;
struct dsu{
	int fa[maxn],siz[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y,siz[y]+=siz[x];
		}
	}
}d;
struct segment_tree{
	int l,r;
	int any,cur,lca,tag;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].any=max(t[ls(p)].any,t[rs(p)].any);
	t[p].cur=lca(t[ls(p)].cur,t[rs(p)].cur);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].tag=-1;
	if(l==r){
		t[p].lca=l;
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	t[p].lca=lca(t[ls(p)].lca,t[rs(p)].lca);
}
inline void add_tag(int p,int v){
	if(v)t[p].any=t[p].l,t[p].cur=t[p].lca;
	else t[p].any=t[p].cur=0;
	t[p].tag=v;
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
	push_up(p);
}
int id[maxn],n,rt,q,tot,val[maxn],x[maxn],y[maxn],z[maxn];
int main(){
	n=qr(),q=qr();
	for(ri i=1;i<n;++i){
		x[i]=qr(),y[i]=qr(),z[i]=qr();
		id[i]=i;
	}
	rt=(n<<1)-1;
	d.init(rt);
	sort(id+1,id+n,[&](int x,int y){return z[x]<z[y];});
	tot=n;
	for(ri ii=1;ii<n;++ii){
		ri i=id[ii],fx=d.find(x[i]),fy=d.find(y[i]);
		val[++tot]=z[i];
		d.fa[fx]=d.fa[fy]=tot;
		addedge(tot,fx),addedge(tot,fy);
	}
	LCA::init(rt);
	build(1,1,n);
	while(q--){
		ri op=qr(),x=qr();
		if(op<3)modify(1,x,qr(),op&1);
		else{
			if(t[1].cur==x||!t[1].any)putchar('-'),putchar(49);
			else qw(val[lca(x,t[1].cur)]);
			putchar(10);
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
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
	inline int lca(int l,int r){
		ri k=lg2[r-l+1];
		return ptmin(st[k][l],st[k][r-(1<<k)+1]);
	}
	inline void init(int rt){
		cnt=0;
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
struct node{
	int mn,mx;
	inline node operator+(const node &k)const{return {min(mn,k.mn),max(mx,k.mx)};}
};
struct segment_tree{
	int l,r;
	node v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].v=t[ls(p)].v+t[rs(p)].v;
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].v={LCA::fir[l],LCA::fir[r]};
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subseg (l<=t[p].l&&t[p].r<=r)
node query(int p,int l,int r){
	if(no_intersection)return {INT_MAX,INT_MIN};
	if(is_subseg)return t[p].v;
	return query(ls(p),l,r)+query(rs(p),l,r);
}
int m,n,rt,q,t_case,tot,val[maxn],x[maxn],y[maxn];
int main(){
	t_case=qr();
	while(t_case--){
		n=qr(),m=qr(),q=qr();
		ri rt=(n<<1)-1,tot=n;
		clear(hd,rt),len=0,clear(val,rt);
		d.init(rt);
		for(ri i=1;i<=m;++i){
			x[i]=qr(),y[i]=qr();
			ri fx=d.find(x[i]),fy=d.find(y[i]);
			if(fx!=fy){
				val[++tot]=i;
				d.fa[fx]=d.fa[fy]=tot;
				addedge(tot,fx),addedge(tot,fy);
			}
		}
		LCA::init(rt);
		build(1,1,n);
		while(q--){
			ri l=qr(),r=qr();
			node tmp=query(1,l,r);
			qw(val[lca(tmp.mn,tmp.mx)]),putchar(32);
		}
		putchar(10);
	}
	return 0;
}
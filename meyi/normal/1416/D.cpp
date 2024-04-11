#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
struct dsu{
	int fa[maxn];
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
}d;
int a[maxn],cnt,id[maxn],m,n,op[maxn],pos[maxn],val[maxn],x[maxn],y[maxn],z[maxn];
inline void kruskal(){
	for(ri i=1;i<(n<<1);++i)d.fa[i]=i;
	sort(id+1,id+m+1,[&](int x,int y){return z[x]>z[y];});
	cnt=n;
	for(ri ii=1;ii<=m;++ii){
		ri i=id[ii],fx=d.find(x[i]),fy=d.find(y[i]);
		if(fx!=fy){
			d.fa[fx]=d.fa[fy]=++cnt;
			addedge(cnt,fx),addedge(cnt,fy);
			val[cnt]=z[i];
		}
	}
}
int dfn[maxn],fa[maxn][19],lg,rev[maxn],siz[maxn],tot;
void dfs(int p,int f){
	dfn[p]=++tot;
	fa[p][0]=f;
	for(ri i=1;i<=lg;++i)fa[p][i]=fa[fa[p][i-1]][i-1];
	rev[tot]=p;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f)
			dfs(e[i].to,p),siz[p]+=siz[e[i].to];
}
struct segment_tree{
    int l,r,v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline int ptmax(int x,int y){return a[x]>a[y]?x:y;}
inline void push_up(int p){
	t[p].v=ptmax(t[ls(p)].v,t[rs(p)].v);
}
void build(int p,int l,int r){
    t[p].l=l,t[p].r=r;
    if(l==r){
		t[p].v=rev[l];
        return;
    }
    ri mid=l+r>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    push_up(p);
}
void modify(int p,int k){
    if(t[p].l>k||k>t[p].r||t[p].l==t[p].r)return;
    modify(ls(p),k);
    modify(rs(p),k);
    push_up(p);
}
inline int query(int p,int l,int r){
    if(l>t[p].r||t[p].l>r)return 0;
    if(l<=t[p].l&&t[p].r<=r)return t[p].v;
    return ptmax(query(ls(p),l,r),query(rs(p),l,r));
}
int q;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1;i<=m;++i)id[i]=i,scanf("%d%d",x+i,y+i),z[i]=q+1;
	for(ri i=1;i<=q;++i){
		scanf("%d%d",op+i,pos+i);
		if(op[i]==2)z[pos[i]]=i;
	}
	kruskal();
	lg=__lg(cnt);
	for(ri i=1;i<=cnt;++i)
		if(!siz[i])
			dfs(d.find(i),0);
	a[0]=-1;
	build(1,1,cnt);
	for(ri i=1;i<=q;++i)
		if(op[i]&1){
			for(ri j=lg;~j;--j)
				if(val[fa[pos[i]][j]]>i)
					pos[i]=fa[pos[i]][j];
			ri ans=query(1,dfn[pos[i]],dfn[pos[i]]+siz[pos[i]]-1);
			printf("%d\n",a[ans]);
			a[ans]=0;
			modify(1,dfn[ans]);
		}
	return 0;
}
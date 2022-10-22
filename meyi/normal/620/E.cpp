#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=4e5+10;
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
int cnt,rev[maxn],seg[maxn],siz[maxn];
void dfs(int p,int f){
	seg[p]=++cnt;
	rev[cnt]=p;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs(e[i].to,p);
			siz[p]+=siz[e[i].to];
		}
}
struct segment_tree{
	int l,r;
	ll v,tag;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].v=t[ls(p)].v|t[rs(p)].v;
}
ll a[maxn];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].v=a[rev[l]];
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline void add_tag(int p,ll v){
	t[p].v=t[p].tag=v;
}
inline void push_down(int p){
	if(!t[p].tag)return;
	add_tag(ls(p),t[p].tag);
	add_tag(rs(p),t[p].tag);
	t[p].tag=0;
}
void modify(int p,int l,int r,ll v){
	if(t[p].l>r||l>t[p].r)return;
	if(l<=t[p].l&&t[p].r<=r){
		add_tag(p,v);
		return;
	}
	push_down(p);
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
	push_up(p);
}
ll query(int p,int l,int r){
	if(t[p].l>r||l>t[p].r)return 0;
	if(l<=t[p].l&&t[p].r<=r)return t[p].v;
	push_down(p);
	return query(ls(p),l,r)|query(rs(p),l,r);
}
int m,n;
signed main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i){
		scanf("%lld",a+i);
		a[i]=1ll<<(a[i]-1);
	}
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs(1,0);
	build(1,1,cnt);
	while(m--){
		ri op,x;
		scanf("%d%d",&op,&x);
		if(op&1){
			ll y;
			scanf("%lld",&y);
			y=1ll<<(y-1);
			modify(1,seg[x],seg[x]+siz[x]-1,y);
		}
		else printf("%d\n",__builtin_popcountll(query(1,seg[x],seg[x]+siz[x]-1)));
	}
	return 0;
}
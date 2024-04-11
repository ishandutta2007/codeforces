#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
struct node{int id,x,y;}st[maxn<<1];
int tp;
struct undo_dfs{
	int fa[maxn<<1],id,siz[maxn<<1];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;}
	int find(int k){return k==fa[k]?k:find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y,siz[y]+=siz[x];
			st[++tp]={id,x,y};
		}
	}
	inline void undo(int x,int y){fa[x]=x,siz[y]-=siz[x];}
}d[51];
int k,m,n;
struct segment_tree{
	int l,r;
	vector<int>v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
void modify(int p,int l,int r,int v){
	if(t[p].l>r||l>t[p].r)return;
	if(l<=t[p].l&&t[p].r<=r){
		t[p].v.push_back(v);
		return;
	}
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
}
int c[maxn],e[maxn],lst[maxn],x[maxn],y[maxn];
void solve(int p){
	ri tmp=tp;
	for(ri i:t[p].v)
		if(c[i])
			d[c[i]].merge(x[e[i]],y[e[i]]+n),d[c[i]].merge(x[e[i]]+n,y[e[i]]);
	if(t[p].l==t[p].r){
		if(d[c[t[p].l]].find(x[e[t[p].l]])==d[c[t[p].l]].find(y[e[t[p].l]]))puts("NO"),c[t[p].l]=lst[e[t[p].l]];
		else puts("YES"),lst[e[t[p].l]]=c[t[p].l];
	}
	else solve(ls(p)),solve(rs(p));
	while(tp>tmp)d[st[tp].id].undo(st[tp].x,st[tp].y),--tp;
}
int q;
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(ri i=1;i<=k;++i)d[i].id=i,d[i].init(n<<1);
	build(1,1,q);
	for(ri i=1;i<=m;++i)scanf("%d%d",x+i,y+i);
	for(ri i=1;i<=q;++i){
		scanf("%d%d",e+i,c+i);
		if(lst[e[i]])modify(1,lst[e[i]]+1,i-1,lst[e[i]]);
		lst[e[i]]=i;
	}
	for(ri i=1;i<=m;++i){
		if(lst[i])modify(1,lst[i]+1,q,lst[i]);
		lst[i]=0;
	}
	solve(1);
	return 0;
}
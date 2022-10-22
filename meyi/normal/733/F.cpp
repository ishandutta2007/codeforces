#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
struct edge{
	int fr,to,v,c;
	bool mst;
}e[maxn];
int id[maxn],m,n;
struct dsu{
	int fa[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
}d;
struct node{int fi,se,th;};
vector<node>g[maxn];
int a[maxn],cnt,dep[maxn],ed[maxn],fa[maxn],rev[maxn],seg[maxn],siz[maxn],son[maxn],top[maxn];
void dfs1(int p,int f){
	dep[p]=dep[f]+1;
	fa[p]=f;
	siz[p]=1;
	for(auto i:g[p])
		if(i.fi!=f){
			a[i.fi]=i.se;
			ed[i.fi]=i.th;
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
typedef pair<int,int> pii;
#define fi first
#define se second
struct SGT{
	int l,r;
	pii mx;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].mx=max(t[ls(p)].mx,t[rs(p)].mx);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].mx={a[rev[l]],rev[l]};
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline pii query(int p,int l,int r){
	if(l>t[p].r||t[p].l>r)return {0,0};
	if(l<=t[p].l&&t[p].r<=r)return t[p].mx;
	return max(query(ls(p),l,r),query(rs(p),l,r));
}
inline pii query_chain(int x,int y){
	pii ret={0,0};
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
ll ans1=LLONG_MAX,sum;
int ans2,ans3,s;
signed main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=m;++i)scanf("%d",&e[i].v);
	for(ri i=1;i<=m;++i)scanf("%d",&e[i].c);
	for(ri i=1;i<=m;++i){
		scanf("%d%d",&e[i].fr,&e[i].to);
		id[i]=i;
	}
	sort(id+1,id+m+1,[&](const int &x,const int &y){return e[x].v<e[y].v;});
	d.init(n);
	for(ri i=1;i<=m;++i){
		ri u=e[id[i]].fr,v=e[id[i]].to,w=e[id[i]].v,x=d.find(u),y=d.find(v);
		if(x!=y){
			sum+=w;
			d.fa[x]=y;
			e[id[i]].mst=true;
			g[u].push_back({v,w,id[i]});
			g[v].push_back({u,w,id[i]});
		}
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,cnt);
	scanf("%d",&s);
	for(ri i=1;i<=m;++i)
		if(e[i].mst){
			ll tmp=sum-s/e[i].c;
			if(tmp<ans1){
				ans1=tmp;
				ans2=i;
				ans3=0;
			}
		}
		else{
			pii tmp1=query_chain(e[i].fr,e[i].to);
			ll tmp2=sum-tmp1.fi+e[i].v-s/e[i].c;
			if(tmp2<ans1){
				ans1=tmp2;
				ans2=i;
				ans3=ed[tmp1.se];
			}
		}
	printf("%lld\n",ans1);
	for(ri i=1;i<=m;++i){
		if(ans2==i)printf("%d %d\n",i,e[i].v-s/e[i].c);
		else if(e[i].mst&&ans3!=i)printf("%d %d\n",i,e[i].v);
	}
	return 0;
}
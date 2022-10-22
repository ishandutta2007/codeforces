#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
int m,n;
namespace tree{
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
		int l,r,v1,v2,tag1,tag2;
	}t[maxn<<2];
	#define ls(p) (p<<1)
	#define rs(p) (p<<1|1)
	inline void push_up(int p){
		t[p].v1=max(t[ls(p)].v1,t[rs(p)].v1);
		t[p].v2=t[ls(p)].v2^t[rs(p)].v2;
	}
	inline void add_tag(int p,int v1,int v2){
		t[p].v1+=v1;
		t[p].v2^=(((t[p].r-t[p].l)&1)?0:v2);
		t[p].tag1+=v1;
		t[p].tag2^=v2;
	}
	inline void push_down(int p){
		if(!t[p].tag1&&!t[p].tag2)return;
		add_tag(ls(p),t[p].tag1,t[p].tag2);
		add_tag(rs(p),t[p].tag1,t[p].tag2);
		t[p].tag1=t[p].tag2=0;
	}
	void build(int p,int l,int r){
		t[p].l=l,t[p].r=r;
		if(l==r)return;
		int mid=l+r>>1;
		build(ls(p),l,mid);
		build(rs(p),mid+1,r);
	}
	void modify(int p,int l,int r,int v){
		if(t[p].l>r||l>t[p].r)return;
		if(l<=t[p].l&&t[p].r<=r){
			add_tag(p,1,v);
			return;
		}
		push_down(p);
		modify(ls(p),l,r,v);
		modify(rs(p),l,r,v);
		push_up(p);
	}
	inline void modify_chain(int x,int y,int v){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			modify(1,seg[top[x]],seg[x],v);
			x=fa[top[x]];
		}
		if(x==y)return;
		if(dep[x]>dep[y])swap(x,y);
		modify(1,seg[x]+1,seg[y],v);
	}
	typedef pair<int,int> pii;
	#define fi first
	#define se second
	inline pii operator+(const pii &x,const pii &y){
		return {max(x.fi,y.fi),x.se^y.se};
	}
	pii query(int p,int l,int r){
		if(t[p].l>r||l>t[p].r)return {0,0};
		if(l<=t[p].l&&t[p].r<=r)return {t[p].v1,t[p].v2};
		push_down(p);
		return query(ls(p),l,r)+query(rs(p),l,r);
	}
	typedef pair<int,int> pii;
	inline pii query_chain(int x,int y){
		pii ret={0,0};
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			ret=ret+query(1,seg[top[x]],seg[x]);
			x=fa[top[x]];
		}
		if(x==y)return ret;
		if(dep[x]>dep[y])swap(x,y);
		return ret+query(1,seg[x]+1,seg[y]);
	}
}
namespace MST{
	struct edge{
		int fr,to,v;
		bool mst;
	};
	vector<edge>e;
	struct dsu{
		int fa[maxn];
		inline void init(int siz){for(ri i=1;i<=siz;++i)fa[i]=i;}
		int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	}d;
	inline void kruskal(){
		d.init(n);
		ri tot=1;
		for(ri i=0;i<e.size();++i){
			ri x=d.find(e[i].fr),y=d.find(e[i].to);
			if(x!=y){
				d.fa[x]=y;
				tree::addedge(e[i].fr,e[i].to);
				tree::addedge(e[i].to,e[i].fr);
				e[i].mst=true;
				if(++tot==n)return;
			}
		}
	}
}
typedef pair<int,int> pii;
struct qry{
	char op[5];
	int x,y;
}q[maxn];
vector<bool>ans;
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=0;i<m;++i){
		ri x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		MST::e.push_back({x,y,z});
	}
	MST::kruskal();
	for(ri i=1;i<=n;++i)
		if(!tree::top[i]){
			tree::dfs1(i,0);
			tree::dfs2(i,i);
		}
	tree::build(1,1,tree::cnt);
	for(ri i=0;i<m;++i){
		pii tmp=tree::query_chain(MST::e[i].fr,MST::e[i].to);
		if(!tmp.fi){
			puts("YES");
			tree::modify_chain(MST::e[i].fr,MST::e[i].to,MST::e[i].v);
		}
		else if(tmp.fi==1){
			if((MST::e[i].v^tmp.se)==1){
				puts("YES");
				tree::modify_chain(MST::e[i].fr,MST::e[i].to,MST::e[i].v);
			}
			else puts("NO");
		}
		else puts("NO");
	}
	return 0;
}
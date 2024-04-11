#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int N=4e5+5;
int c[N],b[N];
inline void add(int x,int y){
	for(;x<N;x+=x&-x) c[x]+=y;
}
inline int sum(int x){
	int s=0;
	for(;x;x-=x&-x) s+=c[x];
	return s; 
}
struct node{
    int l,r;mutable int v;
    node(int L,int R,int V):l(L),r(R),v(V){}
    bool operator < (const node & a)const{
        return l<a.l;
    }
};
set<node> s[N];
#define IT set<node>::iterator
inline IT split(int id,int pos){
    IT it=s[id].lower_bound(node(pos,-1,0));
    if(it!=s[id].end()&&it->l==pos) return it;
    --it;
    int l=it->l,r=it->r,v=it->v;
    s[id].erase(it);s[id].insert(node(l,pos-1,v));
    return s[id].insert(node(pos,r,v)).first;
}
inline void assign(int id,int l,int r,int x){
    IT itr=split(id,r+1),itl=split(id,l);
    for(IT it=itl;it!=itr;++it) add(it->v,it->l-it->r-1);
    add(x,r-l+1);
    s[id].erase(itl,itr);s[id].insert(node(l,r,x));
}
int n,q;
vector<int> G[N];

int fa[N],dep[N],son[N],siz[N],top[N],dfn[N],mx[N];
inline void dfs1(int u,int f){
	fa[u]=f;dep[u]=dep[f]+1;siz[u]=1;
	for(int v:G[u]){
		if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;
	}
}
int dfn_t;
inline void dfs2(int u,int k){
	top[u]=k,mx[u]=dfn[u]=++dfn_t;
	//if(!son[u]) return;
	if(son[u]) dfs2(son[u],k),mx[u]=max(mx[son[u]],mx[u]);
	if(u==k) s[u].insert(node(dfn[u],mx[u]+1,N)); 
	for(int v:G[u])
		if(v!=fa[u]&&v!=son[u])
			dfs2(v,v);
}
inline int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return x;
}
int num=0;
inline void update(int x,int y){
	b[++num]=x;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		assign(top[x],dfn[top[x]],dfn[x],num);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	assign(top[x],dfn[x],dfn[y],num);
}
inline int dis(int x,int y){
	return dep[x]+dep[y]-(dep[lca(x,y)]<<1)+1;
}
inline int query(int u){
	int v=split(top[u],dfn[u])->v;
	return sum(v-1)+dis(u,b[v]);
}
int main(){
	n=read(),q=read();
	int u,v;
	for(int i=1;i<n;i++) {
		u=read(),v=read();
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs1(1,0);dfs2(1,1);
	for(int i=1;i<n;i++) update(i,i+1);
	char opt[10];int la=n;
	while(q--){
		scanf("%s",opt);u=read();
		if(opt[0]=='c') {
			v=read();
			printf("%d\n",query(u)<query(v)?u:v);
		}else if(opt[0]=='u'){
			update(la,u),la=u;
		}else {
			printf("%d\n",query(u));
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,q;
int rt[N],ls[N*30],rs[N*30],sum[N*30];
vector<int> G[N],g[N];
int tot=0;int fa[N];
int siz[N],son[N],top[N],dep[N];
inline void ins(int &rt,int pre,int l,int r,int p){
	rt=++tot;
	ls[rt]=ls[pre],rs[rt]=rs[pre],sum[rt]=sum[pre]+1;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(p<=mid) ins(ls[rt],ls[pre],l,mid,p);
	else ins(rs[rt],rs[pre],mid+1,r,p); 
}
void dfs(int u,int f){
	rt[u]=rt[f];fa[u]=f;siz[u]=1;dep[u]=dep[f]+1;
	for(int v:g[u]) ins(rt[u],rt[u],1,m,v);
	for(int v:G[u])
		if(v!=f){
			dfs(v,u);
			siz[u]+=siz[v];
			if(siz[son[u]]<siz[v]) son[u]=v;
		}
}
void dfs2(int u,int k){
	top[u]=k;
	if(!son[u]) return;
	dfs2(son[u],k);
	for(int v:G[u])
		if(v!=son[u]&&v!=fa[u])
			dfs2(v,v);
}
inline int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
inline int query(int rt1,int rt2,int pre1,int pre2,int l,int r,int c){
	if(l==r) return l;
	int s=sum[ls[rt1]]+sum[ls[rt2]]-sum[ls[pre1]]-sum[ls[pre2]];
	int mid=(l+r)>>1;
	
	if(c<=s) return query(ls[rt1],ls[rt2],ls[pre1],ls[pre2],l,mid,c);
	else return query(rs[rt1],rs[rt2],rs[pre1],rs[pre2],mid+1,r,c-s);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		G[x].push_back(y);G[y].push_back(x);
	}
	for(int i=1;i<=m;i++){
		int x;scanf("%d",&x);
		g[x].push_back(i);
	}
	dfs(1,0);dfs2(1,1);
	while(q--){
		int x,y,a;
		scanf("%d%d%d",&x,&y,&a);
		int z=lca(x,y);
		a=min(a,sum[rt[x]]+sum[rt[y]]-sum[rt[z]]-sum[rt[fa[z]]]);
		printf("%d ",a);
		for(int i=1;i<=a;i++) printf("%d ",query(rt[x],rt[y],rt[z],rt[fa[z]],1,m,i));
		puts("");
	}
	return 0;
}
/*
6 11 1
1 2
2 3
3 4
4 5
5 6
1 1 1 1 1 1 1 1 1 1 2
2 2 1
*/
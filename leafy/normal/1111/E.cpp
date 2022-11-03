#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int N=1e5+5,mod=1e9+7;
int n,q,k,m,r;
vector<int> G[N];
int f[N][305];
int a[N],c[N],g[N];
inline void add(int x,int y){
	for(;x<=n;x+=x&-x) c[x]+=y;
}
inline int sum(int x){
	int s=0;
	for(;x;x-=x&-x) s+=c[x];
	return s; 
}
inline int query(int l,int r){return sum(r)-sum(l-1);}
int fa[N],dep[N],son[N],siz[N],top[N],dfn[N];
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
	top[u]=k,dfn[u]=++dfn_t;
	if(!son[u]) return;
	dfs2(son[u],k);
	for(int v:G[u])
		if(v!=fa[u]&&v!=son[u])
			dfs2(v,v);
}
inline int query_g(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans+=query(dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return ans+query(dfn[x],dfn[y]);
}
int main(){
	n=read(),q=read();
	for(int i=1;i<n;i++) {
		int u=read(),v=read();
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs1(1,0);dfs2(1,1);
	while(q--){
		k=read(),m=read(),r=read();
		for(int i=1;i<=k;i++) a[i]=read(),add(dfn[a[i]],1);
		for(int i=1;i<=k;i++) g[a[i]]=query_g(a[i],r)-1;
		sort(a+1,a+k+1,[](int a,int b)->bool{return g[a]<g[b];});
		f[1][1]=1;
		for(int i=2;i<=k;i++)	
			for(int j=1;j<=min(i,m);j++)
				f[i][j]=(1ll*f[i-1][j]*max(j-g[a[i]],0)%mod+f[i-1][j-1])%mod;
		int ans=0;
		for(int i=1;i<=m;i++) ans=(ans+f[k][i])%mod;
		printf("%d\n",ans);
		for(int i=1;i<=k;i++) add(dfn[a[i]],-1);
	}
	return 0;
}
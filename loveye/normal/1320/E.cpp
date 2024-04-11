#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v,T) for(int i = T.fir[u],v;v = T.to[i],i;i = T.nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5;
int n,m,k,a[N<<1],s[N],tot,ans[N];
int st[N],ed[N];
struct Tree {
	int fir[N],to[N<<1],eds,nxt[N<<1];
	void addedge(int u,int v) {
		to[++eds]=v;
		nxt[eds]=fir[u];
		fir[u]=eds;
	}
} T0,T;
int dfn[N],dfc,bz[N][20],dep[N];
void predfs(int u,int fa) {
	fr(k,1,18) bz[u][k]=bz[bz[u][k-1]][k-1];
	dfn[u]=++dfc;
	dep[u]=dep[fa]+1;
	foredge(i,u,v,T0) if(v!=fa) bz[v][0]=u,predfs(v,u);
}
int LCA(int u,int v) {
	if(dep[u]<dep[v]) swap(u,v);
	rf(i,18,0) if(dep[u]-dep[v]>>i&1) u=bz[u][i];
	if(u==v) return u;
	rf(i,18,0) if(bz[u][i]!=bz[v][i]) u=bz[u][i],v=bz[v][i];
	return bz[u][0];
}
int dis(int u,int v) {return dep[u]+dep[v]-(dep[LCA(u,v)]<<1);}
int stk[N],top;

int from[N];
void chk(int u,int v) {
	if(!from[u]) return from[u]=v,void();
	if(from[u]==v) return;
	int t1=(dis(u,from[u])+s[from[u]]-1)/s[from[u]];
	int t2=(dis(u,v)+s[v]-1)/s[v];
	if(t2<t1||(t1==t2&&st[v]<st[from[u]])) from[u]=v;
}
void dfs1(int u) {
	if(st[u]) from[u]=u;
	else from[u]=0;
	foredge(i,u,v,T) {
		dfs1(v);
		if(from[v]) chk(u,from[v]);
	}
}
void dfs2(int u) {
	foredge(i,u,v,T) chk(v,from[u]),dfs2(v);
	if(ed[u]) ans[ed[u]]=st[from[u]];
	T.fir[u]=0;
}
void solve() {
	if(!st[1]&&!ed[1]) a[++tot]=1;
	sort(a+1,a+tot+1,[](const int &i,const int &j) {
		return dfn[i]<dfn[j];
	});
	stk[top=1]=1;
	fr(i,2,tot) if(a[i]!=a[i-1]) {
		int lca=LCA(stk[top],a[i]);
		while(top&&dep[lca]<=dep[stk[top-1]])
			T.addedge(stk[top-1],stk[top]),--top;
		if(stk[top]!=lca) T.addedge(lca,stk[top]),stk[top]=lca;
		stk[++top]=a[i];
	}
	while(top>1) T.addedge(stk[top-1],stk[top]),--top;
	dfs1(1); dfs2(1);
	T.eds=0;
}
int main() {
	n=read();
	for(int i=1,u,v;i<n;++i) {
		u=read(),v=read();
		T0.addedge(u,v);
		T0.addedge(v,u);
	}
	predfs(1,0);
	for(int q=read();q--;) {
		k=read(),m=read();
		fr(i,1,k) st[a[i]=read()]=i,s[a[i]]=read();
		fr(i,1,m) ed[a[i+k]=read()]=i;
		tot=k+m; solve();
		fr(i,1,k+m+1) st[a[i]]=ed[a[i]]=0;
		fr(i,1,m) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}
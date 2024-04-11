#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=1e5+9;
int n,m,cut[N];

namespace Tarjan {
	vp e[N];
	int tick,dfn[N],low[N],vst[N];

	void add(int u,int v,int id) {
		e[u].emplace_back(pii(v,id));
		e[v].emplace_back(pii(u,id));
		dfn[u]=dfn[v]=cut[id]=0;
	}
	void dfs(int u) {
		dfn[u]=low[u]=++tick;
		for(auto ed:e[u]) {
			int v=ed.fi, id=ed.se;
			if(vst[id]) continue; vst[id]=1;
			if(!dfn[v]) {
				dfs(v), low[u]=min(low[u],low[v]);
				if(low[v]>dfn[u]) cut[id]=1;
			}
			else low[u]=min(low[u],dfn[v]);
		}
	}
	void redfs(int u) {if(!dfn[u]) tick=0, dfs(u);}
	void clear(int u,int v) {e[u].clear(), e[v].clear();}
}

namespace Kruskal {
	int tot;
	struct edge {int u,v,w,id;} e[N];
	bool cmp(const edge &x,const edge &y) {return x.w<y.w;}

	int fa[N];
	int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
	void unite(int x,int y) {fa[find(x)]=find(y);}

	void add(int u,int v,int w,int id) {e[++tot]=(edge){u,v,w,id};}

	void solve() {
		sort(e+1,e+m+1,cmp);
		int r=0;
		rep(i,1,n) fa[i]=i;
		for(int l=1;l<=m;l=r+1) {
			while(r<m&&e[r+1].w==e[l].w) r++;
			rep(i,l,r) if(find(e[i].u)!=find(e[i].v))
				Tarjan::add(fa[e[i].u],fa[e[i].v],e[i].id);
			rep(i,l,r) if(find(e[i].u)!=find(e[i].v))
				Tarjan::redfs(fa[e[i].u]);
			rep(i,l,r) if(find(e[i].u)!=find(e[i].v)) 
				Tarjan::clear(fa[e[i].u],fa[e[i].v]);
			rep(i,l,r) unite(e[i].u,e[i].v);
		}
	}
}

int main() {
	n=read(), m=read();
	rep(i,1,m) {
		int u=read(), v=read(), w=read();
		Kruskal::add(u,v,w,i), cut[i]=-1;
	}
	Kruskal::solve();
	rep(i,1,m) {
		if(cut[i]==-1) puts("none");
		else if(cut[i]==0) puts("at least one");
		else if(cut[i]==1) puts("any");
		else throw "TRUMP";
	}
	return 0;
}
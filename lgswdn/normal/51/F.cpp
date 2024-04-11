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

int n,m,ans,dfn[N],low[N],tick,dcc[N],cnt;
vp e[N];
vi t[N];
bool evst[N],nvst[N],cut[N];

void tarjan(int u) {
	dfn[u]=low[u]=++tick;
	for(auto ed:e[u]) {
		int v=ed.fi, id=ed.se;
		if(evst[id]) continue; evst[id]=1;
		if(!dfn[v]) {
			tarjan(v), low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]) cut[id]=1;
		} else low[u]=min(low[u],dfn[v]);
	}
}
void dfs(int u) {
	dcc[u]=cnt;
	for(auto ed:e[u]) {
		int v=ed.fi, id=ed.se;
		if(evst[id]||cut[id]) continue; evst[id]=1;
		dfs(v);
	}
}

int f[N],lcnt,dd,deg[N];

void dfst(int u) {
	nvst[u]=1; f[u]=1;
	for(auto v:t[u]) if(!nvst[v]) {
		deg[u]++, deg[v]++; dfst(v);
		dd=max(dd,f[u]+f[v]);
		f[u]=max(f[u],f[v]+1);
	} lcnt+=(deg[u]<=1);
	dd=max(dd,f[u]);
}
int cald(int x) {
	lcnt=dd=0; dfst(x);
	return lcnt+dd-1-(lcnt>1);
}

signed main() {
	n=read(), m=read();
	rep(i,1,m) {
		int u=read(), v=read();
		e[u].emplace_back(pii(v,i)), e[v].emplace_back(pii(u,i));
	}
	rep(i,1,n) if(!dfn[i]) tarjan(i);
	rep(i,1,m) evst[i]=0;
	rep(i,1,n) if(!dcc[i]) ++cnt, dfs(i);
	ans=n;
	rep(i,1,n) for(auto v:e[i]) t[dcc[i]].emplace_back(dcc[v.fi]);
	rep(i,1,cnt) if(!nvst[i]) ans-=cald(i)-1;
	printf("%d\n",ans-1);
	return 0;
}
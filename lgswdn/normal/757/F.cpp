#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=3e5+9;
typedef pair<int,int> pii;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

struct edge {int to,w;};
vector<edge>e[N]; vector<int>e2[N],son[N];
void add(int u,int v,int w) {e[u].push_back((edge){v,w});}
int n,m,s,d[N],deg[N],lc[N],dep[N],f[N][29],sz[N],ans;
bool vst[N];

void dijkstra() {
	priority_queue<pii>q; q.push(pii(0,s));
	memset(d,0x3f,sizeof(d)); d[s]=0;
	while(!q.empty()) {
		int u=q.top().second; q.pop();
		if(vst[u]) continue; vst[u]=1;
		for(auto ed:e[u]) {
			int v=ed.to, w=ed.w;
			if(d[v]>d[u]+w)
				d[v]=d[u]+w, q.push(pii(-d[v],v));
		}
	}
	//cout<<"shortest path\n";
	//rep(i,1,n) cout<<d[i]<<" "; puts("");
}
void build(int u) {
	//cout<<u<<" "<<lc[u]<<endl;
	dep[u]=dep[lc[u]]+1, f[u][0]=lc[u];
	son[lc[u]].push_back(u);
	rep(i,1,19) f[u][i]=f[f[u][i-1]][i-1]; 
}
int lca(int u,int v) {
	if(dep[u]<dep[v]) swap(u,v);
	per(h,19,0) if(dep[f[u][h]]>=dep[v]) u=f[u][h];
	if(u==v) return u;
	per(h,19,0) if(f[u][h]!=f[v][h]) u=f[u][h],v=f[v][h];
	return f[u][0];
}
void domtree() {
	queue<int>q; rep(i,1,n) if(!deg[i]) q.push(i);
	dep[s]=1;
	while(!q.empty()) {
		int u=q.front(); q.pop();
		build(u);
		for(auto v:e2[u]) {
			deg[v]--;
			lc[v]=(lc[v]?lca(lc[v],u):u);
			if(!deg[v]) q.push(v);
		}
	}
}
void dfs(int u) {
	sz[u]=1;
	for(auto v:son[u])
		dfs(v), sz[u]+=sz[v];
	if(u!=s) ans=max(ans,sz[u]);
} 

signed main() {
	n=read(), m=read(), s=read();
	rep(i,1,m) {
		int u=read(), v=read(), w=read();
		add(u,v,w), add(v,u,w);
	}
	dijkstra();
	//cout<<"DAG\n";
	rep(u,1,n) for(auto ed:e[u]) if(d[ed.to]==d[u]+ed.w)
		e2[u].push_back(ed.to),deg[ed.to]++;
	domtree();
	dfs(s);
	printf("%lld\n",ans);
	return 0;
}
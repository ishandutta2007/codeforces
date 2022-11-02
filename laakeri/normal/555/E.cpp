// TCR
// Finds bridges and 2-edge connected components of graph
// Component of vertex x is c[x]
// Edge is bridge iff its endpoints are in different components
// Graph in form {adjacent vertex, edge id}
// Uses 1-indexing
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

struct Bridges {
	vector<int> c, h;
	void dfs(vector<pair<int, int> >* g, int x, int pe, int d, vector<int>& ns) {
		if (h[x]) return;
		h[x]=d;
		ns.push_back(x);
		for (auto nx:g[x]) {
			if (nx.S!=pe) {
				dfs(g, nx.F, nx.S, d+1, ns);
				h[x]=min(h[x], h[nx.F]);
			}
		}
		if (h[x]==d) {
			while (ns.size()>0) {
				int t=ns.back();
				c[t]=x;
				ns.pop_back();
				if (t==x) break;
			}
		}
	}
	Bridges(vector<pair<int, int> >* g, int n) : c(n+1), h(n+1) {
		vector<int> ns;
		for (int i=1;i<=n;i++) {
			dfs(g, i, -1, 1, ns);
		}
	}
};

vector<int> tg[202020];
int used[202020];
int pa[202020][20];
int d[202020];
int fr[202020];
int to[202020];
int lca(int a, int b){
	if (d[a]>d[b]) swap(a, b);
	for (int i=19;i>=0;i--){
		if (d[b]-d[a]>=(1<<i)){
			b=pa[b][i];
		}
	}
	if (a==b) return a;
	for (int i=19;i>=0;i--){
		if (pa[a][i]!=pa[b][i]){
			a=pa[a][i];
			b=pa[b][i];
		}
	}
	return pa[a][0];
}
void tdfs(int x, int pp){
	if (used[x]) return;
	used[x]=1;
	pa[x][0]=pp;
	for (int i=1;i<20;i++){
		pa[x][i]=pa[pa[x][i-1]][i-1];
	}
	for (int nx:tg[x]){
		if (nx!=pp) d[nx]=d[x]+1;
		tdfs(nx, x);
	}
}
vector<pair<int, int> > g[202020];
int cc[202020];
void dfs(int x, int c){
	if (cc[x]) return;
	cc[x]=c;
	for (auto nx:g[x]){
		dfs(nx.F, c);
	}
}

void dfs3(int x, int p){
	if (used[x]==3) return;
	used[x]=3;
	for (int nx:tg[x]){
		if (nx!=p){
 			dfs3(nx, x);
			fr[x]=max(fr[x], fr[nx]-1);
			to[x]=max(to[x], to[nx]-1);
		}
	}
	if (fr[x]>0&&to[x]>0){
		cout<<"No"<<endl;
		exit(0);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	Bridges b(g, n);
	for (int i=1;i<=n;i++) dfs(i, i);
	for (int i=1;i<=n;i++){
		for (auto nx:g[i]){
			if (b.c[nx.F]!=b.c[i]){
				tg[b.c[i]].push_back(b.c[nx.F]);
			}
		}
	}
	for (int i=1;i<=n;i++) tdfs(i, 0);
	for (int i=0;i<q;i++){
		int v,u;
		cin>>v>>u;
		if (cc[v]!=cc[u]){
			cout<<"No"<<endl;
			return 0;
		}
		if (b.c[v]!=b.c[u]){
 			v=b.c[v];
			u=b.c[u];
			int l=lca(u, v);
			fr[v]=max(fr[v], d[v]-d[l]);
			to[u]=max(to[u], d[u]-d[l]);
		}
	}
	for (int i=1;i<=n;i++){
		dfs3(i, 0);
	}
	cout<<"Yes"<<endl;
}
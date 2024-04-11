#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef int ll;

struct MaxFlow {
	struct e {
		int to,r;
		ll f;
	};
	vector<vector<e> > g;
	vector<int> used;
	int cc;
	ll flow(int x, int t, ll fl, ll miv) {
		if (x==t) return fl;
		used[x]=cc;
		for (auto& nx:g[x]) {
			if (used[nx.to]!=cc&&nx.f>=miv) {
				ll r=flow(nx.to, t, min(fl, nx.f), miv);
				if (r>0) {
					nx.f-=r;g[nx.to][nx.r].f+=r;
					return r;
				}
			}
		}
		return 0;
	}
	// maxv is maximum expected maxflow
	ll getMaxFlow(int source, int sink, ll maxv) {
		cc=1;ll r=0;ll k=1;
		while (k*2<=maxv) k*=2;
		for (;k>0;k/=2) {
			while (ll t=flow(source, sink, maxv, k)) {
				r+=t;cc++;
			}
			cc++;
		}
		return r;
	}
	void addEdge(int a, int b, ll c) {
		g[a].push_back({b, (int)g[b].size(), c});
		g[b].push_back({a, (int)g[a].size()-1, 0});
	}
	MaxFlow(int n) : g(n+1), used(n+1) {}
};

int nid;

int u[505050];

void dfs2(int x, MaxFlow& mf){
	if (u[x]) return;
	u[x]=1;
	for (auto ne:mf.g[x]){
		if (ne.f){
			dfs2(ne.to, mf);
		}
	}
}

int up[20202][15];
int uv[20202][15];

int d[20202];

vector<pair<int, int> > g[20202];

int source;
int sink;

const int W=1e6;

void dfs1(int x, int p, int pe, MaxFlow& mf){
	if (p!=0){
		up[x][0]=p;
		uv[x][0]=pe;
		mf.addEdge(pe, sink, 1);
		for (int i=1;i<15;i++){
			up[x][i]=up[up[x][i-1]][i-1];
			if (up[x][i]!=0){
				uv[x][i]=nid++;
				mf.addEdge(uv[x][i], uv[x][i-1], W);
				mf.addEdge(uv[x][i], uv[up[x][i-1]][i-1], W);
			}
		}
	}
	for (auto nx:g[x]){
		if (nx.F!=p){
			d[nx.F]=d[x]+1;
			dfs1(nx.F, x, nx.S, mf);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	MaxFlow mf(505000);
	source=n+m+1;
	sink=n+m+2;
	nid=n+m+3;
	dfs1(1, 0, 0, mf);
	for (int qq=0;qq<m;qq++){
		int x,y;
		cin>>x>>y;
		int tn=n+qq;
		mf.addEdge(source, tn, 1);
		if (d[x]<d[y]) swap(x, y);
		for (int i=14;i>=0;i--){
			if (d[x]-d[y]>=(1<<i)){
				mf.addEdge(tn, uv[x][i], W);
				x=up[x][i];
			}
		}
		assert(d[x]==d[y]);
		assert(x!=0&&y!=0);
		if (x==y) continue;
		for (int i=14;i>=0;i--){
			if (up[x][i]!=up[y][i]){
				mf.addEdge(tn, uv[x][i], W);
				mf.addEdge(tn, uv[y][i], W);
				x=up[x][i];
				y=up[y][i];
			}
		}
		assert(x!=0&&y!=0);
		assert(x!=y);
		mf.addEdge(tn, uv[x][0], W);
		mf.addEdge(tn, uv[y][0], W);
	}
	int ans=mf.getMaxFlow(source, sink, 1);
	for (int i=0;i<nid;i++){
		u[i]=0;
	}
	cout<<ans<<endl;
	dfs2(source, mf);
	vector<int> a1;
	for (int i=0;i<m;i++){
		if (!u[n+i]){
			a1.push_back(i+1);
		}
	}
	cout<<a1.size()<<" ";
	for (int x:a1){
		cout<<x<<" ";
	}
	cout<<endl;
	vector<int> a2;
	for (int i=1;i<=n-1;i++){
		if (u[i]){
			a2.push_back(i);
		}
	}
	cout<<a2.size()<<" ";
	for (int x:a2){
		cout<<x<<" ";
	}
	cout<<endl;
}
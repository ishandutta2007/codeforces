#include <bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<pii> vpi;
typedef vector<vi> graph;


struct LCA {
	vector<int> dist;
	vi pars;
	LCA () {}

	LCA(graph& C) : dist(sz(C)), pars(sz(C)){
		dfs(C);
	}

	void dfs(graph& C) {
		vector<tuple<int, int, int>> q(1);
		int v, p, d;
		while (!q.empty()) {
			tie(v, p, d) = q.back();
			q.pop_back();
			pars[v] = p;
			dist[v] = d;
			trav(e, C[v]) if (e != p)
				q.emplace_back(e, v, d+1);
		}
	}
};

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
};


vector<vi> treeJump(vi& P){
	int on = 1, d = 1;
	while(on < sz(P)) on *= 2, d++;
	vector<vi> jmp(d, P);
	rep(i,1,d) rep(j,0,sz(P))
		jmp[i][j] = jmp[i-1][jmp[i-1][j]];
	return jmp;
}

int jmp(vector<vi>& tbl, int nod, int steps){
	rep(i,0,sz(tbl))
		if(steps&(1<<i)) nod = tbl[i][nod];
	return nod;
}

int _lca(vector<vi>& tbl, vi& depth, int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	a = jmp(tbl, a, depth[a] - depth[b]);
	if (a == b) return a;
	for (int i = sz(tbl); i--;) {
		int c = tbl[i][a], d = tbl[i][b];
		if (c != d) a = c, b = d;
	}
	return tbl[0][a];
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int _n, k, R;
	cin >> _n >> k >> R;
	int n = _n + _n-1;
	vector<vector<int> > edges(n);
	for(int i = 0; i < _n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		int c = i + _n;
		edges[a].push_back(c);
		edges[b].push_back(c);
		edges[c].push_back(a);
		edges[c].push_back(b);
	}
	LCA lca(edges);
	vector<vector<int> > tbl = treeJump(lca.pars);
	vector<int> rest_stops(R);
	for(int& a : rest_stops){
		cin >> a;
		a--;
	}
	int q;
	cin >> q;
	vector<int> st(q), en(q);
	for(int i = 0; i < q; i++){
		cin >> st[i] >> en[i];
		st[i]--; en[i]--;
	}
	UF bubbles(n);
	vector<int> dist(n, -1);
	{
		vector<int> bfs = rest_stops;
		int s = 0;
		for(int a : bfs){
			dist[a] = 0;
		}
		while(s < (int)bfs.size()){
			int v = bfs[s];
			s++;
			for(int w : edges[v]){
				if(dist[w] == -1){
					dist[w] = dist[v] + 1;
					bfs.push_back(w);
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j : edges[i]){
			if(dist[i] + 1 <= k){
				bubbles.join(i, j);
			}
		}
	}
	for(int i = 0; i < q; i++){
		bool ans = false;
		int a = st[i];
		int b = en[i];
		int p = _lca(tbl, lca.dist, a, b);
		int d1 = lca.dist[a] - lca.dist[p];
		int d2 = lca.dist[b] - lca.dist[p];
		if(d1 + d2 <= 2 * k){
			ans = true;
		} else {
			int f1 = (k <= d1) ? jmp(tbl, a, k) : jmp(tbl, b, d1 + d2 - k);
			int f2 = (k <= d2) ? jmp(tbl, b, k) : jmp(tbl, a, d1 + d2 - k);
			if(bubbles.find(f1) == bubbles.find(f2)){
				ans = true;
			}
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
}
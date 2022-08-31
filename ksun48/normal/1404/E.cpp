#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, int rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				trav(e, adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	Dinic flow(n*m + 2);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] == '.') continue;
			if(i > 0 && s[i-1][j] == '#'){
				flow.addEdge(i*m + j, (i-1) * m + j, 1);
			} else {
				flow.addEdge(i*m + j, n*m+1, 1);
			}
			if(j > 0 && s[i][j-1] == '#'){
				flow.addEdge(i*m + (j-1), i*m + j, 1);
			} else {
				flow.addEdge(n*m, i*m + j, 1);
			}
		}
	}
	cout << flow.calc(n*m, n*m+1) << '\n';
}
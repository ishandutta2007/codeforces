#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct PushRelabel {
	struct Edge {
		int dest, back;
		ll f, c;
	};
	vector<vector<Edge>> g;
	vector<ll> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void addEdge(int s, int t, ll cap, ll rcap=0) {
		if (s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s])-1, 0, rcap});
	}

	void addFlow(Edge& e, ll f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	ll calc(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		trav(e, g[s]) addFlow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					addFlow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
	bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	m -= k;
	vector<pair<int,int> > special;
	for(int i = 0; i < k; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		special.push_back({u, v});
	}
	vector<pair<pair<int,int>, int> > normal;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		normal.push_back({{u, v}, w});
	}
	vector<int> val(1 << k, 0);
	for(int r = 0; r < (1 << k); r++){
		PushRelabel flow(n+2);
		for(auto e : normal){
			flow.addEdge(e.first.first, e.first.second, e.second);
		}
		for(int j = 0; j < k; j++){
			if(r & (1 << j)){
				flow.addEdge(special[j].first, special[j].second, 5e6);
			}
		}
		flow.addEdge(n, 0, 5e6);
		flow.addEdge(n-1, n+1, 5e6);
		val[((1 << k) - 1) ^ r] = min((ll)1e9, flow.calc(n, n+1));
	}
	for(int _ = 0; _ < q; _++){
		vector<int> w(k);
		for(int i = 0; i < k; i++) cin >> w[i];
		vector<int> a(1 << k);
		for(int j = 0; j < k; j++){
			for(int i = 0; i < (1 << j); i++){
				a[i + (1 << j)] = a[i] + w[j];
			}
		}
		int ans = 1e9;
		for(int i = 0; i < (1 << k); i++){
			ans = min(ans, val[i] + a[i]);
		}
		cout << ans << '\n';
	}
}
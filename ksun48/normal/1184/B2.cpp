#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef ll Flow;
struct Edge {
	int dest, back;
	Flow f, c;
};

struct PushRelabel {
	vector<vector<Edge>> g;
	vector<Flow> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void add_edge(int s, int t, Flow cap, Flow rcap=0) {
		if (s == t) return;
		Edge a = {t, sz(g[t]), 0, cap};
		Edge b = {s, sz(g[s]), 0, rcap};
		g[s].push_back(a);
		g[t].push_back(b);
	}

	void add_flow(Edge& e, Flow f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	Flow maxflow(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		trav(e, g[s]) add_flow(e, e.c);

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
					add_flow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
};


using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > edges(n);
	vector<vector<int> > dist(n, vector<int>(n, 1e9));
	for(int i = 0; i < n; i++) dist[i][i] = 0;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		dist[u][v] = min(dist[u][v], 1);
		dist[v][u] = min(dist[v][u], 1);
	}
	for(int _ = 0; _ < 3; _++)
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int s, b;
	ll k, h;
	cin >> s >> b >> k >> h;
	vector<int> x1(s), a(s), f(s);
	vector<int> x2(b), d(b);
	for(int i = 0; i < s; i++){
		cin >> x1[i] >> a[i] >> f[i];
		x1[i]--;
	}
	for(int i = 0; i < b; i++){
		cin >> x2[i] >> d[i];
		x2[i]--;
	}
	PushRelabel flow(s + b + 2);
	for(int i = 0; i < s; i++){
		for(int j = 0; j < b; j++){
			if(a[i] >= d[j] && f[i] >= dist[x1[i]][x2[j]]){
				flow.add_edge(i, j + s, 1);
			}
		}
	}
	for(int i = 0; i < s; i++) flow.add_edge(s + b, i, 1);
	for(int j = 0; j < b; j++) flow.add_edge(s + j, s + b + 1, 1);
	int v = flow.maxflow(s + b, s + b + 1);
	ll cost = v * k;
	for(int dummy = 0; dummy <= s; dummy++){
		ll cc = dummy * h;
		cc += k * min(v, s - dummy);
		cost = min(cc, cost);
	}
	cout << cost << '\n';
}
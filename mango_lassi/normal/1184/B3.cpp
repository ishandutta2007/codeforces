#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
const ll INF = 1e18;
 
// Dinic's algorithm for max flow
// O(V^2 E) in general
// O(min(V^{2/3}, E^1/2) E) in graphs with unit capacities
// O(sqrt{V} E) in unit networks (e.g. bipartite matching)
class Dinic {
	private:
		const static ll INF = 8*(ll)1e18;
		struct Edge {
			const int t; // Endpoint
			const ll c; // Capacity
			ll a; // Admissible flow
			Edge(int tar, ll cap = INF) : t(tar), c(cap), a(cap) {}
		};

		vector<Edge> edges;
		vector<vector<int>> conns;
		vector<int> dist, act_ind;

		ll push(int ei, ll v) {
			edges[ei].a -= v;
			edges[ei ^ 1].a += v;
			return v;
		}
		void calcDists(int sink) {
			for (int& v : dist) v = -1;
			dist[sink] = 0;
			vector<int> que = {sink};
			for (int j = 0; j < que.size(); ++j) {
				for (auto ei : conns[que[j]]) {
					int t = edges[ei].t;
					if (edges[ei^1].a > 0 && dist[t] == -1) {
						dist[t] = dist[que[j]] + 1;
						que.push_back(t);
					}
				}
			}
		}
		ll dfsFlow(int i, int sink, ll cap) {
			if (i == sink) return 0;
			for (int& j = act_ind[i]; j < conns[i].size(); ++j) {
				int ei = conns[i][j];
				int t = edges[ei].t;
				if (dist[t] != dist[i] - 1 || edges[ei].a == 0) continue;

				ll subcap = min(cap, edges[ei].a);
				cap -= push(ei, subcap - dfsFlow(t, sink, subcap));
				if (! cap) return 0;
			}
			return cap;
		}
	public:
		Dinic(int n) : conns(n), dist(n), act_ind(n) {}

		int addEdge(int s, int t, ll c = INF, bool dir = 1) {
			int i = edges.size() / 2;
			edges.emplace_back(t, c);
			edges.emplace_back(s, dir ? 0 : c);
			conns[s].push_back(2*i);
			conns[t].push_back(2*i+1);
			return i;
		}
		ll pushFlow(int source, int sink) {
			for (ll res = 0;;) {
				calcDists(sink);
				if (dist[source] == -1) return res;
				for (int& v : act_ind) v = 0;
				res += INF - dfsFlow(source, sink, INF);
			}
		}
		ll getFlow(int i) const { return edges[2*i].c - edges[2*i].a; }
};
ll solve(const Graph& g, const vector<ll>& vals) {
	// Problem is equivalent to:
	// 	maximize v1 x1 + ... + vn xn
	// 	subject to
	// 		xi - xj <= 0 if j \in g[i]
	// 		0 <= xi <= 1
 
	// Dual:
	// 	minimize y1 + ... + yn
	// 	subject to
	// 		yi + \sum_{outs} r_{j} >= vi + \sum_{ins} r_{j}
	// 		0 <= yi, rj
 
	// Use max-flow. r_{j} is flow along edge j. We have
	// 	yi + \sum_{outs} r_{j} >= vi + \sum_{ins} r_{j} (if vi >= 0)
	//	yi + \sum_{outs} r_{j} - vi >= \sum_{ins} r_{j} (if vi < 0)
 
	int n = g.size();
	int source = n;
	int sink = n+1;
	Dinic dinic(n+2);
 
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		if (vals[i] < 0) {
			dinic.addEdge(i, sink, -vals[i]);
		} else {
			dinic.addEdge(source, i, vals[i]);
			res += vals[i];
		}
		for (auto t : g[i]) {
			dinic.addEdge(i, t);
		}
	}
	res -= dinic.pushFlow(source, sink);
	return res;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> dist(n);
	for (int i = 0; i < n; ++i) {
		dist[i].resize(n, INF);
		dist[i][i] = 0;
	}
 
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < n; ++b) {
				dist[a][b] = min(dist[a][b], dist[a][i] + dist[i][b]);
			}
		}
	}
 
	int s, b, k;
	cin >> s >> b >> k;
 
	vector<tuple<int, int, int, int>> ships(s);
	for (int i = 0; i < s; ++i) {
		int loc, atk, fuel, cost;
		cin >> loc >> atk >> fuel >> cost;
		--loc;
		ships[i] = tie(loc, atk, fuel, cost);
	}
	vector<tuple<int, int, int>> bases(b);
	for (int i = 0; i < b; ++i) {
		int tar, def, gold;
		cin >> tar >> def >> gold;
		--tar;
		bases[i] = tie(tar, def, gold);
	}
	sort(bases.begin(), bases.end());
 
	vector<vector<pair<int, int>>> offs(n);
	for (int i = 0; i < b; ++i) {
		int tar, def, gold;
		tie(tar, def, gold) = bases[i];
		if (offs[tar].empty() || offs[tar].back().second < gold) {
			offs[tar].push_back({def, gold});
		}
	}
 
	vector<ll> vals(s, -INF);
	for (int i = 0; i < s; ++i) {
		int loc, atk, fuel, cost;
		tie(loc, atk, fuel, cost) = ships[i];
 
		for (int t = 0; t < n; ++t) {
			if (dist[loc][t] > fuel) continue;
			int low = -1;
			int high = (int)offs[t].size() - 1;
			while(low != high) {
				int mid = (low + high + 1) >> 1;
				if (atk >= offs[t][mid].first) low = mid;
				else high = mid - 1;
			}
			if (low >= 0) vals[i] = max(vals[i], (ll)offs[t][low].second);
		}
		vals[i] -= cost;
	}
 
	Graph g(s);
	for (int j = 0; j < k; ++j) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
	}
 
	ll res = solve(g, vals);
	cout << res << '\n';
}
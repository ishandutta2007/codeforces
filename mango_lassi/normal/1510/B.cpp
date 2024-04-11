#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// Dinic's algorithm for max flow
// O(V^2 E) in general
// O(min(V^{2/3}, E^1/2) E) in graphs with unit capacities
// O(sqrt{V} E) in unit networks (e.g. bipartite matching)
class Dinic {
	private:
		const static ll INF = 8*(ll)1e18;
		struct Edge {
			const int t; // Endpoint
			ll a; // Admissible flow
			Edge(int tar, ll cap = INF) : t(tar), a(cap) {}
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
		// Returns a min-cut containing the sink
		vector<int> minCut() {
			vector<int> res;
			for (int i = 0; i < dist.size(); ++i) {
				if (dist[i] == -1) res.push_back(i);
			}
			return res;
		}
		// Gives flow on edge assuming it is directed/undirected. Undirected flow is signed.
		ll getDirFlow(int i) const { return edges[2*i+1].a; }
		ll getUndirFlow(int i) const { return (edges[2*i+1].a - edges[2*i].a) / 2; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int d, n;
	cin >> d >> n;

	vector<int> nodes(n);
	vector<vector<int>> layers(d);
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		int ind = 0;
		for (int j = 0; j < d; ++j) {
			if (str[j] == '1') ind += 1 << j;
		}
		nodes[i] = ind;
		layers[__builtin_popcount(ind) - 1].push_back(i);
	}

	Dinic dinic(2*n + 2);
	int so = 2*n;
	int si = 2*n+1;

	vector<pair<int, pair<int, int>>> edges;
	for (int i = 0; i < n; ++i) {
		dinic.addEdge(so, i, 1);
		dinic.addEdge(i+n, si, 1);
	}
	for (int j = d-2; j >= 0; --j) {
		for (int i = j+1; i < d; ++i) {
			for (int y : layers[j]) {
				for (int x : layers[i]) {
					if ((nodes[x] & nodes[y]) == nodes[y]) {
						int ind = dinic.addEdge(y, x+n, 1);
						edges.emplace_back(ind, make_pair(y, x));
					}
				}
			}
		}
		dinic.pushFlow(so, si);
	}

	vector<int> nxt(n, -1), pre(n, -1);
	for (auto pr : edges) {
		if (dinic.getDirFlow(pr.first)) {
			int y = pr.second.first;
			int x = pr.second.second;
			nxt[y] = x;
			pre[x] = y;
		}
	}

	vector<int> starts;
	for (int i = 0; i < n; ++i) {
		if (pre[i] == -1) starts.push_back(i);
	}

	vector<int> res;
	while(! starts.empty()) {
		int cur = 0;
		int ind = starts.back();
		starts.pop_back();

		while(ind != -1) {
			for (int j = 0; j < d; ++j) {
				if (cur & (1 << j)) continue;
				if (! (nodes[ind] & (1 << j))) continue;
				res.emplace_back(j);
			}
			cur = nodes[ind];
			ind = nxt[ind];
		}
		res.push_back(-1);
	}
	res.pop_back();

	cout << res.size() << '\n';
	for (auto v : res) {
		if (v == -1) cout << "R ";
		else cout << v << ' ';
	}
	cout << '\n';
}
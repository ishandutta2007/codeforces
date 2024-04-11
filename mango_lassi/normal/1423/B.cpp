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

	int n, m;
	cin >> n >> m;

	vector<pair<int, pair<int, int>>> roads(m);
	for (int i = 0; i < m; ++i) {
		int a, b, d;
		cin >> a >> b >> d;
		--a; --b;
		roads[i] = {d, {a, b}};
	}
	sort(roads.begin(), roads.end());

	// We need to check if a perfect matching exists
	// Dinic is fast enough for this

	int low = n;
	int high = m;
	while (low != high) {
		int mid = (low + high) >> 1;

		Dinic dinic(2*n+2);
		for (int i = 0; i < n; ++i) {
			dinic.addEdge(2*n, i, 1, 1);
			dinic.addEdge(i+n, 2*n+1, 1, 1);
		}
		for (int i = 0; i <= mid; ++i) {
			dinic.addEdge(roads[i].second.first, n + roads[i].second.second, 1, 1);
		}

		int flow = dinic.pushFlow(2*n, 2*n+1);
		if (flow == n) high = mid;
		else low = mid + 1;
	}
	cout << (low >= m ? -1 : roads[low].first) << '\n';
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18 + 7;

// Struct for priority queue operations on index set [1, n]
// push(i, v) overwrites value at position i if one already exists
// decKey is faster but requires that the new key is smaller than the old one
struct Prique {
	const ll INF = 4 * (ll)1e18;
	vector<pair<ll, int>> data;
	const int n;

	Prique(int siz) : n(siz), data(2*siz, {INF, -1}) { data[0] = {-INF, -1}; }
	void push(int i, ll v) {
		data[i+n] = {v, (v >= INF ? -1 : i)};
		for (i += n; i > 1; i >>= 1) data[i>>1] = min(data[i], data[i^1]);
	}
	void decKey(int i, ll v) {
		for (int j = i+n; data[j].first > v; j >>= 1) data[j] = {v, i};
	}
	pair<ll, int> pop() {
		auto res = data[1];
		push(res.second, INF);
		return res;
	}
};

// Find shortest paths from src to all other nodes.
// cost[i] is cost from src to node i
// prev[i] is previous node on cheapest path from src to i
// Complexity: O(m log n), Space: O(m)
pair<vector<ll>, vector<int>> djikstra(int src, const vector<vector<pair<int, ll>>>& g) {
	int n = g.size();
	vector<ll> cost(n, 4 * (ll)1e18);
	vector<int> prev(n, -1);
	Prique que(n);

	cost[src] = 0;
	for (int i = src; i != -1; i = que.pop().second) {
		for (auto pr : g[i]) {
			int t = pr.first;
			ll off = cost[i] + pr.second;
			if (off < cost[t]) {
				cost[t] = off;
				prev[t] = i;
				que.decKey(t, off);
			}
		}
	}
	return {cost, prev};
}


void solve() {
	int n, m;
	cin >> n >> m;

	vector<pair<pair<int, int>, ll>> ed;
	vector<vector<pair<int, ll>>> g(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		ll w;
		cin >> a >> b >> w;
		--a; --b;

		ed.emplace_back(make_pair(a, b), w);
		g[a].emplace_back(b, 1);
		g[b].emplace_back(a, 1);
	}
	vector<ll> so_dist = djikstra(0, g).first;
	vector<ll> si_dist = djikstra(n-1, g).first;
	
	// Compute mutual distances
	Prique pq(n);
	vector<ll> bo_dist(n, INF);
	for (int i = 0; i < n; ++i) {
		bo_dist[i] = so_dist[i] + si_dist[i];
		pq.decKey(i, bo_dist[i]);
	}
	for (int j = 0; j < n; ++j) {
		int i = pq.pop().second;
		ll d = bo_dist[i];
		for (auto pr : g[i]) {
			int t = pr.first;
			if (bo_dist[t] > bo_dist[i] + 1) {
				bo_dist[t] = bo_dist[i] + 1;
				pq.decKey(t, bo_dist[t]);
			}
		}
	}

	ll res = INF;
	for (auto pr : ed) {
		int a = pr.first.first;
		int b = pr.first.second;
		
		ll di0 = 1 + min(so_dist[a] + si_dist[b], so_dist[b] + si_dist[a]);
		ll di1 = 2 + min(bo_dist[a], bo_dist[b]);
		res = min(res, min(di0, di1) * pr.second);
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
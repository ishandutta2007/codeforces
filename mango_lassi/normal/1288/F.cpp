#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// Struct for priority queue operations on index set [1, n]
// push(i, v) overwrites value at position i if one already exists
// decKey is faster but requires that the new key is smaller than the old one
struct PriQue {
	const ll INF = 4 * (ll)1e18;
	vector<pair<ll, int>> data;
	const int n;
 
	PriQue(int siz) : n(siz), data(2*siz, {INF, -1}) { data[0] = {-INF, -1}; }
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
 
// Capacity scaling algorithm for min cost circulation
// To solve minimum cost flow, add an edge from sink to source with cost -nC
// Complexity: O(m^2 log U log n), Space: O(m)
class MinCostCirc {
	private:
		struct Edge {
			int t; // other endpoint
			ll ru, c, u; // real capacity, cost, capacity
		};
 
		const ll INF = (ll)1e18; // must be greater than 2nC
		const int n;
		vector<Edge> edges;
		vector<vector<int>> g;
		vector<ll> p, dist; // potential
		vector<int> pre;
		PriQue que;
 
		void djikstra() {
			while(true) {
				int i = que.pop().second;
				if (i == -1) break;
				for (int ei : g[i]) {
					Edge& ed = edges[ei];
					ll off = dist[i] + (ed.c + p[i] - p[ed.t]);
					if (ed.u && off < dist[ed.t]) {
						pre[ed.t] = ei;
						dist[ed.t] = off;
						que.decKey(ed.t, off);
					}
				}
			}
			for (int i = 0; i < n; ++i) p[i] += dist[i];
		}
 
		// Updates potentials to ensure that no negative cost arcs form when we push flow along the cycle
		void updatePotentials(int s) {
			for (ll& v : dist) v = INF;
			dist[s] = 0;
			que.decKey(s, 0);
			djikstra();
		}
 
		// Fixes potentials to range [-nC, nC]
		void fixPotentials() {
			for (int i = 0; i < n; ++i) {
				dist[i] = -p[i];
				que.decKey(i, dist[i]);
			}
			djikstra();
		}

		// Increases capacity of the edge by h
		ll incEdge(int ei, ll h) {
			Edge& ed = edges[ei];
			if (ed.u == 0) updatePotentials(ed.t);
			ed.u += h;
 
			int s = edges[ei ^ 1].t;
			ll res = h * min(0ll, (ed.c + p[s] - p[ed.t]));
			if (res < 0) {
				pre[ed.t] = ei;
				for (int i = s; ed.u > 0;) {
					edges[pre[i]].u -= h; // push flow
					edges[pre[i] ^ 1].u += h;
					i = edges[pre[i] ^ 1].t;
				}
			}
			if (ed.u <= h) fixPotentials();
			return res;
		}
	public:
		MinCostCirc(int nc) : n(nc), g(nc), p(nc, 0), dist(n), pre(n), que(n) {}
		
		int addEdge(int s, int t, ll u, ll c) {
			int i = edges.size();
			edges.push_back({t, u, c, 0});
			edges.push_back({s, 0, -c, 0});
			g[s].push_back(i);
			g[t].push_back(i^1);
			return i >> 1;
		}
		ll edgeFlow(int ei) const { return edges[2*ei ^ 1].u; }
		
		// Finds min-cost circulation in O(m^2 log U log n)
		ll minCostCirc() {
			ll res = 0;
			for (ll h = 1ll << 62; h > 0; h >>= 1) {
				for (int ei = 0; ei < edges.size(); ++ei) {
					if (edges[ei].ru & h) res += incEdge(ei, h);
				}
			}
			return res;
		}
};

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Minimise \sum_{(i, j)} c1 b(i, j) + c2 r(i, j)
	// \sum_{(i, j)} b(i, j) - r(i, j) >= 1 (for blue i)
	// \sum_{(i, j)} r(i, j) - b(i, j) >= 1 (for red i)
	// Say edge is BLUE if it flows left-to-right
	// Say edge is RED if it flows right-to-left
	// Then:
	//	for left blues and right reds outflow must be at least inflow plus one
	// 	for right blues and left reds inflow must be at least outflow plus one
	// -> Min-cost flow!

	int n1, n2, m;
	ll c1, c2;
	cin >> n1 >> n2 >> m >> c1 >> c2;

	MinCostCirc mcc(n1 + n2 + 1);
	int so = n1 + n2;

	string le, ri;
	cin >> le >> ri;

	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		mcc.addEdge(a, n1 + b, 1, c2); // BLUE
		mcc.addEdge(n1 + b, a, 1, c1); // RED
	}

	ll cc = 0;
	for (int i = 0; i < n1; ++i) {
		if (le[i] == 'R') {
			// Left red <- inflow at least outflow + 1
			mcc.addEdge(i, so, 1, -INF);
			mcc.addEdge(i, so, INF, 0);
			++cc;
		} else if (le[i] == 'B') {
			// Left blue <- outflow at least inflow + 1
			mcc.addEdge(so, i, 1, -INF);
			mcc.addEdge(so, i, INF, 0);
			++cc;
		} else {
			// No conditions, unlimited flow both in and out
			mcc.addEdge(i, so, INF, 0);
			mcc.addEdge(so, i, INF, 0);
		}
	}
	for (int i = 0; i < n2; ++i) {
		if (ri[i] == 'B') {
			// Right blue <- inflow at least outflow + 1
			mcc.addEdge(n1 + i, so, 1, -INF);
			mcc.addEdge(n1 + i, so, INF, 0);
			++cc;
		} else if (ri[i] == 'R') {
			// Right red <- outflow at least inflow + 1
			mcc.addEdge(so, n1 + i, 1, -INF);
			mcc.addEdge(so, n1 + i, INF, 0);
			++cc;
		} else {
			// No conditions, unlimited flow both in and out
			mcc.addEdge(n1 + i, so, INF, 0);
			mcc.addEdge(so, n1 + i, INF, 0);
		}
	}

	ll cost = cc * INF + mcc.minCostCirc();
	if (cost >= INF) {
		cout << -1 << '\n';
	} else {
		cout << cost << '\n';
		for (int i = 0; i < m; ++i) {
			int d = mcc.edgeFlow(2*i) - mcc.edgeFlow(2*i+1);
			if (d == 1) cout << 'B';
			else if (d == 0) cout << 'U';
			else cout << 'R';
		}
		cout << '\n';
	}
}
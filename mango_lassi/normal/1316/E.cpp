#include <iostream>
#include <vector>
#include <algorithm>
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
 
		// Finds min-cost maximum flow in O(nm + Fm log n) time (where F is the flow amount), assuming there are no negative-weight cycles
		pair<int, ll> minCostFlow(int so, int si) {
			for (auto& ed : edges) ed.u = ed.ru;
			for (int round = 0; round < n; ++round) {
				for (int ei = 0; ei < edges.size(); ++ei) {
					if (! edges[ei].u) continue;
					p[edges[ei].t] = min(p[edges[ei].t], p[edges[ei ^ 1].t] + edges[ei].c);
				}
			}
			int sse = 2 * addEdge(si, so, INF, -INF);
 
			ll off = 0;
			pair<int, ll> res = {0, 0};
			while(true) {
				off = incEdge(sse, 1);
				if (off >= 0) return res;
				else res = {res.first + 1, res.second + off + INF};
			}
		}
};

const ll INF = (ll)1e9;
const int N = 1e5;
const int P = 7;
int val[N][2*P+1];
vector<int> can[2*P+1];
int ind[N + 3 + P];
int typ[N];
int rev[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, p, k;
	cin >> n >> p >> k;

	vector<pair<int, int>> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> val[i][0];
		as[i] = {val[i][0], i};
	}
	sort(as.begin(), as.end());
	reverse(as.begin(), as.end());

	ll res = 0;
	for (int i = 0; i < k; ++i) {
		res += as[i].first;
		typ[as[i].second] = 1;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= p; ++j) {
			cin >> val[i][j];
			val[i][j+p] = val[i][j] - val[i][0];
		}
		for (int j = 1 + typ[i] * p; j <= p + typ[i] * p; ++j) {
			int x = i;
			for (int t = 0; t < can[j].size(); ++t) {
				if (val[can[j][t]][j] < val[x][j]) swap(can[j][t], x);
			}
			if (can[j].size() < p) can[j].push_back(x);
		}
	}
	for (int j = k; j < k+p; ++j) can[0].push_back(as[j].second);

	int so = p;
	int si = p+1;
	int aux = p+2;

	int nn = 3 + p;
	for (int j = 0; j <= 2*p; ++j) {
		for (auto x : can[j]) {
			if (ind[x] == 0) {
				ind[x] = nn;
				rev[nn] = x;
				++nn;
			}
		}
	}

	MinCostCirc mcc(nn);

	mcc.addEdge(so, aux, p, -INF);
	for (int i = 0; i < p; ++i) mcc.addEdge(i, si, 1, -INF);
	for (int i : can[0]) {
		mcc.addEdge(ind[i], si, 1, -val[i][0]);
	}
	for (int j = 1; j <= 2*p; ++j) {
		int t = (j-1) % p;
		for (auto x : can[j]) {
			if (typ[x]) {
				mcc.addEdge(ind[x], t, 1, -val[x][t+1+p]);
			} else {
				mcc.addEdge(ind[x], t, 1, -val[x][t+1]);
			}
		}
	}
	for (int t = 0; t < p; ++t) {
		for (auto x : can[0]) {
			mcc.addEdge(ind[x], t, 1, -val[x][t+1]);
		}
	}

	for (int i = 3+p; i < nn; ++i) {
		int x = rev[i];
		if (typ[x]) mcc.addEdge(so, i, 1, 0);
		else mcc.addEdge(aux, i, 1, 0);
	}
	mcc.addEdge(si, so, INF, 0);

	res -= (2 * p * INF) + mcc.minCostCirc();
	cout << res << '\n';
}
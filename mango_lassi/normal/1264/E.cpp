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
 
		const ll INF = (ll)1e18; // must be > nC
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
 
		void updatePotentials(int s) {
			for (ll& v : dist) v = INF;
			dist[s] = 0;
			que.decKey(s, 0);
			djikstra();
		}
		void fixPotentials() {
			for (int i = 0; i < n; ++i) {
				dist[i] = -p[i];
				que.decKey(i, dist[i]);
			}
			djikstra();
		}
		ll incEdge(int ei, ll h) {
			ll res = 0;
			Edge& ed = edges[ei];
			if (ed.u == 0) updatePotentials(ed.t);
			ed.u += h;
 
			int s = edges[ei ^ 1].t;
			res = min(res, ed.c + p[s] - p[ed.t]);
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
 
 
const int N = 50;
const int FV = 2 + N + N*N;
const int FE = 5 * N*N;
const ll INF = 1e9;
 
int win[N][N];
int ref[N][N];
int outd[N];
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		win[a][b] = 1;
		win[b][a] = -1;
		++outd[a];
	}
	int t = n*(n-1)/2;
 
	// Beauty	= number of cycles of length 3
	//		= (n choose 3) - \sum_{i} (o_i choose 2)
	// So we must minimise \sum_{i} o_i^2 (\sum o_i is always n(n-1)/2)
 
	// Solve this using min-cost flow. Flow to node i is its outdegree, flowing in i'th unit costs 2i + 1,
	// And to every edge must be flown one unit.
 
	int v = 2 + n + n*n;
	int source = v - 2;
	int sink = v - 1;
	MinCostCirc mcc(v);
 
	for (int i = 0; i < n; ++i) {
		for (int j = outd[i]; j < n; ++j) {
			mcc.addEdge(source, i, 1, 2*j+1);
		}
	}
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			int ind = n + min(a, b) + n * max(a, b);
			if (a != b && win[a][b] == 0) {
				ref[a][b] = mcc.addEdge(a, ind, 1, 0);
			}
			if (a < b) mcc.addEdge(ind, sink, 1, 0);
		}
	}
	mcc.minCostFlow(source, sink);
 
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			if (a != b && win[a][b] == 0) {
				if (mcc.edgeFlow(ref[a][b]) > 0) {
					win[a][b] = 1;
					win[b][a] = -1;
				}
			}
			cout << (win[a][b] == 1);
		}
		cout << '\n';
	}
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const ll INF = 1e18;

// Min-Cost Flow with positive convex edge weights
class MinCostFlow {
	private:
		struct Edge {
			int a, b; // source, target
			int f, c; // flow, capacity
			ll m1, m2; // constants for cost

			Edge(int av, int bv, int cv, ll m1v, ll m2v)
				: a(av), b(bv), f(0), c(cv), m1(m1v), m2(m2v) {}

			// Get other end of edge
			int getOth(int i) {
				return i == a ? b : a;
			}
			// Get change in cost of pushing flow from i to getOth(i)
			ll getCost(int i) {
				int tf = f + (i == a ? 1 : -1);
				if (tf < 0 || tf > c) return INF;
				return m1*(tf-f) + m2*(tf*tf-f*f);
			}
			void pushUnit(int i) {
				f += (i == a ? 1 : -1);
			}
		};

		vector<Edge> eds;
		vector<vector<int>> conns;
	public:
		MinCostFlow(int n) : conns(n) {}

		void addEdge(int a, int b, int c, int m1, int m2) {
			eds.emplace_back(a, b, c, m1, m2);
			conns[a].push_back(eds.size() - 1);
			conns[b].push_back(eds.size() - 1);
		}
		ll pushFlow(int source, int sink) {
			int n = conns.size();
			ll res = 0;

			vector<int> pre(n);
			vector<ll> cost(n);
			while(true) {
				for (int i = 0; i < n; ++i) {
					pre[i] = -1;
					cost[i] = INF;
				}
				cost[source] = 0;

				priority_queue<pair<ll, int>> que;
				que.push({0, source});
				while(! que.empty()) {
					int i = que.top().second;
					ll v = -que.top().first;
					que.pop();
					if (v > cost[i]) continue;
					for (auto j : conns[i]) {
						int t = eds[j].getOth(i);
						ll off = cost[i] + eds[j].getCost(i);
						if (off < cost[t]) {
							cost[t] = off;
							pre[t] = j;
							que.push({-off, t});
						}
					}
				}
				int i = sink;
				while(pre[i] != -1) {
					auto& ed = eds[pre[i]];
					i = ed.getOth(i);
					ed.pushUnit(i);
				}
				if (i != source) break;
				res += cost[sink];
			}
			return res;
		}
};

int getInd(int i, int t, int n) {
	return i + t*n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, c, d;
	cin >> n >> m >> k >> c >> d;

	int mt = n + k - 1;
	int nn = mt*n + 2;
	MinCostFlow fl(nn);
	int source = nn-2;
	int sink = nn-1;

	for (int t = 0; t < mt; ++t) {
		fl.addEdge(getInd(0, t, n), sink, k, t*c, 0);
	}
	for (int t = 0; t+1 < mt; ++t) {
		for (int i = 0; i < n; ++i) {
			fl.addEdge(getInd(i, t, n), getInd(i, t+1, n), k, 0, 0);
		}
	}
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		--a;
		fl.addEdge(source, getInd(a, 0, n), 1, 0, 0);
	}
	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		for (int t = 0; t+1 < mt; ++t) {
			fl.addEdge(getInd(a, t, n), getInd(b, t+1, n), k, 0, d);
			fl.addEdge(getInd(b, t, n), getInd(a, t+1, n), k, 0, d);
		}
	}
	ll ans = fl.pushFlow(source, sink);
	cout << ans << '\n';
}
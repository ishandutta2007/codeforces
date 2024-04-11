#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;

class DSU {
	private:
		vector<int> comp, siz;
		vector<set<int>> que;
	public:
		vector<ll> ans;

		DSU(int n, const vector<pair<int, int>>& q) : comp(n), siz(n, 1), que(n), ans(q.size(), -1) {
			for (int i = 0; i < n; ++i) comp[i] = i;
			for (int j = 0; j < q.size(); ++j) {
				que[q[j].first].insert(j);
				que[q[j].second].insert(j);
			}
		}
		int getc(int i) {
			if (comp[i] != i) comp[i] = getc(comp[i]);
			return comp[i];
		}
		void join(int a, int b, ll res) {
			a = getc(a);
			b = getc(b);
			if (a == b) return;

			if (siz[a] < siz[b]) swap(a, b);
			siz[a] += siz[b];
			comp[b] = a;

			if (que[a].size() < que[b].size()) swap(que[a], que[b]);
			for (auto j : que[b]) {
				auto it = que[a].find(j);
				if (it != que[a].end()) {
					ans[j] = res;
					que[a].erase(it);
				} else {
					que[a].insert(j);
				}
			}
		}
		int compSize(int i) { return siz[getc(i)]; }
};

const ll INF = 1e18;
const int N = 1e5;
vector<pair<int, ll>> conns[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, q;
	cin >> n >> m >> k >> q;

	for (int i = 0; i < m; ++i) {
		int a, b;
		ll w;
		cin >> a >> b >> w;
		--a; --b;
		conns[a].push_back({b, w});
		conns[b].push_back({a, w});
	}
	
	vector<pair<int, int>> qrs(q);
	for (int qi = 0; qi < q; ++qi) {
		int a, b;
		cin >> a >> b;
		qrs[qi] = {a-1, b-1};
	}
	DSU dsu(n, qrs);

	// do multi-source DFS. Once two charging stations can reach some node, combine them in DSU.
	// Whenever we combine two charging stations, answer queries where one endpoint is in one and the other in the other.
	vector<pair<ll, int>> dist(n, {INF, -1});
	priority_queue<pair<ll, int>> que; // DFS queue
	vector<pair<ll, pair<int, int>>> evs; // join events

	for (int i = 0; i < k; ++i) {
		dist[i] = {0, i};
		que.push({0, i});
	}
	while(! que.empty()) {
		ll w = -que.top().first;
		int i = que.top().second;
		int j = dist[i].second;
		que.pop();
		if (dist[i].first != w) continue;

		for (auto pr : conns[i]) {
			int t = pr.first;
			ll off = w + pr.second;

			if (dist[t].second != -1) {
				evs.push_back({off + dist[t].first, {j, dist[t].second}});
			}
			if (dist[t].first > off) {
				dist[t] = {off, j};
				que.push({-off, t});
			}
		}
	}

	// Make joins
	sort(evs.begin(), evs.end());
	for (auto pr : evs) {
		ll w = pr.first;
		dsu.join(pr.second.first, pr.second.second, w);
	}

	// Answer queries
	for (auto v : dsu.ans) cout << v << '\n';
}
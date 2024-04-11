#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

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

int off(pair<int, int> a, pair<int, int> b) {
	return 1 + min(a.first + b.second, a.second + b.first);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> spec(k);
	for (int i = 0; i < k; ++i) {
		cin >> spec[i];
		--spec[i];
	}

	vector<vector<pair<int, ll>>> g(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back({b, 1});
		g[b].push_back({a, 1});
	}

	auto d0 = djikstra(0, g).first;
	auto d1 = djikstra(n-1, g).first;

	int dist = d0[n-1];
	
	vector<pair<int, int>> offs(k);
	for (int i = 0; i < k; ++i) {
		offs[i] = {(int)d0[spec[i]], (int)d1[spec[i]]};
	}
	sort(offs.begin(), offs.end());

	// Find pair maximising min(a0 + b1, a1 + b0)
	// We have a0 + b0 >= dist, a1 + b1 >= dist
	int res = 0;
	vector<pair<pair<int, int>, int>> act;
	for (int i = 0; i < k; ++i) {
		auto pr = offs[i];
		while(! act.empty() && act.back().first.first == pr.first) {
			res = max(res, off(act.back().first, pr));
			act.pop_back();
		}
		if (! act.empty()) res = max(res, off(act.back().first, pr));
		act.push_back({pr, i});
	}

	for (int i = 0; i < k; ++i) {
		auto pr = offs[i];

		// Binary search point where a0 + pr.second >= a1 + pr.first
		int low = 0;
		int high = (int)act.size();
		while(low != high) {
			int mid = (low + high) >> 1;
			if (act[mid].first.first + pr.second >= act[mid].first.second + pr.first) high = mid;
			else low = mid + 1;
		}
		if (low < act.size() && act[low].second != i) res = max(res, off(act[low].first, pr));
		if (low-1 >= 0 && act[low-1].second != i) res = max(res, off(act[low-1].first, pr));
	}

	res = min(res, dist);
	cout << res << '\n';

}
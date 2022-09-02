#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	// "Can't jump down" is a useless condition, if we are above a position we could have jumped to it before

	int n;
	cin >> n;

	vector<int> as(n), bs(n);
	for (int& a : as) cin >> a;
	for (int& b : bs) cin >> b;

	vector<vector<pair<int, ll>>> g(2*n + 1);
	for (int i = 0; i < n; ++i) {
		if (as[i] > i) {
			g[i].emplace_back(2*n, 1);
		} else {
			g[i].emplace_back(i - as[i] + n, 1);
		}
		if (i + 1 < n) g[i + n].emplace_back(i + n + 1, 0);
		g[i + n].emplace_back(i + bs[i], 0);
	}
	auto res = djikstra(n-1, g);
	if (res.first[2*n] >= INF) {
		cout << -1 << '\n';
	} else {
		cout << res.first[2*n] << '\n';

		/*
		for (int i = 0; i <= 2*n; ++i) cerr << res.first[i] << ' '; cerr << '\n';
		for (int i = 0; i <= 2*n; ++i) cerr << res.second[i] << ' '; cerr << '\n';
		*/

		vector<int> ord = {0};
		for (int i = 2*n; i != n - 1; i = res.second[i]) {
			if (n <= res.second[i] && i < n) ord.push_back(res.second[i] - n + 1);
		}

		reverse(ord.begin(), ord.end());
		for (int h : ord) cout << h << ' '; cout << '\n';
	}
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Struct for priority queue operations on index set [0, n-1]
// push(i, v) overwrites value at position i if one already exists
// decKey is faster but requires that the new key is smaller than the old one
struct Prique {
	const ll INF = 4 * (ll)1e18;
	vector<pair<ll, int>> data;
	const int n;

	Prique(int siz) : n(siz), data(2*siz, {INF, -1}) { data[0] = {-INF, -1}; }
	bool empty() const { return data[1].second >= INF; }
	pair<ll, int> top() const { return data[1]; }

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

void solve() {
	int n, m;
	ll x;
	cin >> n >> m >> x;

	vector<pair<ll, int>> blocks(n);
	for (int i = 0; i < n; ++i) {
		cin >> blocks[i].first;
		blocks[i].second = i;
	}
	sort(blocks.rbegin(), blocks.rend());

	Prique pq(m);
	for (int i = 0; i < m; ++i) pq.push(i, 0);

	vector<ll> cur(n, 0);
	vector<int> res(n, -1);
	for (auto pr : blocks) {
		int i = pq.pop().second;
		cur[i] += pr.first;
		res[pr.second] = i+1;
		pq.push(i, cur[i]);
	}

	cout << "YES\n";
	for (int& v : res) cout << v << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
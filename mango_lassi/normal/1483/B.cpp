#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

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
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	vector<int> nxt(n);
	for (int i = 0; i < n; ++i) nxt[i] = (i+1) % n;
	
	Prique que(n);
	for (int i = 0; i < n; ++i) {
		if (gcd(as[i], as[nxt[i]]) == 1) que.decKey(i, i);
	}
	
	vector<int> res;
	while(true) {
		auto pr = que.pop();
		if (pr.second == -1) break;

		ll round = pr.first / n;
		int i = pr.second;
		if (nxt[i] == -1) continue;

		int t = nxt[i];
		nxt[i] = nxt[t];
		nxt[t] = -1;
		res.push_back(t);

		if (t != i && gcd(as[i], as[nxt[i]]) == 1) {
			que.decKey(i, n*(round + 1) + i);
		}
	}
	cout << res.size() << ' ';
	for (auto i : res) cout << i+1 << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
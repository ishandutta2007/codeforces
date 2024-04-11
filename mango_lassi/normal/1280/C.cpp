#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;

const int N = 2 * (int)1e5;
vector<pair<int, ll>> conns[N];
int siz[N];

ll dfsGood(int i, int p) {
	siz[i] = 1;
	ll ans = 0;
	for (auto pr : conns[i]) {
		int t = pr.first;
		if (t == p) continue;

		ll sub = dfsGood(t, i);
		ans += sub;
		siz[i] += siz[t];
		if (siz[t] & 1) ans += pr.second;
	}
	return ans;
}
ll dfsBad(int i, int p, int n) {
	ll ans = 0;
	for (auto pr : conns[i]) {
		int t = pr.first;
		if (t == p) continue;

		ll sub = dfsBad(t, i, n);
		ans += sub + min(siz[t], n - siz[t]) * pr.second;
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < 2*n; ++i) conns[i].clear();
	for (int i = 0; i < 2*n-1; ++i) {
		int a, b;
		ll d;
		cin >> a >> b >> d;
		--a; --b;
		conns[a].push_back({b, d});
		conns[b].push_back({a, d});
	}

	// Shortest distance: At every node, pay for edge to exactly the subtrees of odd size.
	// Longest distance: Pay for every edge equal to the minimum number of nodes on one of its sides
	ll good = dfsGood(0, -1);
	ll bad = dfsBad(0, -1, 2*n);
	cout << good << ' ' << bad << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
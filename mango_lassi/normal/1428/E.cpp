#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int MA = 1e6;

ll sq(ll v) { return v*v; }

ll cost(ll v, ll m) {
	ll v0 = v / m;
	ll v1 = v0 + 1;
	ll c1 = v % m;
	ll c0 = m - c1;
	return c0 * sq(v0) + c1 * sq(v1);
}

void solve() {
	ll n, k;
	cin >> n >> k;
	k = k - n; // k = number of splits we need to make

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	ll res = 0;
	vector<ll> counts(n);
	priority_queue<pair<ll, int>> que;
	for (int i = 0; i < n; ++i) {
		counts[i] = 1;
		res += cost(as[i], 1);
		que.push({cost(as[i], counts[i]) - cost(as[i], counts[i] + 1), i});
	}
	for (int j = 0; j < k; ++j) {
		int i = que.top().second;
		que.pop();
		res += cost(as[i], counts[i] + 1) - cost(as[i], counts[i]);
		++counts[i];
		que.push({cost(as[i], counts[i]) - cost(as[i], counts[i] + 1), i});
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}
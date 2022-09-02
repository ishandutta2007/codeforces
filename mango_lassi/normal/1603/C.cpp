#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

const ll H = 1e5;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	ll res = 0;
	vector<pair<ll, ll>> vals, nxt;
	for (int i = n-1; i >= 0; --i) {
		vals.emplace_back(H, 1ll); // End here
		nxt.clear();

		ll a = as[i];
		for (auto pr : vals) {
			ll b = pr.first;
			if (a <= b) {
				nxt.emplace_back(as[i], pr.second);
			} else {
				ll x = (a + (b-1)) / b;
				res = (res + (ll)(i + 1) * (x - 1) * pr.second) % MOD;
				nxt.emplace_back(a / x, pr.second);
			}
		}

		vals.clear();
		for (int j = 0; j < nxt.size(); ++j) {
			if (j > 0 && nxt[j].first == nxt[j-1].first) vals.back().second += nxt[j].second;
			else vals.emplace_back(nxt[j]);
		}

		/*
		cerr << i << ' ' << res << ": ";
		for (auto pr : vals) cerr << "(" << pr.first << ' ' << pr.second << ") ";
		cerr << '\n';
		*/
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) solve();
}
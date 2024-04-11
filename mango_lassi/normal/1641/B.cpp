#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void revPref(ll k, ll& add, vector<ll>& as, vector<pair<ll, ll>>& ins, vector<ll>& ts) {
	for (ll i = 0; i < k; ++i) ins.emplace_back(add + k + i, as[i]);
	ts.push_back(2 * k);
	add += 2 * k;

	for (ll j = 0; j <= k-1-j; ++j) swap(as[j], as[k-1-j]);
}


void solve() {
	ll n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	// Necessary condition: each lleger occurs an even number of times
	// Also sufficient: we can reverse a prefix!
	// Loop until you find first value that equals v0, then do two prefix flips

	ll add = 0;
	vector<pair<ll, ll>> ins;
	vector<ll> ts;
	while(! as.empty()) {
		ll j = 1;
		for (; j < as.size(); ++j) {
			if (as[j] == as[0]) break;
		}
		if (j == as.size()) {
			cout << -1 << '\n';
			return;
		} else if (j == 1) {
			ts.push_back(2);
			add += 2;
			
			vector<ll> tmp;
			for (ll i = 2; i < as.size(); ++i) tmp.push_back(as[i]);
			as = tmp;
		} else {
			revPref(j, add, as, ins, ts);
			revPref(j + 1, add, as, ins, ts);
		}
	}

	cout << ins.size() << '\n';
	for (auto pr : ins) cout << pr.first << ' ' << pr.second << '\n';

	cout << ts.size() << '\n';
	for (ll t : ts) cout << t << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll t;
	cin >> t;
	for (ll ti = 0; ti < t; ++ti) solve();
}
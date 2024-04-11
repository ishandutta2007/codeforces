#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18 + 7;

vector<pair<ll, ll>> build(const vector<ll>& vec) {
	ll cur = 0, need = 0;
	vector<pair<ll, ll>> res;
	for (ll v : vec) {
		cur += v;
		need = max(need, -cur);
		if (cur > 0) {
			res.emplace_back(need, cur);
			cur = 0;
			need = 0;
		}
	}
	res.emplace_back(need, cur);
	reverse(res.begin(), res.end());

	return res;
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<ll> le(k), ri(n - k);
	for (int i = k-1; i >= 0; --i) cin >> le[i];
	for (int i = 0; i < n - k; ++i) cin >> ri[i];
	
	auto sta_le = build(le);
	auto sta_ri = build(ri);
	
	ll cur = 0;
	while(! sta_le.empty() && ! sta_ri.empty()) {
		if (sta_le.back().first <= cur) {
			cur += sta_le.back().second;
			sta_le.pop_back();
		} else if (sta_ri.back().first <= cur) {
			cur += sta_ri.back().second;
			sta_ri.pop_back();
		} else break;
	}

	if (sta_le.empty() || sta_ri.empty()) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
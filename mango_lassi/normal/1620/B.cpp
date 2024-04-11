#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> readVec() {
	int k;
	cin >> k;
	vector<ll> xs(k);
	for (ll& x : xs) cin >> x;
	return xs;
}

void solve() {
	ll w, h;
	cin >> w >> h;
	vector<ll> xs0 = readVec();
	vector<ll> xs1 = readVec();
	vector<ll> ys0 = readVec();
	vector<ll> ys1 = readVec();

	ll res = 0;
	for (auto x : xs0) {
		res = max(res, (ys0.back() - ys0[0]) * x);
		res = max(res, (ys1.back() - ys1[0]) * (w - x));
		res = max(res, (xs1.back() - xs1[0]) * h);
	}
	for (auto x : xs1) {
		res = max(res, (ys0.back() - ys0[0]) * x);
		res = max(res, (ys1.back() - ys1[0]) * (w - x));
		res = max(res, (xs0.back() - xs0[0]) * h);
	}
	for (auto y : ys0) {
		res = max(res, (xs0.back() - xs0[0]) * y);
		res = max(res, (xs1.back() - xs1[0]) * (h - y));
		res = max(res, (ys1.back() - ys1[0]) * w);
	}
	for (auto y : ys1) {
		res = max(res, (xs0.back() - xs0[0]) * y);
		res = max(res, (xs1.back() - xs1[0]) * (h - y));
		res = max(res, (ys0.back() - ys0[0]) * w);
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
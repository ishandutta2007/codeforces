#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;

	ll res0 = 0, res1 = 0, dt0 = 0, dt1 = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a & 1) {
			++dt0;
			++dt1;
		} else {
			--dt0;
			--dt1;
		}
		if (i & 1) {
			++dt0;
			--dt1;
		} else {
			--dt0;
			++dt1;
		}
		res0 += abs(dt0);
		res1 += abs(dt1);
	}

	ll res = INF;
	if (dt0 == 0) res = min(res, res0 / 2);
	if (dt1 == 0) res = min(res, res1 / 2);
	if (res == INF) res = -1;
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ti = 0; ti < n; ++ti) solve();
}
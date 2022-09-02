#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll hp, ap;
	cin >> hp >> ap;

	ll hm, am;
	cin >> hm >> am;

	ll k, w, a;
	cin >> k >> w >> a;

	bool win = 0;
	for (int x = 0; x <= k; ++x) {
		ll hr = hp + a * x;
		ll ar = ap + w * (k-x);
		win |= ((hr + am-1) / am >= (hm + ar-1) / ar);
	}
	cout << (win ? "YES" : "NO") << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll h, w, n;
	cin >> h >> w >> n;

	ll res = 1;
	while((h % 2) == 0) {
		res *= 2;
		h /= 2;
	}
	while((w % 2) == 0) {
		res *= 2;
		w /= 2;
	}
	if (res >= n) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
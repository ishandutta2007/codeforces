#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll h, w, k;
	cin >> h >> w >> k;

	int hori_odd = 0, vert_odd = 0;
	ll hori = 0, vert = 0;
	for (int i = 0; i < k; ++i) {
		ll a;
		cin >> a;
		if (a / h >= 2) {
			vert += a / h;
			vert_odd += (a / h) - 2;
		}
		if (a / w >= 2) {
			hori += a / w;
			hori_odd += (a / w) - 2;
		}
	}

	if ((hori >= h && ((hori % 2 == h % 2) || (hori_odd))) || (vert >= w && ((vert % 2 == w % 2 ) || (vert_odd)))) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
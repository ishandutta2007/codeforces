#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
	int n;
	ld k;
	cin >> n >> k;
	vector<ld> pts(n);
	for (ld& v : pts) cin >> v;

	ld ans = 0;
	ld x0 = 0, x1 = k;
	int i = 0, j = n-1;
	while(i <= j) {
		ld t0 = (pts[i] - x0) / (i+1);
		ld t1 = (x1 - pts[j]) / (n-j);
		if (t0 < t1) {
			ans += t0;
			x0 += (i+1) * t0;
			x1 -= (n-j) * t0;
			++i;
		} else {
			ans += t1;
			x0 += (i+1) * t1;
			x1 -= (n-j) * t1;
			--j;
		}
	}
	ans += (x1 - x0) / (n+2);
	cout << setprecision(20) << fixed << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (int)1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> as(n);
	for (int& a : as) cin >> a;

	vector<int> pref(n+1, 0), suff(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i-1];
		if (i >= 3) {
			if (as[i-3] > as[i-2] && as[i-2] < as[i-1]) ++pref[i];
			else if (as[i-3] < as[i-2] && as[i-2] > as[i-1]) ++pref[i];
		}
	}
	for (int i = n-1; i >= 0; --i) {
		suff[i] = suff[i+1];
		if (i + 3 <= n) {
			if (as[i] > as[i+1] && as[i+1] < as[i+2]) ++suff[i];
			else if (as[i] < as[i+1] && as[i+1] > as[i+2]) ++suff[i];
		}
	}

	int res = n;
	for (int i = 0; i < n; ++i) {
		if (i > 1 && i+2 < n) {
			int hi = INF;
			int lo = -INF;
			if (as[i-2] > as[i-1]) hi = as[i-1];
			if (as[i-2] < as[i-1]) lo = as[i-1];
			if (as[i+1] > as[i+2]) lo = as[i+1];
			if (as[i+1] < as[i+2]) hi = as[i+1];
			
			res = min(res, pref[i] + suff[i+1] + (hi < lo));
		} else {
			res = min(res, pref[i] + suff[i+1]);
		}
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
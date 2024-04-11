#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
	int k;
	cin >> k;

	ll tot = 0;
	vector<ll> counts(k);
	for (ll& c : counts) {
		cin >> c;
		tot += c;
	}
	if (tot == 1) return true;
	sort(counts.rbegin(), counts.rend());
	
	ll cur = 2;
	vector<ll> vals = {1, 1};
	while(cur < tot) {
		int h = vals.size();
		vals.push_back(vals[h-2] + vals[h-1]);
		cur += vals.back();
	}
	if (cur != tot) return false;
	
	int m = vals.size();
	vector<ll> apps(m, 0), lows(m, 0);
	for (int i = 0; i < counts.size(); ++i) {
		ll v = counts[i];
		bool ban = 0;
		for (int j = m-1; j >= 0; --j) {
			if (ban) ban = 0;
			else if (vals[j] <= v) {
				v -= vals[j];
				ban = 1;
				
				++apps[j];
				if (v == 0) ++lows[j];
			}
		}
		if (v != 0) return false;
	}
	for (int j = 0; j < m; ++j) {
		if (apps[j] > 1) {
			if (lows[j] == 0 || (j % 2 == 0)) return false;
			--apps[j];
			--lows[j];
			for (int j2 = j - 1; j2 >= 0; j2 -= 2) ++apps[j2];
		}
	}
	for (int j = 0; j < m; ++j) {
		if (apps[j] != 1) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		bool res = solve();
		cout << (res ? "YES" : "NO") << '\n';
	}
}
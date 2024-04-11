#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int x;
		string s;
		cin >> x >> s;

		ll n = s.size();
		for (int i = 1; i <= x; i++) {
			ll was = s.size();
			n = (n + (n - i + MOD) % MOD * (s[i - 1] - '1') % MOD) % MOD;
			for (int cnt = 0; cnt < s[i - 1] - '1' && s.size() <= x; cnt++) {
				for (int j = i; j < was && s.size() <= x; j++) {
					s.push_back(s[j]);
				}
			}
		}

		cout << n << '\n';
	}
}
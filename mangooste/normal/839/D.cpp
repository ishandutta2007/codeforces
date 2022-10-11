#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAXA = 1000001;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	vector<int> p2(MAXA, 1);
	for (int i = 1; i < MAXA; i++) {
		p2[i] = p2[i - 1] * 2 % MOD;
	}

	vector<int> cnt(MAXA, 0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int j = 1; j * j <= x; j++) {
			if (x % j == 0) {
				cnt[j]++;
				cnt[x / j] += 1 - (j * j == x);
			}
		}
	}

	vector<int> g(MAXA, 0);
	for (int i = MAXA - 1; i; i--) {
		if (!cnt[i]) {
			continue;
		}
		g[i] = (ll)p2[cnt[i] - 1] * cnt[i] % MOD;
		for (int j = i * 2; j < MAXA; j += i) {
			g[i] -= g[j];
			if (g[i] < 0) {
				g[i] += MOD;
			}
		}
	}

	int ans = 0;
	for (int i = 2; i < MAXA; i++) {
		ans += (ll)i * g[i] % MOD;
		if (ans >= MOD) {
			ans -= MOD;
		}
	}

	cout << ans << '\n';
}
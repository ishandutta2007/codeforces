#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int tt; cin >> tt;
	while (tt--) {
		int n, m, sz; cin >> n >> m >> sz;
		string s; cin >> s;
		long long ans = 1LL * n * m;
		vector<int> cnt(26, 0);
		for (auto c : s) cnt[c - 'A']++;
		for (int i = 0; i < 26; ++i) {
			vector<bool> f(sz - cnt[i] + 1, 0);
			f[0] = 1;
			for (int j = 0; j < 26; ++j) if (j != i) {
				for (int k = sz - cnt[i]; k >= 0; --k) if (f[k]) f[k + cnt[j]] = 1;
			}
			for (int j = 0; j <= sz - cnt[i]; ++j) if (f[j]) {
				int num_x = max(0, n - j);
				int num_y = max(0, m - (sz - cnt[i] - j));
				if (num_x + num_y > cnt[i]) continue;
				ans = min(ans, 1LL * num_x * num_y);
			}
		}
		cout << ans << '\n'; 
	}
}
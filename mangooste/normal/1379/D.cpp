#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, h, m, k;
	cin >> n >> h >> m >> k;
	m /= 2;
	k--;
	vector<int> times;
	vector<pair<int, int>> bad;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		y -= (y >= m) * m;
		times.push_back(y);
		bad.emplace_back(y, i);
	}
	sort(times.begin(), times.end());
	times.resize(unique(times.begin(), times.end()) - times.begin());
	sort(bad.begin(), bad.end());
	int when = -1, ans = n + 1;
	for (auto &fir : times) {
		int res = 0;
		auto get = [&](int L, int R) -> int {
			return upper_bound(bad.begin(), bad.end(), pair<int, int>{R, n}) - lower_bound(bad.begin(), bad.end(), pair<int, int>{L, -1});
		};
		res += (fir > 0) * get(max(0, fir - k), fir - 1);
		res += (fir < k) * get(fir + m - k, m - 1);
		if (ans > res) {
			ans = res;
			when = fir;
		}
	}
	cout << ans << ' ' << when << '\n';
	for (auto &[x, num] : bad) {
		bool need = false;
		auto inter = [](int L, int R, int x) -> bool {
			return L <= x && x <= R;
		};
		need |= (when > 0) && inter(max(0, when - k), when - 1, x);
		need |= (when < k) && inter(when + m - k, m - 1, x);
		if (need) {
			cout << num + 1 << ' ';
		}
	}
}
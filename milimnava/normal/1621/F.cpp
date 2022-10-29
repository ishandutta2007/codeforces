#include <bits/stdc++.h>
using namespace std;

char foo[100005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, A, b, c;
		cin >> n >> A >> b >> c;
		for (int i = 1; i <= n; i++) cin >> foo[i];
		vector<pair<int, int> > zero;
		int cnt = 0;
		for (int l = 1, r; l <= n; l = r + 1) {
			r = l;
			while (r < n && foo[l] == foo[r + 1]) ++r;
			if (foo[l] == '0') {
				if (l == 1 || r == n) zero.emplace_back(1, r - l);
				else zero.emplace_back(0, r - l);
			} else {
				cnt += r - l;
			}
		}
		sort(zero.begin(), zero.end());
		long long ans = 0;
		auto solve = [&](int cnt, int st) {
			vector<pair<int, int> > a = zero;
			long long sum = st;
			int pos = 0, zcnt = 0, zcnt2 = 0;
			while (pos < (int)a.size() && a[pos].second == 0) {
				zcnt += 1 - a[pos].first;
				zcnt2 += a[pos].first;
				++pos;
			}
			ans = max(ans, sum);
			while (1) {
				if (pos < (int)a.size()) ans = max(ans, sum + A);
				if (cnt) {
					if (pos >= (int)a.size()) {
						if (!zcnt && !zcnt2) break;
						if (zcnt) {
							--zcnt;
						} else {
							--zcnt2; --cnt;
						}
						sum += b - c;
						ans = max(ans, sum);
						continue;
					}
					sum += A + b;
					--cnt; --a[pos].second;
					while (pos < (int)a.size() && a[pos].second == 0) {
						zcnt += 1 - a[pos].first;
						zcnt2 += a[pos].first;
						++pos;
					}
				} else {
					if (!zcnt || b <= c) break;
					--zcnt;
					sum += b - c;
				}
				ans = max(ans, sum);
			}
		};
		solve(cnt, 0);
		if (cnt) solve(cnt - 1, b);
		cout << ans << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	long long n, m;
	cin >> n >> m;
	long long l, r;
	cin >> l >> r;
	vector<array<long long, 4>> res(n + 1, {-1, -1, -1, -1});
	for (long long g = 1; g <= n; g++)
		for (long long x1 = g; x1 <= n; x1 += g) {
			long long k = x1 / g;
			long long min_t = 1;
			long long max_t = n / g - k;
			long long min_v = (l + x1 - 1) / x1;
			long long max_v = min(m, r / x1);
			if (max_t < min_t || max_v < min_v)
				continue;
			{
				for (long long t = min_t; t <= max_t && (k + t) * t <= max_v && res[x1][0] == -1; t++) {
					long long p = (min_v + k + t - 1) / (k + t);
					if (p * (k + t) <= m && (k + t) * p <= max_v) {
						res[x1][0] = x1;
						res[x1][1] = (k + t) * p;
						res[x1][2] = (k + t) * g;
						res[x1][3] = k * p;
					}
				}
			}
			{
				for (long long p = 1; (k + p) * p <= max_v && res[x1][0] == -1; p++) {
					long long t = (min_v + p - 1) / p - k;
					if (min_t <= t && t <= max_t && (k + t) * p <= max_v) {
						res[x1][0] = x1;
						res[x1][1] = (k + t) * p;
						res[x1][2] = (k + t) * g;
						res[x1][3] = k * p;
					}
				}
			}
		}

	for (int i = 1; i <= n; i++) {
		if (res[i][0] == -1)
			cout << "-1\n";
		else
			cout << res[i][0] << ' ' << res[i][1] << ' ' << res[i][2] << ' ' << res[i][3] << '\n';
	}
}
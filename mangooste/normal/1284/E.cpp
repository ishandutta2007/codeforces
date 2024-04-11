#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define vec point

struct point {
	ll x, y;

	point(ll x = 0, ll y = 0) : x(x), y(y) {}

	vec operator - (point p) {
		return point(x - p.x, y - p.y);
	}

	ll operator % (vec v) {
		return x * v.y - y * v.x;
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<point> ps(n);
	for (auto &p : ps) {
		cin >> p.x >> p.y;
	}

	ll ans = 0;
	for (int p = 0; p < n; p++) {
		vector<vec> all;
		for (int i = 0; i < n; i++) {
			if (p != i) {
				all.push_back(ps[i] - ps[p]);
			}
		}

		auto where = [&](point &p) -> int {
			if (p.x >= 0) {
				return p.y >= 0 ? 0 : 3;
			} else {
				return p.y >= 0 ? 1 : 2;
			}
		};

		sort(all.begin(), all.end(), [&](vec &v1, vec &v2) {
			int w1 = where(v1);
			int w2 = where(v2);
			return w1 < w2 || (w1 == w2 && v1 % v2 > 0);
		});

		ll res = (ll)(n - 4) * (n - 3) * (n - 2) * (n - 1) / 24;
		for (int i = 0, j = 0; i < n - 1; i++) {
			if (all[i] % all[(i - 1 + n - 1) % (n - 1)] > 0) {
				res = 0;
				break;
			}

			while (all[i] % all[j] >= 0) {
				j = (j + 1) % (n - 1);
			}

			int cnt = max(0, j - i - 1 + (n - 1) * (i > j));
			res -= (ll)cnt * (cnt - 1) * (cnt - 2) / 6;
		}

		ans += res;
	}

	cout << ans;
}
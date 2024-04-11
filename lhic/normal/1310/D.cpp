#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int N = 90;
const int IT = 10000;

const ll INF = 1e18;
ll dd[N][N];

int n, k;
int cl[N];

ll dp[N];
ll dp2[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());  // f*ck hackers!!!
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> dd[i][j];
		}
	}

	ll ans = INF;

	for (int it = 0; it < IT; ++it) {
		for (int i = 0; i < n; ++i) {
			cl[i] = rnd() % 2;
		}
		for (int i = 0; i < n; ++i) {
			if (cl[i] == cl[0]) {
				dp[i] = INF;
			} else {
				dp[i] = dd[0][i];
			}
		}

		for (int ii = 1; ii < k; ++ii) {
			fill(dp2, dp2 + n, INF);
			for (int i = 0; i < n; ++i) {
				if (dp[i] >= INF) {
					continue;
				}
				for (int j = 0; j < n; ++j) {
					if (cl[j] != cl[i]) {
						dp2[j] = min(dp2[j], dp[i] + dd[i][j]);
					}
				}
			}
			memcpy(dp, dp2, sizeof(dp));
		}
		ans = min(ans, dp[0]);
	}

	cout << ans << "\n";
	return 0;
}
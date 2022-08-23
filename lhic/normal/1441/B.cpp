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

const ll MOD = 998244353;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
const int N = 210000;
const int LG = 20;
const int INF = 1e9;

vector<int> eds[2][N];

int dd1[LG][N];
int n, m;
int was[N];
pair<int, int> dd[N * 2];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[0][a].emplace_back(b);
		eds[1][b].emplace_back(a);
	}

	for (int i = 0; i < LG; ++i) {
		for (int j = 0; j < N; ++j) {
			dd1[i][j] = INF;
		}
	}

	dd1[0][0] = 0;
	for (int i = 0; i < LG; ++i) {
		queue<pair<int, int>> qq;
		vector<pair<int, int>> vv;
		for (int j = 0; j < n; ++j) {
			if (dd1[i][j] < INF) {
				vv.emplace_back(dd1[i][j], j);
			}
		}
		memset(was, 0, sizeof(was));
		sort(ALL(vv));
		reverse(ALL(vv));
		while (qq.size() + vv.size() > 0) {
			while (!vv.empty() && (qq.empty() || qq.back().first == vv.back().first)) {
				qq.push(vv.back());
				vv.pop_back();
			}

			int x = qq.front().second;
			qq.pop();
			if (was[x]) {
				continue;
			}
			was[x] = 1;

			if (i + 1 < LG) {
				dd1[i + 1][x] = min(dd1[i + 1][x], dd1[i][x]);
			}

			for (int u : eds[i & 1][x]) {
				if (dd1[i][u] > dd1[i][x] + 1) {
					dd1[i][u] = dd1[i][x] + 1;
					qq.emplace(dd1[i][u], u);
				}
			}
		}
	}

	ll ans = INF;
	for (int i = 0; i < LG; ++i) {
		ans = min(ans, ll(dd1[i][n - 1]) + (1ll << (i)) - 1);
	}
	if (ans < INF) {
		cout << ans << "\n";
		return 0;
	}

	for (int i = 0; i < n * 2; ++i) {
		dd[i] = {INF, INF};
	}
	dd[0] = {0, 0};


	set<pair<pair<int, int>, int>> ss;
	ss.emplace(dd[0], 0);

	while (!ss.empty()) {
		int x = ss.begin()->second;
		ss.erase(ss.begin());
		int bs = x;
		int ad = 0;
		int c = 0;
		int oth = x + n;
		if (x >= n) {
			bs = x - n;
			ad = n;
			c = 1;
			oth = x - n;
		}


		auto nw = dd[x];
		nw.first += 1;
		if (dd[oth] > nw) {
			ss.erase(make_pair(dd[oth], oth));
			dd[oth] = nw;
			ss.emplace(dd[oth], oth);
		}

		for (int u : eds[c][bs]) {
			auto nw = dd[x];
			nw.second += 1;
			if (dd[u + ad] > nw) {
				ss.erase(make_pair(dd[u + ad], u + ad));
				dd[u + ad] = nw;
				ss.emplace(dd[u + ad], u + ad);
			}
		}
	}

	auto an = min(dd[n - 1], dd[n + n - 1]);

	ll cur = pw(2, an.first);
	ans = (cur + an.second - 1 + MOD) % MOD;
	cout << ans << "\n";

	return 0;
}
#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MAXN = 120;

ll v[MAXN];
int n, m;
vector<int> vv;

ll ans[4];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	for (int i = 1; i <= m; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			cnt += (v[j] / i) % 2;
		}
		if (cnt % 2 == 0)
			++ans[3];
		else
			++ans[2];
	}
	for (ll sum = 3; sum < 2 * m; ++sum) {
		vv.clear();
		for (int i = 0; i < n; ++i)
			vv.push_back(v[i] % sum);
		sort(vv.begin(), vv.end());
		int x = 1;
		int y = sum - x;
		if (y > m) {
			int d = y - m;
			x += d;
			y -= d;
		}
		int nx = 0;
		int ny = vv.size();
		int nx2 = 0;
		int lb = sum / 2;
		if (sum % 2 == 0)
			--lb;
		int rb = sum - lb;
		while (x < y) {
			while (nx < vv.size() && vv[nx] < x)
				++nx;
			while (ny > 0 && vv[ny - 1] >= y)
				--ny;
			while (nx2 < vv.size() && vv[nx2] < 2 * x)
				++nx2;
			int dd = min(lb - x + 1, y - rb + 1);
			if (nx < vv.size())
				dd = min(dd, vv[nx] - x + 1);
			if (ny > 0)
				dd = min(dd, y - vv[ny - 1]);
			if (nx2 < vv.size())
				dd = min(dd, vv[nx2] / 2 - x + 1);
			if (dd <= 0)
				break;
			int aa = vv.size() - ny;
			int bb = vv.size() - nx - aa;
			int cc = vv.size() - nx2;
			if (!bb && cc <= 1) {
				if (cc == 1) {
					if (aa & 1)
						ans[2] += 2 * dd;
					else
						ans[0] += dd, ans[1] += dd;
				}
				else {
					if (aa & 1)
						ans[2] += 2 * dd;
					else
						ans[3] += 2 * dd;
				}
			}
			else {
				ans[1] += dd;
				ans[0] += dd;
			}
			x += dd;
			y -= dd;
		}
	}
	for (int i = 0; i < 4; ++i)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}
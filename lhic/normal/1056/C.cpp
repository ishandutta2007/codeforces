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

const int MAXN = 21000;

int n, m;
int p[MAXN];

int us[MAXN];
int go[MAXN];
int gg[MAXN];
int ds[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < 2 * n; ++i) {
		cin >> p[i];
	}
	vector<pair<int, int>> vv;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		us[a] = us[b] = 1;
		go[a] = b, go[b] = a;
		if (p[a] < p[b])
			swap(a, b);
		gg[a] = gg[b] = vv.size();
		vv.emplace_back(a, b);
	}
	int t;
	cin >> t;
	int cnt = 2 * n;
	if (t == 2) {
		while (cnt > 0) {
			int x;
			cin >> x;
			--x;
			--cnt;
			if (us[x]) {
				int pp = gg[x];
				ds[pp] = 1;
				if (x == vv[pp].first) {
					cout << vv[pp].second + 1 << "\n";
					cout.flush();
					--cnt;
				}
				else {
					cout << vv[pp].first + 1 << "\n";
					cout.flush();
					--cnt;
				}
			}
			else {
				us[x] = 1;
				break;
			}
		}
	}
	while (cnt > 0) {
		int fl = 0;
		for (int i = 0; i < vv.size(); ++i) {
			if (!ds[i]) {
				cout << vv[i].first + 1 << "\n";
				cout.flush();
				ds[i] = 1;
				--cnt;
				fl = 1;
				int tmp;
				cin >> tmp;
				--cnt;
				break;
			}
		}
		if (fl)
			continue;
		int mx = -1;
		for (int i = 0; i < n * 2; ++i)
			if (!us[i] && (mx == -1 || p[i] > p[mx]))
				mx = i;
		cout << mx + 1 << "\n";
		cout.flush();
		us[mx] = 1;
		--cnt;
		if (cnt) {
			int tmp;
			cin >> tmp;
			--tmp;
			us[tmp] = 1;
			--cnt;
		}
	}
	return 0;

}
#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

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

const int MAXN = 120000;

int was[MAXN];
vector<pair<int, int>> eds[MAXN];
vector<int> vv;

int h[MAXN];
int xr[MAXN];

void dfs1(int v) {
	was[v] = 1;
	for (auto e: eds[v]) {
		int u = e.first;
		if (!was[u]) {
			h[u] = h[v] + 1;
			xr[u] = xr[v] ^ e.second;
			dfs1(u);
		}
		else if (h[u] <= h[v]) {
			vv.push_back(xr[u] ^ xr[v] ^ e.second);
		}
	}
}

int n, m;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		--x, --y;
		eds[x].emplace_back(y, w);
		eds[y].emplace_back(x, w);
	}
	dfs1(0);
	int now = 0;
	for (int i = 30; i >= 0; --i) {
		int fl = 0;
		for (int j = now; j < vv.size(); ++j) {
			if ((vv[j] >> i) & 1) {
				swap(vv[j], vv[now]);
				fl = 1;
				break;
			}
		}
		if (!fl)
			continue;
		for (int j = now + 1; j < vv.size(); ++j) {
			if ((vv[j] >> i) & 1)
				vv[j] ^= vv[now];
		}
		++now;
	}
	int ans = xr[n - 1];
	for (int i = 0; i < vv.size(); ++i) {
		if ((ans ^ vv[i]) < ans)
			ans ^= vv[i];
	}
	cout << ans << "\n";
	return 0;
}
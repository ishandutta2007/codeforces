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
const int MAXN = 120000;
const int LOG = 20;

int n, m, q;
vector<int> eds[MAXN];
int h[MAXN];
int up[MAXN][LOG];
int was[MAXN];
int tin[MAXN];
int tout[MAXN];
int tm1;

void dfs1(int v) {
	tin[v] = tm1++;
	was[v] = 1;
	up[v][0] = v;
	for (int u: eds[v]) {
		if (!was[u]) {
			h[u] = h[v] + 1;
			dfs1(u);
		}
		else {
			if (h[u] < h[up[v][0]])
				up[v][0] = u;
		}
	}
	tout[v] = tm1;
}

bool is_p(int a, int b) {
	return tin[a] <= tin[b] && tin[b] < tout[a];
}

int get(int a, int b) {
	int ans = 0;
	if (!is_p(a, b)) {
		for (int i = LOG - 1; i >= 0; --i) {
			if (!is_p(up[a][i], b))
				a = up[a][i], ans += (1 << i);
		}
		a = up[a][0];
		ans += 1;
	}
	if (!is_p(b, a)) {
		for (int i = LOG - 1; i >= 0; --i) {
			if (!is_p(up[b][i], a))
				b = up[b][i], ans += (1 << i);
		}
		b = up[b][0];
		ans += 1;
	}
	return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m >> q;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0);
	for (int i = 1; i < LOG; ++i)
		for (int j = 0; j < n; ++j)
			up[j][i] = up[up[j][i - 1]][i - 1];
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		cout << min(get(a, b), get(b, a)) << "\n";
	}
	return 0;
}
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
const int MAXN = 210000;

int n;
vector<int> eds[MAXN];
ll sz[MAXN];
ll cc[2];
ll ans = 0;

void dfs1(int v, int c, int p) {
	++cc[c];
	sz[v] = 1;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		dfs1(u, c ^ 1, v);
		sz[v] += sz[u];
	}
	ans += sz[v] * (n - sz[v]);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0, 0, -1);
	ans += cc[0] * cc[1];
	ans /= 2;
	cout << ans << "\n";
	return 0;
}
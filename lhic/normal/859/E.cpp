#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
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
const int MAXN = 220000;
const ll MOD = 1e9 + 7;

int n;
int was[MAXN * 2];
vector<int> beds[MAXN * 2];
int go[MAXN * 2];
int tm1;

ll dfs1(int v) {
	was[v] = 1;
	ll ans = 1;
	for (int u: beds[v])
		ans = (ans + dfs1(u)) % MOD;
	return ans;
}

int dfs2(int v) {
	was[v] = tm1;
	if (was[go[v]] == tm1) {
		return 1;
	}
	if (was[go[v]])
		return 0;
	return dfs2(go[v]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; ++i)
		go[i] = -1;
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		go[x] = y;
		beds[y].push_back(x);
	}
	ll ans = 1;
	for (int i = 0; i < 2 * n; ++i) {
		if (go[i] == -1)
			ans = (ans * dfs1(i)) % MOD;
		else if (go[i] == i) {
			was[i] = 1;
		}
	}
	tm1 = 1;
	for (int i = 0; i < 2 * n; ++i) {
		if (was[i])
			continue;
		++tm1;
		if (dfs2(i))
			ans = (ans * 2) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
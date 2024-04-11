#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;

const int maxn = 1010, mod = 1e9 + 7;
int qpow(int a, int p) {
	int ans = 1; a %= mod;
	while (p) {
		if (p & 1) ans = 1ll * ans * a % mod;
		a = 1ll * a * a % mod, p >>= 1;
	}
	return ans;
}
#define inc(x, y) ((x) += (y), (x) = (x) >= mod ? (x) - mod : (x))
struct Tree {
	int n;
	vi e[maxn];
	void add(int x, int y) { e[x].push_back(y), e[y].push_back(x); }
}S,T;
int son[maxn],f[maxn][1 << 12],bel[1 << 12],tot;
void dfs(int u, int pre) {
	son[u] = 0;
	for (int v : T.e[u]) {
		if (v == pre) continue;
		dfs(v, u), son[u] |= (1 << (v - 1));
	}
}
void dp(int u, int pre) {
	f[u][0] = 1;
	for (int v : S.e[u]) {
		if (v == pre) continue;
		dp(v, u);
		for (int s = tot; s >= 0; --s) if (f[u][s])
			for (int y = 1; y <= T.n; ++y)
				if (!s || (!((s >> (y - 1)) & 1) && ((bel[s] >> (y - 1)) & 1)))
					inc(f[u][s | (1 << (y - 1))], 1ll * f[u][s] * f[v][son[y]] % mod);
	}
}
int calc() {
	tot = (1 << T.n) - 1;
	int ans = 0;
	for (int i = 1; i <= T.n; ++i) {
		memset(f, 0, sizeof f);
		dfs(i, 0);
		for (int s = 0; s <= tot; ++s)
			for (int j = 1; j <= T.n; ++j)
				if ((son[j] & s) == s) bel[s] = son[j];
		dp(1, 0);
		for (int j = 1; j <= S.n; ++j) inc(ans, f[j][son[i]]);
	}
	return ans;
}

int main() {
	scanf("%d", &S.n);
	for (int i = 1; i < S.n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		S.add(x, y);
	}
	scanf("%d", &T.n);
	for (int i = 1; i < T.n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		T.add(x, y);
	}
	int res = calc();
	S = T;
	res = 1ll * res * qpow(calc(), mod - 2) % mod;
	printf("%d\n", res);
	return 0;
}
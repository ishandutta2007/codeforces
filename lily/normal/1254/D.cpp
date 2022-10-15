#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 301111
#define MOD 998244353

int n, Q, invn, tcnt, fa[N], son[N], siz[N], top[N], L[N], R[N];

LL power(LL x, int y) {
	LL ret = 1;
	for ( ; y; y >>= 1) {
		if (y & 1) ret = ret * x % MOD;
		x = x  * x % MOD;
	}
	return ret;
}

vector <int> E[N];

void dfs(int x) {
	son[x] = 0;
	siz[x] = 1;
	for (auto &v : E[x]) if (v != fa[x]) {
		fa[v] = x;
		dfs(v);
		siz[x] += siz[v];
		if (siz[v] > siz[son[x]]) son[x] = v;
	}
}

void dfs2(int x, int anc) {
	L[x] = ++tcnt;
	top[x] = anc;
	if (son[x]) {
		dfs2(son[x], anc);
		for (auto &v : E[x]) if (v != fa[x] && v != son[x]) dfs2(v, v);
	}
	R[x] = tcnt;
}

struct BIT {
	int t[N];
	void upd(int x, int v) {
		for ( ; x <= n; x += x & -x ) (t[x] += v) %= MOD;
	}
	int qry(int x) {
		int ret = 0;
		for ( ; x; x -= x & -x) (ret += t[x]) %= MOD;
		return ret;
	}
} T;

LL val[N], sumv;

void upd(int x, LL d) {
	(sumv += siz[x] * d) %= MOD;
	(val[x] += d) %= MOD;
	T.upd(L[x], (-d * siz[x]) % MOD);
	T.upd(R[x] + 1, d * siz[x] % MOD);
	if (son[x]) {
		T.upd(L[son[x]], d * (n - siz[son[x]]) % MOD);
		T.upd(R[son[x]] + 1, -d * (n - siz[son[x]]) % MOD);
	}
}

int qry(int x) {
	LL ret = (T.qry(L[x]) + val[x] * n + sumv) % MOD;
	while (top[x] != 1) {
		x = top[x];
		(ret += val[fa[x]] * (n - siz[x])) %= MOD;
		x = fa[x];
	}
	return (ret + MOD) * invn % MOD;
}

void work() {
	scanf("%d%d", &n, &Q);
	tcnt = 0;
	for (int i = 1; i <= n; i++) E[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1);
	dfs2(1, 1);
	invn = power(n, MOD - 2);
	for (int i = 1; i <= Q; i++) {
		int op, v, d;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &v, &d);
			upd(v, d);
		}
		else {
			scanf("%d", &v);
			printf("%d\n", qry(v));
		}
	}
}

int main() {
	work();
}
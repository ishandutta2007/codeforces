#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

template <typename T> void inline read(T &x) {
	x = 0; int f = 1; char s = getchar();
	while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
	while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
	x *= f;
}

template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }
template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }


const int N = 1e5 + 5;

int n, P, k, x, w[N], in[N], out[N], pw[N], ip[N], S, sz[N];

vector<int> g[N];



LL T;

int maxP, rt, a[N], b[N], dep[N];

bool st[N];

void findRt(int u, int fa) {
	sz[u] = 1;
	int s = 0;
	for (int v: g[u]) {
		if (v == fa || st[v]) continue;
		findRt(v, u);
		sz[u] += sz[v];
		chkMax(s, sz[v]);
	}	
	chkMax(s, S - sz[u]);
	if (s < maxP) maxP = s, rt = u;
}

vector<int> C, D;

struct E{
	int next, v, w;
};

const int MOD = 999997;

struct Hash{
 	E e[MOD];
 	int numE, head[MOD];
 	void inline clear() {
 		for (int i = 1; i <= numE; i++)
 			head[e[i].v % MOD] = 0;
 		numE = 0;
 	}
 	int &operator[] (int x) {
 		int t = x % MOD;
 		for (int i = head[t]; i; i = e[i].next) {
 			if (e[i].v == x) {
 				return e[i].w;
 			}
 		}
 		e[++numE] = (E) { head[t], x, 0 };
 		head[t] = numE;
 		return e[numE].w;
 	}
} t[4];

int inline power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % P;
		a = 1ll * a * a % P;
		b >>= 1;
	}
	return res;
}


void dfs(int u, int fa, int d, int A, int B) {
	dep[u] = d;
	a[u] = A, b[u] = B;
	int val = (B + 1ll * pw[d] * w[rt]) % P;
	if (A == x) in[u]++, out[rt]++;
	if (val == x) out[u]++, in[rt]++;
	sz[u] = 1;
	t[0][A]++;
	t[1][A]++;
	int gx = 1ll * (x - B + P) * ip[d] % P;
	t[2][gx]++;
	t[3][gx]++;
	C.pb(u);
	sz[u] = 1;
	for (int v: g[u]) {
		if (v == fa || st[v]) continue;
		dfs(v, u, d + 1, (A + 1ll * w[v] * pw[d + 1]) % P, (1ll * B * k + w[v]) % P);
		sz[u] += sz[v];
	}	
}

int inline calc(int u) {
	return 1ll * (x - b[u] + P) * ip[dep[u]] % P;
}

void solve(int u) {
	maxP = 2e9;
	findRt(u, 0);
	st[rt] = 1;
	if (w[rt] == x) in[rt]++, out[rt]++;
	for (int v: g[rt]) {
		if (st[v]) continue;
		dfs(v, rt, 1, (w[rt] + 1ll * w[v] * k) % P, w[v]);
		for (int p: C) {
			int o = calc(p);
			out[p] -= t[1][o];
			in[p] -= t[3][a[p]];
			D.pb(p);
		}
		C.clear();
		t[1].clear(), t[3].clear();
	}
	for (int p: D) {
		int o = calc(p);
		out[p] += t[0][o];
		in[p] += t[2][a[p]];
	}
	C.clear(), D.clear();
	for (int i = 0; i < 4; i++) t[i].clear();
	for (int v: g[rt]) {
		if (st[v]) continue;
		S = sz[v], solve(v);
	}
}

int main() {
	read(n), read(P), read(k), read(x); k %= P, x %= P;
	pw[0] = 1, ip[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = 1ll * pw[i - 1] * k % P, ip[i] = power(pw[i], P - 2);
	for (int i = 1; i <= n; i++) read(w[i]), w[i] %= P;
	for (int i = 1, u, v; i < n; i++)
		read(u), read(v), g[u].pb(v), g[v].pb(u);
	S = n, solve(1);
	for (int i = 1; i <= n; i++)
		T += 1ll * out[i] * (n - out[i]) * 2 + 1ll * in[i] * (n - in[i]) * 2 + 1ll * in[i] * (n - out[i]) + 1ll * (n - in[i]) * out[i];
	T /= 2;
	LL ans = 1ll * n * n * n;
	ans -= T;
	printf("%lld\n", ans);
	return 0;
}
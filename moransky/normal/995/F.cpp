#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }
template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }

template <typename T> void inline read(T &x) {
	x = 0; int f = 1; char s = getchar();
	while (s > '9' || s < '0') { if (s == '-') f = -1; s = getchar(); }
	while (s <= '9' && s >= '0') x = x * 10 + s - '0', s = getchar();
	x *= f;
}

const int N = 3010, P = 1e9 + 7;

int n, D, f[N][N], y[N], m;

vector<int> g[N];

void dfs(int u) {
	for (int i = 1; i <= m; i++) f[u][i] = 1;
	for (int v: g[u]) {
		dfs(v);
		for (int i = 1; i <= m; i++)
			f[u][i] = 1ll * f[u][i] * f[v][i] % P;
	}
	for (int i = 1; i <= m; i++) {
		(f[u][i] += f[u][i - 1]) %= P;
	}
}

int inline power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}

int inline Interpo(int k) {
	int res = 0;
	for (int i = 1; i <= m; i++) {
		int s = y[i], v = 1;
		for (int j = 1; j <= m; j++) {
			if (i == j) continue;
			s = 1ll * s * (k - j + P) % P;
			v = 1ll * v * (i - j + P) % P;
		}

		res = (res + 1ll * s * power(v, P - 2)) % P;
	}
	return res;
}

int main() {
	read(n), read(D); m = n + 1;
	for (int i = 2; i <= n; i++) {
		int p; read(p);
		g[p].pb(i);
	}
	dfs(1);
	for (int i = 1; i <= m; i++) y[i] = f[1][i];
	printf("%d\n", Interpo(D));
	return 0;
}
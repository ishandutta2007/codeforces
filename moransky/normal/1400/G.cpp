#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 300005, P = 998244353, S = 21;

int n, m, L[N], R[N], a[N], b[N], g[1 << S][S + 1], c[N], d[N], e[N];
int fact[N], infact[N], f[N][S * 2], tot, fa[N], sz[N], Log[1 << S], now[N], ans;

bool vis[N], ins[N];
vector<int> col[N];

int inline power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}

int inline C(int a, int b) {
	if (a < b || a < 0 || b < 0) return 0;
	return (LL)fact[a] * infact[b] % P * infact[a - b] % P;
}

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
	scanf("%d%d", &n, &m); 

	fact[0] = infact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = (LL)fact[i - 1] * i % P;
	infact[n] = power(fact[n], P - 2);
	for (int i = n - 1; i; i--)
		infact[i] = (LL)infact[i + 1] * (i + 1) % P;

	for (int i = 0; i <= 20; i++) Log[1 << i] = i;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", L + i, R + i);
		f[i][0] = 1, fa[i] = i, sz[i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", a + i, b + i);
		fa[find(a[i])] = find(b[i]);
		ins[a[i]] = ins[b[i]] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (!ins[i]) c[L[i]]++, c[R[i] + 1]--;
	}
	for (int i = 1; i <= n; i++) col[find(i)].push_back(i), c[i] += c[i - 1];
	for (int t = 1; t <= n; t++) {
		if (find(t) != t || col[t].size() == 1) continue;
		int k = col[t].size();
		for (int i = 1; i < (1 << k); i++)
			for (int j = 0; j <= k; j++) g[i][j] = 0;
		for (int i = 1; i < (1 << k); i++) {
			bool ok = true; int cnt = 0;
			for (int j = 0; j < k; j++) 
				if (i >> j & 1) vis[col[t][j]] = true, cnt++;
			for (int j = 1; j <= m; j++)
				if (vis[a[j]] && vis[b[j]]) { ok = false; break; }
			for (int j = 0; j < k; j++) 
				if (i >> j & 1) vis[col[t][j]] = false;
			if (ok) g[i][cnt] = 1;
		}
		for (int v = 0; v < k; v++) {
			for (int i = 1; i + 1 < (1 << k); i++) {
				for (int j = 1; j <= k; j++) {
					if (!g[i][j] || i >> v & 1) continue;
					(g[i + (1 << v)][j] += g[i][j]) %= P;
				}
			}
		}
		for (int i = 1; i <= n; i++) d[i] = 0, e[i] = 0;
		for (int i = 0; i < k; i++) {
			d[L[col[t][i]]] += 1 << i, d[R[col[t][i]] + 1] -= 1 << i;
			e[L[col[t][i]]] ++, e[R[col[t][i]] + 1]--;
		}
		for (int i = 1; i <= n; i++) {
			d[i] += d[i - 1], e[i] += e[i - 1];
			now[i] += e[i];
			for (int j = now[i]; j; j--) {
				for (int v = 1; v <= min(j, e[i]); v++) {
					if (!f[i][j - v] || !g[d[i]][v]) continue;
					f[i][j] = (f[i][j] + (LL)f[i][j - v] * g[d[i]][v]) % P;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= now[i]; j++) {
			ans = (ans + (LL)f[i][j] * C(c[i], i - j)) % P;
		}
	}
	printf("%d\n", ans);
	return 0;
}
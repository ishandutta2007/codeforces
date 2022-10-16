#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int P = 1e9 + 7;

const int N = 5e5 + 5;

int inline power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}

int n, m, a[N], x[N][2], id[N], b[N], cnt, f[N];

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) f[i] = i;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		for (int j = 0; j < a[i]; j++)
			scanf("%d", &x[i][j]);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			int w = find(x[i][0]);
			if (!id[w]) {
				id[w] = i;
				b[++cnt] = i;
			}
		} else {
			int u = x[i][0], v = x[i][1];
			if (u < v) swap(u, v);
			if (!id[u]) {
				id[u] = i;
				b[++cnt] = i;
				f[u] = v;
			} else {
				int t = find(u); v = find(v);
				if (t == u) {
					if (!id[v]) {
						id[v] = i;
						b[++cnt] = i;
					}
				} else {
					if (t == v) continue;
					if (t < v) swap(t, v);
					
					if (!id[t]) {
						id[t] = i;
						b[++cnt] = i;
						f[t] = v;
					} else {
						if (!id[v]) {
							id[v] = i;
							b[++cnt] = i;
							
						}
					}
				}
			}
		}
	}
	printf("%d %d\n", power(2, cnt), cnt);
	for (int i = 1; i <= cnt; i++) printf("%d ", b[i]);
	return 0;
}
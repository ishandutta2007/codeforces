#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 3e18;
#define chkmn(a, b) ((a) = (a) < (b) ? (a) : (b))
int n,m,a[20],to[20];
ll dp[20][20][1 << 18], w[20];
bool pre[20][20][1 << 18];
struct Edge {
	int v,nxt;
}e[410];
int h[20], ind[20], cnt_e = 1;
void add(int x, int y) { e[++cnt_e] = {y, h[x]}, h[x] = cnt_e, ++ind[y]; }

int ord[20],tot;
void Sort() {
	queue <int> q;
	for (int i = 1; i <= n; ++i)
		if (ind[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		ord[++tot] = u;
		for (int j = h[u]; j; j = e[j].nxt) {
			int v = e[j].v;
			if (--ind[v] == 0) q.push(v);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int x,y,z; scanf("%d%d%d", &x, &y, &z);
		add(x, y), w[x] += z, w[y] -= z, to[x] |= (1 << (y - 1));
	}
	Sort();
	for (int i = 1; i <= n; ++i) {
		int u = ord[i];
		for (int j = h[u]; j; j = e[j].nxt) {
			int v = e[j].v;
			to[u] |= to[v];
		}
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int s = 0; s < (1 << n); ++s) {
				int u = ord[j + 1];
				if (dp[i][j][s] >= inf) continue;
				chkmn(dp[i][j + 1][s], dp[i][j][s]);
				if (dp[i][j + 1][s] == dp[i][j][s]) pre[i][j + 1][s] = 0;
				if (!(s & (1 << (u - 1))) && (s & to[u]) == to[u]) {
					chkmn(dp[i][j + 1][s | (1 << (u - 1))], dp[i][j][s] + w[u] * i);
					if (dp[i][j + 1][s | (1 << (u - 1))] == dp[i][j][s] + w[u] * i) pre[i][j + 1][s | (1 << (u - 1))] = 1;
				}
			}
		}
		for (int s = 0; s < (1 << n); ++s)
			chkmn(dp[i + 1][0][s], dp[i][n][s]);
	}
	for (int i = n, j = 0, s = (1 << n) - 1; i || j || s;) {
		if (!j) --i, j = n;
		else {
			if (pre[i][j][s]) {
				int u = ord[j];
				a[u] = i, s ^= (1 << (u - 1));
			}
			--j;
		}
	}
	for (int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i == n]);
	return 0;
}
/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
typedef double D;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define MAXN 100319

struct edge {
	int next, to, ans;
} e[MAXN * 2];

int ecnt = 1, head[MAXN];

int f[MAXN], d[MAXN];
vector <int> l[MAXN], cnt[MAXN];
vector <LL> sum[MAXN];

int getf(int x) {
	return f[x] < 0 ? x : (f[x] = getf(f[x]));
}

void merge(int u, int v) {
	u = getf(u), v = getf(v);
	if (f[u] > f[v]) swap(u, v);
	f[u] += f[v];
	f[v] = u;
}

void add(int u, int v) {
	e[++ecnt] = (edge) {head[u], v, -1}; head[u] = ecnt;
	e[++ecnt] = (edge) {head[v], u, -1}; head[v] = ecnt;
	merge(u, v);
}

D solve(int x, int y) {
	int maxd = max(d[x], d[y]);
	int n = sum[x].size() - 2, m = sum[y].size() - 2;
	if (n > m) swap(n, m), swap(x, y);
	D tot = 0;
	for (int i = 0, j, cc; i <= n;) {
		i++;
		cc = cnt[x][i] - cnt[x][i - 1];
		if (cc) {
			j = max(min(maxd - i - 1, m), -1) + 1;
			tot += double(maxd * LL(cnt[y][j]) + sum[y][m + 1] - sum[y][j] + (cnt[y][m + 1] - cnt[y][j]) * i) * cc;
		}
	}
	return tot / f[x] / f[y];
}

int n, m, q;

int dfs(int x, int from) {
	int fir = 0, sec = 0;
	for (int now = head[x]; now; now = e[now].next) {
		if (e[now].to != from) {
			if (!(~e[now].ans)) e[now].ans = dfs(e[now].to, x) + 1;
			if (e[now].ans >= fir) sec = fir, fir = e[now].ans;
			else if (e[now].ans > sec) sec = e[now].ans;
		}
	}
	if (from == -1) d[getf(x)] = max(d[getf(x)], fir + sec);
	return fir;
}

map <pii, D> A;


int main() {
	scanf("%d%d%d", &n, &m, &q);
	memset(f, -1, sizeof f);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);add(u, v);
	}
	for (int i = 1; i <= n; i++) {dfs(i, -1);}
	for (int i = 1; i <= n; i++) {
		int ma = 0;
		for (int now = head[i]; now; now = e[now].next) {
			ma = max(e[now].ans, ma);
		}
		l[getf(i)].push_back(ma);
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] < 0) {
			sort(l[i].begin(), l[i].end());
			cnt[i].push_back(0);
			sum[i].push_back(0);
			LL tot = 0;
			for (int j = 0, k = 0, now, c = 0; j <= l[i][l[i].size() - 1]; j++) {
				now = 0;
				while (k < l[i].size() && l[i][k] == j) k++, now++;
				tot += (LL)now * j;
				c += now;
				cnt[i].push_back(c);
				sum[i].push_back(tot);
			}
		}
	}
	for (int i = 1, u, v; i <= q; i++) {
		scanf("%d%d", &u, &v);
		u = getf(u), v = getf(v);
		if (u != v) {
			if (A.find(mp(u, v)) == A.end()) {
				A[mp(u, v)] = A[mp(v, u)] = solve(u, v);
			}
			printf("%.10lf\n", A[mp(u, v)]);
		}
		else printf("-1\n");
	}
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, s, m, k, a[1501], f[1501][1501], v[1501], g[1501];
int r[1501];

struct node {
	int x, y;
	bool operator < (const node &A) const {
		return y < A.y;
	}
} c[2001];

inline void insert(int x, int y) {
	x = n - x + 1;
	for (; x <= n; x += x & (-x))
		r[x] = max(r[x], y);
}

int calc(int x) {
	x = n - x + 1;
	int res = -1 << 30;
	for (; x; x -= x & (-x))
		res = max(res, r[x]);
	return res;
}

bool check(int M) {
	v[0] = 0;
	for (int i = 1; i <= n; i++)
		v[i] = v[i - 1] + (a[i] <= M);
	memset(f, 0, sizeof(f));
	int L = 1;
	for (int i = 1; i <= m; i++) {
		g[0] = 0;
		memset(r, 128, sizeof(r));
		memset(g, 0, sizeof(g));
		for (int j = 1; j <= s; j++)
			g[c[j].y] = max(g[c[j].y], f[i - 1][j]);
		for (int j = 1; j <= n; j++)
			g[j] = max(g[j - 1], g[j]);
		for (int j = 1; j <= s; j++) {
			f[i][j] = max(calc(c[j].x), g[c[j].x - 1] - v[c[j].x - 1]) + v[c[j].y];
			insert(c[j].y, f[i - 1][j] - v[c[j].y]);
		}
	}
	int res = 0;
	for (int i = 1; i <= s; i++)
		res = max(res, f[m][i]);
	return (res >= k);
}


int main() {
	scanf("%d%d%d%d", &n, &s, &m, &k);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	for (int i = 1; i <= s; i++)
		scanf("%d%d", &c[i].x, &c[i].y);
	sort(c + 1, c + s + 1);
	int L = 0, R = 1e9 + 1, M = (L + R) >> 1;
	for (; L + 1 < R; M = (L + R) >> 1)
		if (check(M))
			R = M;
		else
			L = M;
	if (check(R))
		printf("%d\n", R);
	else
		printf("-1\n");
}
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const int N = 505, L = 9;

int n, m, q, Log[N], R[N][N], Y[N][N], G[N][N], B[N][N], f[N][N][L][L];

char g[N][N];

int inline sum(int s[N][N], int l1, int r1, int l2, int r2) {
	return s[l2][r2] - s[l1 - 1][r2] - s[l2][r1 - 1] + s[l1 - 1][r1 - 1];
}

int inline query(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) return 0;
	int u = Log[x2 - x1 + 1], v = Log[y2 - y1 + 1];
	return max(max(f[x1][y1][u][v], f[x1][y2 - (1 << v) + 1][u][v]), max(f[x2 - (1 << u) + 1][y1][u][v], f[x2 - (1 << u) + 1][y2 - (1 << v) + 1][u][v]));
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	for (int i = 1; i <= max(n, m); i++) Log[i] = log2(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			R[i][j] = R[i - 1][j] + R[i][j - 1] - R[i - 1][j - 1] + (g[i][j] == 'R');
			Y[i][j] = Y[i - 1][j] + Y[i][j - 1] - Y[i - 1][j - 1] + (g[i][j] == 'Y');
			B[i][j] = B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1] + (g[i][j] == 'B');
			G[i][j] = G[i - 1][j] + G[i][j - 1] - G[i - 1][j - 1] + (g[i][j] == 'G');
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int l = 0, r = min(min(i, n - i), min(j, m - j));
			while (l < r) {
				int mid = (l + r + 1) >> 1;
				int s = sum(R, i - mid + 1, j - mid + 1, i, j) + sum(G, i - mid + 1, j + 1, i, j + mid) + sum(Y, i + 1, j - mid + 1, i + mid, j) + sum(B, i + 1, j + 1, i + mid, j + mid);
				if (s == mid * mid * 4) l = mid;
				else r = mid - 1;
			}
			f[i][j][0][0] = r;
		}
	}
	for (int u = 0; u < L; u++) {
		for (int v = 0; v < L; v++) {
			if (u == 0 && v == 0) continue;
			for (int i = 1; i + (1 << u) - 1 <= n; i++) {
				for (int j = 1; j + (1 << v) - 1 <= m; j++) {
					if (u) {
						f[i][j][u][v] = max(f[i][j][u - 1][v], f[i + (1 << (u - 1))][j][u - 1][v]);
					} else {
						f[i][j][u][v] = max(f[i][j][u][v - 1], f[i][j + (1 << (v - 1))][u][v - 1]);
					}
				}
			}
		}
	}
	while(q--) {
		int r1, c1, r2, c2; scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		int l = 0, r = min(r2 - r1 + 1, c2 - c1 + 1) / 2;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (query(r1 + mid - 1, c1 + mid - 1, r2 - mid, c2 - mid) >= mid) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", r * r * 4);
	}
	return 0;
}
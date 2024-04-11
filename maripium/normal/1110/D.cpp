#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int inf = 1e9;

int n, m;
int cnt[N];
int f[2][9][9];

void mxm(int &x,int y) {
	if (x < y) {
		x = y;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	int ans = 0;
	if (m == 1) {
		printf("%d\n", n / 3);
		return 0;
	}
	for (int i = 1; i <= m; ++i) {
		if (cnt[i] >= 9) {
			int rm = cnt[i] % 3;
			rm += 6;
			ans += (cnt[i] - rm) / 3;
			cnt[i] = rm;
		}
	}
	memset(f, -69, sizeof f);
	for (int tk1 = 0; tk1 * 3 <= cnt[1]; ++tk1) {
		for (int tk2 = 0; tk2 * 3 <= cnt[2]; ++tk2) {
			mxm(f[0][cnt[2] - 3 * tk2][cnt[1] - 3 * tk1], tk2 + tk1);
		}
	}
	for (int i = 2; i <= m; ++i) {
		for (int u = 8; u >= 0; --u) {
			for (int v = 8; v >= 0; --v) {
				if (u >= 3) {
					mxm(f[0][u - 3][v], f[0][u][v] + 1);
				}
			}
		}
		for (int u = 0; u < 9; ++u) {
			for (int v = 0; v < 9; ++v) {
				int mn = min(min(u, v), cnt[i + 1]);
				for (int tk = 0; tk <= mn; ++tk) {
					mxm(f[1][cnt[i + 1] - tk][u - tk], f[0][u][v] + tk);
				}
			}
		}
		for (int u = 0; u < 9; ++u) {
			for (int v = 0; v < 9; ++v) {
				f[0][u][v] = f[1][u][v];
				f[1][u][v] = -inf;
			}
		}
	}
	int mx = 0;
	for (int u = 0; u < 9; ++u) {
		for (int v = 0; v < 9; ++v) {
			mx = max(mx, f[0][u][v]);
		}
	}
	printf("%d\n", ans + mx);
}
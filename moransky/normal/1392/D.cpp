// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 2e5 + 5, INF = 1e9;

int n, f[N][2][2];

int m[300];

char t[2] = { 'L', 'R' };

char s[N];

int main() {
	m['L'] = 0, m['R'] = 1;
	int T; scanf("%d", &T);
	while (T--) {
		int ans = 2e9;
		scanf("%d%s", &n, s + 1);
		for (int x = 0; x <= 1; x++) {
			for (int y = 0; y <= 1; y++) {
				for (int j = 1; j <= n; j++)
					for (int u = 0; u < 2; u++)
						for (int v = 0; v < 2; v++)
							f[j][u][v] = INF;
				f[2][x][y] = (s[1] != t[x]) + (s[2] != t[y]);
				for (int i = 2; i < n; i++) {
					for (int u = 0; u < 2; u++) {
						for (int v = 0; v < 2; v++) {
							for (int k = 0; k < 2; k++) {
								if (u == v && v == k) continue;
								f[i + 1][v][k] = min(f[i + 1][v][k], f[i][u][v] + (s[i + 1] != t[k]));
							}
						}
					}
				}
				for (int u = 0; u < 2; u++) {
					for (int v = 0; v < 2; v++) {
						if (v == x && x == y) continue;
						if (u == v && v == x) continue;
						ans = min(ans, f[n][u][v]);
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
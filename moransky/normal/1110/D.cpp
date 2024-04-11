// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e6 + 5, S = 7;

int n, m, c[N], s, f[N][S][S], ans;
 
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		c[x]++;
	}
	memset(f, 0xcf, sizeof f);
	f[0][0][0] = 0;
	for (int i = 0; i <= m + 3; i++) {
		for (int x = 0; x <= 6; x++) {
			for (int y = 0; y <= 6; y++) {
				if (f[i][x][y] < 0) continue;
				chkMax(ans, f[i][x][y]);
				int p = min(min(i == 0 ? 0 : c[i - 1] - x, c[i] - y), c[i + 1]);
				for (int z = 0; z <= p; z++) {
					if (y + z > 6 || z > 6) break;
					chkMax(f[i + 1][y + z][z], f[i][x][y] + z +  (i == 0 ? 0 : (c[i - 1] - x - z) / 3));
				}
			}
		}
	}
	printf("%d\n", ans + s);
	return 0;
}
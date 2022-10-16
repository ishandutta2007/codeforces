#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}


const int N = 12, M = 2000;

int n, m, a[N][M], f[1 << N], g[1 << N], mx[M], p[M], w[1 << N];

bool inline cmp(int x, int y) {
    return mx[x] > mx[y];
}

int main() {
	int T; read(T);
	while (T--) {
        memset(mx, 0, sizeof mx);
		read(n), read(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) read(a[i][j]), chkMax(mx[j], a[i][j]);
        }
        for (int j = 0; j < m; j++) p[j] = j;
        sort(p, p + m, cmp);
        memset(f, 0xcf, sizeof f);
        f[0] = 0;
        for (int G = 0; G < min(m, n); G++) {
            int c = p[G];
            memcpy(g, f, sizeof g);
            for (int i = 0; i < (1 << n); i++) {
                int v = 0;
                for (int x = 0; x < n; x++) {
                    int s = 0;
                    for (int y = 0; y < n; y++)
                        if (i >> y & 1) s += a[(x + y) % n][c];
                    chkMax(v, s);
                }
                w[i] = v;
            }
            for (int i = 0; i < (1 << n); i++) {
                for (int j = i; j; j = (j - 1) & i) {
                    chkMax(f[i], w[j] + g[i ^ j]);
                }
            }
        }
        printf("%d\n", f[(1 << n) - 1]);
	}
}
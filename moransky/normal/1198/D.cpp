#include <iostream>
#include <cstdio>
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

const int N = 55, INF = 0x3f3f3f3f;

int n, s[N][N];

int f[N][N][N][N];

char g[N][N];

bool inline check(int x1, int y1, int x2, int y2) {
    return (s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]) == 0;
}

int inline dp(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    if (check(x1, y1, x2, y2)) return 0;
    int &v = f[x1][y1][x2][y2];
    if (v != INF) return v;
    v = max(x2 - x1 + 1, y2 - y1 + 1);
    for (int i = x1; i < x2; i++) {
        chkMin(v, dp(x1, y1, i, y2) + dp(i + 1, y1, x2, y2));
    }
    for (int i = y1; i < y2; i++) {
        chkMin(v, dp(x1, y1, x2, i) + dp(x1, i + 1, x2, y2));
    }
    return v;
}

int main() {
    memset(f, 0x3f, sizeof f);
    read(n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", g[i] + 1);
        for (int j = 1; j <= n; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            if (g[i][j] == '#') s[i][j]++;
        }
    }
    printf("%d\n", dp(1, 1, n, n));
}
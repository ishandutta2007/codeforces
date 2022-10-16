#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

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

const int N = 1005, P = 998244353;

int n, k, a[N], f[N][N];

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

int inline calc(int V) {
    a[0] = -1e9;
    f[0][0] = 1;
    int u = 0;
    for (int i = 1; i <= n; i++) {
        while (u + 1 < i && a[i] - a[u + 1] >= V) u++;
        f[i][0] = 0;
        for (int j = 1; j <= k; j++) {
            f[i][j] = f[u][j - 1];
        }
        for (int j = 0; j <= k; j++) add(f[i][j], f[i - 1][j]);
    }
    return f[n][k];
}

int main() {
    read(n), read(k);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
    }
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = 1; i <= a[n] / (k - 1); i++)
         add(ans, calc(i));
    printf("%d\n", ans);
}
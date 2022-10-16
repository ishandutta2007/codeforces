// Skyqwq
#include <bits/stdc++.h>

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

const int N = 5005;

int f[N][N], a[N], n;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), f[i][i] = a[i];
    for (int l = 2; l <= n; l++) {
        for (int i = 1, j; (j = i + l - 1) <= n; i++)
            f[i][j] = f[i + 1][j] ^ f[i][j - 1];
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 1, j; (j = i + l - 1) <= n; i++)
            chkMax(f[i][j], max(f[i + 1][j], f[i][j - 1]));
    }
    int q; read(q);
    while (q--) {
        int l, r; read(l), read(r);
        printf("%d\n", f[l][r]);
    }
    return 0;
}
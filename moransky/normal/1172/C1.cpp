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


const int N = 55, P = 998244353;

int n, m, a[N], w[N], f[N][N][N];

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res; 
}

int inline calc(int u, int o) {
    int A = 0, B = 0, C = w[u];
    for (int i = 1; i <= n; i++) {
        if (i == u) continue;
        if (a[i]) A += w[i];
        else B += w[i];
    }
    memset(f, 0, sizeof f);
    f[0][0][0] = 1; int res = 0;
    for (int i = 0; i <= m; i++) {
        if (C + o * i < 0) continue;
        for (int j = 0; i + j <= m; j++) {
            for (int k = 0; i + j + k <= m; k++) {
                if (B - k < 0) continue;
                if (!f[i][j][k]) continue;
                int v = f[i][j][k];
                if (i + j + k == m) add(res, 1ll * v * i % P);
                int s = power(C + o * i + B - k + A + j, P - 2);
                add(f[i + 1][j][k], 1ll * s * (C + o * i) % P * v % P);
                add(f[i][j + 1][k], 1ll * s * (A + j) % P * v % P);
                add(f[i][j][k + 1], 1ll * s * (B - k) % P * v % P);
            }
        }
    }
    return res;
}

int main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        read(w[i]);
    }
    for (int i = 1; i <= n; i++) {
        int o = a[i] ? 1 : -1;
        printf("%lld\n", (w[i] + 1ll * o * calc(i, o) + P) % P);
    }
}
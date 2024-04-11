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

const int N = 14, P = 1e9 + 7;

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

int n, a[N], w[N][N], wt[N][1 << N], s, ans, f[1 << N];

int inline ban(int x, int y) {
    int res = 1;
    for (int i = 0; i < n; i++) {
        if (y >> i & 1)
            res = 1ll * res * wt[i][x] % P;
    }
    return res;
}

void inline work() {
    memset(f, 0, sizeof f);
    f[1 << s] = 1;
    for (int i = 0; i < (1 << n); i++) {
        if (!(i >> s & 1)) continue;
        if (i == (1 << s)) continue;
        f[i] = 1;
        for (int j = i - 1; j; j = (j - 1) & i) {
            if (j >> s & 1) continue;
            f[i] = (f[i] - 1ll * ban(i ^ j, j) * f[i ^ j] % P + P) % P;
        }
    }
    add(ans, f[(1 << n) - 1]);
}
 
int main() {
    read(n);
    for (int i = 0; i < n; i++) read(a[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int inv = power(a[i] + a[j], P - 2);
            w[i][j] = 1ll * a[i] * inv % P;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            wt[i][j] = 1;
            for (int k = 0; k < n; k++)
                if (j >> k & 1) wt[i][j] = 1ll * wt[i][j] * w[i][k] % P;
        }
    }
    for (s = 0; s < n; s++) work();
    printf("%d\n", ans);
    return 0; 
}
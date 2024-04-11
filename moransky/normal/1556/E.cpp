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

const int N = 1e5 + 5, L = 17;

int n, q;

int g[N], a[N];
LL mx[N][L], mn[N][L], s[N];

void inline STPrework(int n) {
    g[0] = -1;
    for (int i = 1; i <= n; i++) {
        mx[i][0] = mn[i][0] = s[i], g[i] = g[i >> 1] + 1;
    }
    for (int j = 1; j <= g[n]; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
        }
}

LL inline Mx(int l, int r) {
    int k = g[r - l + 1];
    return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}

LL inline Mn(int l, int r) {
    int k = g[r - l + 1];
    return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}
 
int main() {
    read(n), read(q);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1, x; i <= n; i++) {
        read(x); a[i] -= x;
    }
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    STPrework(n);
    while (q--) {
        int l, r; read(l), read(r);
        LL a = Mn(l, r), b = Mx(l, r);
        if (s[r] != s[l - 1] || b - s[l - 1] > 0) puts("-1");
        else {
            printf("%lld\n", s[l - 1] - a);
        }
    }
    return 0;
}
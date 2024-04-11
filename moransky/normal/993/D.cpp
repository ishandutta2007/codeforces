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

const int N = 55;

int n;

struct E{
    int a, b;
} e[N];

bool operator < (const E &x, const E &y) {
    if (x.a == y.a) return x.b > y.b;
    return x.a > y.a;
};
 
long double f[N], g[N], s[N];

bool inline chk(long double mid) {
    for (int i = 1; i <= n; i++) f[i] = -9e18;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + e[i].b * mid - e[i].a;
    }
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j < n && e[j + 1].a == e[i].a) j++;
        memcpy(g, f, sizeof f);
        for (int j = 0; j <= n; j++) f[j] = -9e18;
        int l = j - i + 1;
        for (int j = 0; j <= n; j++) {
            if (g[j] <= -9e18) continue;
            for (int k = 0; k <= l; k++) {
                int re = l - k;
                if (re > j) continue;
                chkMax(f[j - re + k], g[j] + s[i + k - 1] - s[i - 1]);
            }
        }
        i = j;
    }
    for (int i = 0; i <= n; i++) {
        if (f[i] >= 0) return 1;
    }
    return 0;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(e[i].a);
    for (int i = 1; i <= n; i++) read(e[i].b);
    sort(e + 1, e + 1 + n);
    long double l = 0, r = 1e8, eps = 1e-10;
    while (r - l > eps) {
        long double mid = (l + r) / 2;
        if (chk(mid)) r = mid;
        else l = mid;
    }
    printf("%lld\n", (LL)(r * 1000 + 0.99999));
    return 0;
}
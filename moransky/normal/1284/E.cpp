// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const double PI = acos(-1);
const int N = 5005;

int n, t;

PII e[N], a[N];

LL inline cross(PII x, PII y) {
    return 1ll * x.fi * y.se - 1ll * x.se * y.fi;
}

int inline quad(PII x) {
    if (x.fi >= 0 && x.se >= 0) return 1;
    if (x.fi <= 0 && x.se >= 0) return 2;
    if (x.fi <= 0 && x.se <= 0) return 3;
    if (x.fi >= 0 && x.se <= 0) return 4;
    return 0;
}

bool inline cmp(PII x, PII y) {
    int A = quad(x), B = quad(y);
    if (A != B) return A < B;
    return cross(x, y) > 0;
}

LL inline calc(int u) {
    t = 0;
    for (int i = 1; i <= n; i++) {
        if (i == u) continue;
        a[++t] = mp(e[i].fi - e[u].fi, e[i].se - e[u].se);
    }
    sort(a + 1, a + 1 + t, cmp);
    for (int i = 1; i <= t; i++) a[i + t] = a[i];
    LL ret = 1ll * (n - 1) * (n - 2ll) * (n - 3ll) * (n - 4ll) / 24;
    for (int i = 1, j = 1; i <= 2 * t; i++) {
        while (j < i && (j <= i - t || cross(a[i], a[j]) > 0)) j++;
        int num = i - j;
        if (num >= 3 && i > t) {
            ret -= num * (num - 1ll) * (num - 2ll) / 6;
        }
    }
    return ret;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(e[i].fi), read(e[i].se);
    LL ans = 0;
    for (int i = 1; i <= n; i++) ans += calc(i);
    printf("%lld\n", ans);
    return 0;
}
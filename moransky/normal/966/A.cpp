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

const int N = 1e5 + 5;

int n, m, t1, t2, v, a[N], b[N], q;
 
int main() {
    read(n), read(m), read(t1), read(t2), read(v);
    for (int i = 1; i <= t1; i++) read(a[i]);
    sort(a + 1, a + 1 + t1);
    for (int i = 1; i <= t2; i++) read(b[i]);
    sort(b + 1, b + 1 + t2);
    read(q);
    while (q--) {
        int x1, y1, x2, y2; read(x1), read(y1), read(x2), read(y2);
        if (x1 == x2) {
            printf("%d\n", abs(y1 - y2));
            continue;
        }
        int l = y1, r = y2;
        if (l > r) swap(l, r);
        int p;
        int ans = 2e9;
        if (t1) {
            p = lower_bound(a + 1, a + 1 + t1, l) - a;
            if (p >= 1 && p <= t1) chkMin(ans, abs(y1 - a[p]) + abs(y2 - a[p]) + abs(x1 - x2));
            if (p > 1) {
                --p;
                chkMin(ans, abs(y1 - a[p]) + abs(y2 - a[p]) + abs(x1 - x2));
            }
        }
        if (t2) {
            p = lower_bound(b + 1, b + 1 + t2, l) - b;
            if (p >= 1 && p <= t2) chkMin(ans, abs(y1 - b[p]) + abs(y2 - b[p]) + (abs(x1 - x2) + v - 1) / v);
            if (p > 1) {
                --p;
                chkMin(ans, abs(y1 - b[p]) + abs(y2 - b[p]) + (abs(x1 - x2) + v - 1) / v);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
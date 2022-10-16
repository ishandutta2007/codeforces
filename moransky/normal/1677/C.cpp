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

const int N = 1e5 + 5;

int n, f[N], sz[N], ca[N], cb[N], d[N], t;

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    f[x] = y;
    sz[y] += sz[x];
}

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
        for (int i = 1; i <= n; i++) read(ca[i]);
        for (int i = 1; i <= n; i++) {
            read(cb[i]);
            merge(ca[i], cb[i]);
        }
        t = 0;
        for (int i = 1; i <= n; i++) {
            if (find(i) == i) {
                int p = sz[i];
                if (p % 2 == 0) {
                    for (int j = 0; j < p / 2; j++)
                        d[++t] = 2, d[++t] = -2;
                } else {
                    for (int j = 0; j < p / 2; j++)
                        d[++t] = 2, d[++t] = -2;
                    d[++t] = 0;
                }
            }
        }
        sort(d + 1, d + 1 + t);
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += 1ll * i * d[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
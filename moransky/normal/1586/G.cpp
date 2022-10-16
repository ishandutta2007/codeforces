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
 
const int N = 4e5 + 5, P = 1e9 + 7;

struct E{
    int a, b, id;
    bool operator < (const E &x) const {
        return b < x.b;
    }
} e[N];

int n, t, f[N], c[N];

bool vis[N];

int inline ask(int x) {
    int res = 0;
    for (; x; x -= x & -x) (res += c[x]) %= P;
    return res;
}

void inline add(int x, int k) {
    for (; x <= 2 * n; x += x & -x) {
        (c[x] += k) %= P;
    }
}
int main() {
    read(n);
    for (int i = 1; i <= n; i++)
        read(e[i].a), read(e[i].b), e[i].id = i;
    sort(e + 1, e + 1 + n);
    read(t);
    while (t--) {
        int x; read(x); vis[x] = 1;
    }
    int p = -1;
    int m = -1;
    for (int i = 1; i <= n; i++)
        if (vis[e[i].id]) {
            f[i] = 1;
            m = i;
            if (p == -1 || e[i].a > e[p].a) p = i;
        }
    int ta = -1;
    for (int j = m; j; j--) {
        if (vis[e[j].id]) {
            chkMax(ta, e[j].a);
        } else {
            if (e[j].a < ta) {
                f[j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = n; i; i--) {
        (f[i] += ask(e[i].a)) %= P;
        add(e[i].a, f[i]);
        (ans += f[i]) %= P;
    }
    printf("%d\n", ans);
    return 0;
}
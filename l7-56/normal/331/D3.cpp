#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (int i = 0; s[i]; ++i) putchar(s[i]); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

const ll maxn = 2e5 + 10, inf = 1e18;
int n, b, q;
ll t[maxn];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int d_(int d) { return (d > 0) - (d < 0); }
int d__(pii d) {
    d.fir = d_(d.fir), d.sec = d_(d.sec);
    for (int k = 0; k < 4; ++k)
        if (d.fir == dx[k] && d.sec == dy[k]) return k;
    return -1;
}
int d__(char ch) {
    if (ch == 'R') return 0;
    if (ch == 'L') return 1;
    if (ch == 'U') return 2;
    if (ch == 'D') return 3;
    return -1;
}
struct node {
    int x[4], k;
} a[maxn];
int f[maxn][50];
ll g[maxn][50];

function <bool(node, node)> cmp[4] = {
    [&] (node p, node q) { return max(p.x[0], p.x[2]) < max(q.x[0], q.x[2]); },
    [&] (node p, node q) { return min(p.x[0], p.x[2]) > min(q.x[0], q.x[2]); },
    [&] (node p, node q) { return max(p.x[1], p.x[3]) < max(q.x[1], q.x[3]); },
    [&] (node p, node q) { return min(p.x[1], p.x[3]) > min(q.x[1], q.x[3]); }
};
void solve(int k, int o1, int o2) {
    vi ord(n + q);
    iota(begin(ord), end(ord), 1);
    sort(begin(ord), end(ord), [&] (int i, int j) -> bool {
        if (cmp[k](a[i], a[j])) return 1;
        if (cmp[k](a[j], a[i])) return 0;
        return i > j;
    });
    set <pii> s;
    for (int i : ord) {
        if (i <= n) {
            auto lt = s.lower_bound({min(a[i].x[o1], a[i].x[o2]), 0});
            auto rt = s.upper_bound({max(a[i].x[o1], a[i].x[o2]), maxn});
            for (; lt != rt; s.erase(lt++)) {
                int j = lt -> sec;
                f[j][0] = i, g[j][0] = abs(a[i].x[2] - a[j].x[2]) + abs(a[i].x[3] - a[j].x[3]);
            }
        }
        if (a[i].k == k) s.insert({a[i].x[o2], i});
    }
    for (pii o : s) f[o.sec][0] = 0, g[o.sec][0] = inf;
}

int main() {
    scanf("%d%d", &n, &b);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d%d", &a[i].x[0], &a[i].x[1], &a[i].x[2], &a[i].x[3]),
        a[i].k = d__(make_pair(a[i].x[2] - a[i].x[0], a[i].x[3] - a[i].x[1]));
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        char ch[2];
        int u = i + n;
        scanf("%d%d%s%lld", &a[u].x[0], &a[u].x[1], ch, &t[i]);
        a[u].x[2] = a[u].x[0], a[u].x[3] = a[u].x[1], a[u].k = d__(ch[0]);
    }
    solve(0, 1, 3);
    solve(1, 1, 3);
    solve(2, 0, 2);
    solve(3, 0, 2);
    // for (int i = 1; i <= n + q; ++i)
    //     printf("%d : %d %lld\n", i, f[i][0], g[i][0]);
    for (int j = 1; j < 50; ++j)
        for (int i = 1; i <= n + q; ++i)
            f[i][j] = f[f[i][j - 1]][j - 1],
            g[i][j] = min(inf, g[i][j - 1] + g[f[i][j - 1]][j - 1]);
    for (int i = 1; i <= q; ++i) {
        int u = i + n; ll rst = t[i];
        for (int j = 49; j >= 0; --j)
            if (g[u][j] <= rst) rst -= g[u][j], u = f[u][j];
        if (f[u][0]) {
            int v = f[u][0];
            ll dis = dx[a[u].k] * (a[v].x[2] - a[u].x[2]) + dy[a[u].k] * (a[v].x[3] - a[u].x[3]);
            if (rst >= dis) rst -= g[u][0], u = v;
        }
        ll x = max(0ll, min((ll) b, a[u].x[2] + dx[a[u].k] * rst));
        ll y = max(0ll, min((ll) b, a[u].x[3] + dy[a[u].k] * rst));
        printf("%lld %lld\n", x, y);
    }
    return 0;
}
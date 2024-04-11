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

const int maxn = 1e6 + 10, inf = 1e9 + 10;
int n, m, h[maxn], s[maxn], mh[maxn], ans = inf;
int ask(int val) { return upper_bound(s + 1, s + m + 1, val) - s - 1; }
vi e[maxn];
vector <pii> t[maxn];
void dfs(int u, int fa, pii mn, pii smn) {
    pii nw = {h[u], u};
    if (nw < mn) smn = mn, mn = nw;
    else if (nw < smn) smn = nw;
    mh[u] = mn.fir;
    t[mn.sec].push_back({u, smn.fir});
    for (int v : e[u])
        if (v != fa) dfs(v, u, mn, smn);
}

int a[maxn];
struct SegTree {
    int mn[maxn << 2], add[maxn << 2];
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    #define mid ((l + r) >> 1)
    void push_up(int rt) { mn[rt] = min(mn[ls], mn[rs]); }
    void build(int rt, int l, int r) {
        if (l == r) return mn[rt] = a[l], void();
        build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
    }
    void tag(int rt, int val) { add[rt] += val, mn[rt] += val; }
    void push_down(int rt) { if (add[rt]) tag(ls, add[rt]), tag(rs, add[rt]), add[rt] = 0; }
    void update(int rt, int l, int r, int L, int R, int val) {
        if (L > R || L > r || R < l) return;
        if (L <= l && r <= R) return tag(rt, val);
        push_down(rt), update(ls, l, mid, L, R, val), update(rs, mid + 1, r, L, R, val), push_up(rt);
    }
    #undef ls
    #undef rs
    #undef mid
} tr;

int main() {
    read(n);
    for (int i = 1; i <= n; ++i) read(h[i]);
    for (int i = 1; i < n; ++i) {
        int x, y; read(x, y);
        e[x].push_back(y), e[y].push_back(x);
    }
    dfs(1, 0, {inf, inf}, {inf, inf});
    read(m);
    for (int i = 1; i <= m; ++i) read(s[i]);
    sort(s + 1, s + m + 1);
    for (int i = 1; i <= n; ++i) a[ask(mh[i])]++;
    for (int i = m - 1; i >= 0; --i) a[i] += a[i + 1];
    int flg = 1;
    for (int i = 1; i <= m; ++i)
        a[i] -= m - i + 1, flg &= (a[i] >= 0);
    if (flg) return printf("0\n"), 0;

    tr.build(1, 0, m);
    int pos = m;
    while (pos && a[pos] >= 0) --pos;
    int H = s[pos];
    for (int i = 1; i <= n; ++i) {
        auto upd = [&] (int a, int b) {
            tr.update(1, 0, m, 1, ask(a), -1);
            tr.update(1, 0, m, 1, ask(b), 1);
        };
        for (pii p : t[i]) upd(mh[p.fir], min(p.sec, H));
        if (tr.mn[1] >= 0) ans = min(ans, H - h[i]);
        for (pii p : t[i]) upd(min(p.sec, H), mh[p.fir]);
    }
    if (ans >= inf) ans = -1;
    printf("%d\n", ans);
    return 0;
}
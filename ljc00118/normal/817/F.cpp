#include <bits/stdc++.h>
#define int long long
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 6e5 + 5, INF = 0x7fffffff;

struct node_t {
    int l, r, tag, rev, mn[2];
    node_t () { mn[0] = mn[1] = INF; tag = -1; rev = 0; }
} p[N << 2];

void update(int u) {
    for(register int i = 0; i <= 1; i++)
        p[u].mn[i] = min(p[u << 1].mn[i], p[u << 1 | 1].mn[i]);
}

void mdf1(int u) { swap(p[u].mn[0], p[u].mn[1]); p[u].rev ^= 1; }

void mdf2(int u, int x) {
    p[u].rev = 0; p[u].tag = x;
    p[u].mn[x] = p[u].l; p[u].mn[x ^ 1] = INF;
}

void pushdown(int u) {
    if(~p[u].tag) {
        mdf2(u << 1, p[u].tag);
        mdf2(u << 1 | 1, p[u].tag);
        p[u].tag = -1;
    }
    if(p[u].rev) {
        mdf1(u << 1);
        mdf1(u << 1 | 1);
        p[u].rev = 0;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        p[u].mn[0] = l;
        p[u].mn[1] = INF;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
}

void change(int u, int l, int r, int x) {
    if(l <= p[u].l && p[u].r <= r) {
        if(x == 2) mdf2(u, 0);
        if(x == 1) mdf2(u, 1);
        if(x == 3) mdf1(u);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l) change(u << 1, l, r, x);
    if(mid + 1 <= r) change(u << 1 | 1, l, r, x);
    update(u);
}

int opt[N], l[N], r[N], pre[N], n, m, cnt;

#undef int
int main() {
#define int long long
    read(m); pre[++cnt] = 1;
    for(register int i = 1; i <= m; i++) {
        read(opt[i]); read(l[i]); read(r[i]);
        pre[++cnt] = l[i]; pre[++cnt] = r[i];
        if(l[i] - 1) pre[++cnt] = l[i] - 1;
        pre[++cnt] = r[i] + 1;
    }
    sort(pre + 1, pre + cnt + 1);
    n = unique(pre + 1, pre + cnt + 1) - pre - 1;
    build(1, 1, n);
    for(register int i = 1; i <= m; i++) {
        l[i] = lower_bound(pre + 1, pre + n + 1, l[i]) - pre;
        r[i] = lower_bound(pre + 1, pre + n + 1, r[i]) - pre;
        fprintf(stderr, "l[%I64d] = %I64d, r[%I64d] = %I64d\n", i, l[i], i, r[i]);
        change(1, l[i], r[i], opt[i]); print(pre[p[1].mn[0]], '\n');
    }
    return 0;
}
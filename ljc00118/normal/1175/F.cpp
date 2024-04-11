#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
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

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    void clear() { *this = hash_map_t(mod); }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 3e5 + 5;

struct node_t { int l, r, maxn, tag; } p[N << 2];

void update(int u) { p[u].maxn = max(p[u << 1].maxn, p[u << 1 | 1].maxn); }

void add_tag(int u, int x) { p[u].maxn += x; p[u].tag += x; }

void pushdown(int u) {
    if(p[u].tag) {
        add_tag(u << 1, p[u].tag);
        add_tag(u << 1 | 1, p[u].tag);
        p[u].tag = 0;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        p[u].maxn = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
}

void change(int u, int l, int r, int x) {
    if(l <= p[u].l && p[u].r <= r) {
        add_tag(u, x);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l) change(u << 1, l, r, x);
    if(mid + 1 <= r) change(u << 1 | 1, l, r, x);
    update(u);
}

int query(int u, int l, int r, int x) {
    if(l <= p[u].l && p[u].r <= r) {
        if(p[u].maxn != x) return 0;
        if(p[u].l == p[u].r) return 1;
        pushdown(u);
        return query(u << 1, l, r, x) + query(u << 1 | 1, l, r, x);
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1, ans = 0;
    if(mid >= l) ans += query(u << 1, l, r, x);
    if(mid + 1 <= r) ans += query(u << 1 | 1, l, r, x);
    return ans;
}

int st[N], a[N], pre[N];
int n, top, r, ans;

int main() {
    read(n); st[0] = n + 1; r = n;
    for(register int i = 1; i <= n; i++) read(a[i]);
    build(1, 1, n);
    for(register int l = n; l >= 1; l--) {
        change(1, l, l, -a[l]);
        while(top && a[st[top]] <= a[l]) {
            change(1, st[top], st[top - 1] - 1, a[st[top]] - a[l]);
            --top;
        }
        st[++top] = l;
        if(pre[a[l]]) r = min(r, pre[a[l]] - 1);
        pre[a[l]] = l;
        ans += query(1, l, r, l - 1);
    }
    print(ans, '\n');
    return 0;
}
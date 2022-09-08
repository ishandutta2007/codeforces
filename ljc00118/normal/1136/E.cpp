#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
#define mp make_pair
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

// u_i = a_i - g_i-1

const int N = 1e5 + 5, INF = 0x7fffffff;

struct node_t {
    int l, r;
    ll val, tag;
} p[N << 2];

ll a[N], k[N], g[N], gg[N];
int n, m;

void update(int u) { p[u].val = p[u << 1].val + p[u << 1 | 1].val; }

void add_tag(int u, ll x) {
    p[u].tag = x;
    p[u].val = (p[u].r - p[u].l + 1) * x;
}

void pushdown(int u) {
    if(p[u].tag != -INF) {
        add_tag(u << 1, p[u].tag);
        add_tag(u << 1 | 1, p[u].tag);
        p[u].tag = -INF;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r; p[u].tag = -INF;
    if(l == r) {
        p[u].val = a[l] - g[l - 1];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
}

void change(int u, int l, int r, ll x) {
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

ll query(int u, int l, int r) {
    if(l <= p[u].l && p[u].r <= r) return p[u].val;
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1; ll ans = 0;
    if(mid >= l) ans += query(u << 1, l, r);
    if(mid + 1 <= r) ans += query(u << 1 | 1, l, r);
    return ans;
}

ll calc(int x) { return x < 0 ? 0 : gg[x]; }

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]);
    for(register int i = 1; i < n; i++) {
        read(k[i]);
        g[i] = g[i - 1] + k[i];
        gg[i] = gg[i - 1] + g[i];
    }
    build(1, 1, n);
    read(m);
    while(m--) {
        static char c[5]; scanf("%s", c + 1);
        if(c[1] == 's') {
            int l, r;
            read(l); read(r);
            print(query(1, l, r) + calc(r - 1) - calc(l - 2), '\n');
        }
        if(c[1] == '+') {
            int x, y; read(x); read(y);
            // fprintf(stderr, "%I64d %I64d %I64d\n", query(1, 1, 1), query(1, 2, 2), query(1, 3, 3));
            ll now = query(1, x, x) + y;
            int l = x + 1, r = n, ans = x;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(query(1, mid, mid) <= now) ans = mid, l = mid + 1;
                else r = mid - 1;
            }
            change(1, x, ans, now);
        }
    }
    return 0;
}
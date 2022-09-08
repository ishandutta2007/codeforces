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

const ll pw[] = {1, 42, 1764, 74088, 3111696, 130691232, 5489031744ll, 230539333248ll, 9682651996416ll, 406671383849472ll};
const int N = 1e5 + 5;

struct node_t {
    int l, r, val;
    ll minn, _set, _add;
} p[N << 2];

int a[N];
int n, m;

void update(int u) { p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn); }

void add_set(int u, ll x) {
    int now = 1;
    while(pw[now] < x) ++now;
    p[u].val = now;
    p[u].minn = pw[now] - x;
    p[u]._set = x;
    p[u]._add = 0;
}

void add_tag(int u, ll x) {
    if(p[u]._set) p[u]._set += x;
    else p[u]._add += x;
    p[u].minn -= x;
}

void pushdown(int u) {
    if(p[u]._set) {
        add_set(u << 1, p[u]._set);
        add_set(u << 1 | 1, p[u]._set);
        p[u]._set = 0;
    }
    if(p[u]._add) {
        add_tag(u << 1, p[u]._add);
        add_tag(u << 1 | 1, p[u]._add);
        p[u]._add = 0;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        int now = 1;
        while(pw[now] < a[l]) ++now;
        p[u].val = now;
        p[u].minn = pw[now] - a[l];
        p[u]._set = p[u]._add = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
}

void change(int u, int l, int r, int x, int opt) {
    // fprintf(stderr, "change : %d %d %d %d %d\n", u, l, r, x, opt);
    if(l <= p[u].l && p[u].r <= r) {
        if(opt == 1) add_set(u, x);
        if(opt == 2) add_tag(u, x);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l) change(u << 1, l, r, x, opt);
    if(mid + 1 <= r) change(u << 1 | 1, l, r, x, opt);
    update(u);
}

void adaptive(int u) {
    if(p[u].minn >= 0) return;
    if(p[u].l == p[u].r) {
        while(p[u].minn < 0) {
            p[u].minn -= pw[p[u].val];
            p[u].minn += pw[++p[u].val];
        }
        return;
    }
    pushdown(u);
    adaptive(u << 1); adaptive(u << 1 | 1);
    update(u);
}

ll query(int u, int x) {
    if(p[u].l == p[u].r) return pw[p[u].val] - p[u].minn;
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= x) return query(u << 1, x);
    return query(u << 1 | 1, x);
}

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) read(a[i]);
    build(1, 1, n);
    for(register int i = 1; i <= m; i++) {
        int opt; read(opt);
        if(opt == 1) {
            int x; read(x);
            print(query(1, x), '\n');
        }
        if(opt == 2) {
            int l, r, x;
            read(l); read(r); read(x);
            change(1, l, r, x, 1);
        }
        if(opt == 3) {
            int l, r, x;
            read(l); read(r); read(x);
            change(1, l, r, x, 2);
            adaptive(1);
            while(p[1].minn == 0) {
                change(1, l, r, x, 2);
                adaptive(1);
            }
        }
    }
    return 0;
} //
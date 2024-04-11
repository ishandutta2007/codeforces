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

const int N = 1e6 + 5, M = 300005, MAXN = 1e6;

int maxn[N << 2], tag[N << 2];
int a[M], b[M];
int n, m, q;

void update(int u) { maxn[u] = max(maxn[u << 1], maxn[u << 1 | 1]); }

void add_tag(int u, int x) {
    maxn[u] += x;
    tag[u] += x;
}

void pushdown(int u) {
    if(tag[u]) {
        add_tag(u << 1, tag[u]);
        add_tag(u << 1 | 1, tag[u]);
        tag[u] = 0;
    }
}

void change(int u, int l, int r, int L, int R, int x) {
    if(l <= L && R <= r) {
        add_tag(u, x);
        return;
    }
    pushdown(u);
    int mid = (L + R) >> 1;
    if(mid >= l) change(u << 1, l, r, L, mid, x);
    if(mid + 1 <= r) change(u << 1 | 1, l, r, mid + 1, R, x);
    update(u);
}

int query(int u, int l, int r) {
    if(l == r) {
        if(maxn[u] <= 0) return -1;
        return l;
    }
    pushdown(u);
    int mid = (l + r) >> 1;
    if(maxn[u << 1 | 1] > 0) return query(u << 1 | 1, mid + 1, r);
    return query(u << 1, l, mid);
}

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) read(a[i]), change(1, 1, a[i], 1, MAXN, 1);
    for(register int i = 1; i <= m; i++) read(b[i]), change(1, 1, b[i], 1, MAXN, -1);
    read(q); while(q--) {
        int opt, x, y;
        read(opt); read(x); read(y);
        if(opt == 1) {
            change(1, 1, a[x], 1, MAXN, -1);
            a[x] = y;
            change(1, 1, a[x], 1, MAXN, 1);
        }
        if(opt == 2) {
            change(1, 1, b[x], 1, MAXN, 1);
            b[x] = y;
            change(1, 1, b[x], 1, MAXN, -1);
        }
        print(query(1, 1, MAXN), '\n');
    }
    return 0;
} //
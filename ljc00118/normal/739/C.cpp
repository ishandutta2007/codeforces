#include <bits/stdc++.h>
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

const int N = 3e5 + 5;

struct node_t {
    int l, r, lmax, rmax, maxn, lans, rans;
} p[N << 2];

int a[N]; ll val[N];
int n, m;

void update(int u) {
    if(p[u << 1].lmax == p[u << 1].r - p[u << 1].l + 1) p[u].lmax = p[u << 1].lmax + p[u << 1 | 1].lmax; else p[u].lmax = p[u << 1].lmax;
    if(p[u << 1 | 1].rmax == p[u << 1 | 1].r - p[u << 1 | 1].l + 1) p[u].rmax = p[u << 1 | 1].rmax + p[u << 1].rmax; else p[u].rmax = p[u << 1 | 1].rmax;
    if(p[u << 1].rmax == p[u << 1].r - p[u << 1].l + 1) p[u].lans = p[u << 1].rmax + max(p[u << 1 | 1].lmax, p[u << 1 | 1].lans); else p[u].lans = p[u << 1].lans;
    if(p[u << 1 | 1].lmax == p[u << 1 | 1].r - p[u << 1 | 1].l + 1) p[u].rans = p[u << 1 | 1].lmax + max(p[u << 1].rmax, p[u << 1].rans); else p[u].rans = p[u << 1 | 1].rans;
    if(p[u << 1].rans == p[u << 1].r - p[u << 1].l + 1) p[u].lans = max(p[u].lans, p[u << 1].rans + p[u << 1 | 1].lmax);
    if(p[u << 1 | 1].lans == p[u << 1 | 1].r - p[u << 1 | 1].l + 1) p[u].rans = max(p[u].rans, p[u << 1 | 1].lans + p[u << 1].rmax);
    if(p[u].lans == p[u].r - p[u].l + 1) { p[u].rans = p[u].lans; } if(p[u].rans == p[u].r - p[u].l + 1) p[u].lans = p[u].rans;
    p[u].maxn = max(max(p[u << 1].rmax + p[u << 1 | 1].lmax, max(p[u << 1].maxn, p[u << 1 | 1].maxn)), max(p[u << 1].rmax + p[u << 1 | 1].lans, p[u << 1 | 1].lmax + p[u << 1].rans));
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        val[l] = a[l + 1] - a[l];
        if(val[l] < 0) p[u].lmax = p[u].maxn = p[u].rans = 1, p[u].rmax = p[u].lans = 0;
        else if(val[l] == 0) p[u].lmax = p[u].rmax = p[u].maxn = p[u].lans = p[u].rans = 0;
        else p[u].rmax = p[u].maxn = p[u].lans = 1, p[u].lmax = p[u].rans = 0;
        return;
    }
    int mid = (l + r) >> 1; 
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    update(u);
}

void change(int u, int x, int y) {
    if(p[u].l == p[u].r) {
        val[x] += y;
        if(val[x] < 0) p[u].lmax = p[u].maxn = p[u].rans = 1, p[u].rmax = p[u].lans = 0;
        else if(val[x] == 0) p[u].lmax = p[u].rmax = p[u].maxn = p[u].lans = p[u].rans = 0;
        else p[u].rmax = p[u].maxn = p[u].lans = 1, p[u].lmax = p[u].rans = 0;
        return;
    }
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= x) change(u << 1, x, y);
    else change(u << 1 | 1, x, y);
    update(u);
}

void dfs(int u, int l, int r) {
    fprintf(stderr, "l = %d, r = %d, lmax = %d, rmax = %d, lans = %d, rans = %d, maxn = %d\n", l, r, p[u].lmax, p[u].rmax, p[u].lans, p[u].rans, p[u].maxn);
    if(l == r) return;
    int mid = (l + r) >> 1;
    dfs(u << 1, l, mid);
    dfs(u << 1 | 1, mid + 1, r);
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]);
    read(m);
    if(n == 1) {
        while(m--) print(1, '\n');
        return 0;
    }
    build(1, 1, n - 1);
    while(m--) {
        int l, r, x;
        read(l); read(r); read(x);
        if(l != 1) change(1, l - 1, x);
        if(r != n) change(1, r, -x);
        print(p[1].maxn + 1, '\n');
    }
    // dfs(1, 1, n - 1);
    return 0;
}
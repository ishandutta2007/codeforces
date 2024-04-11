#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 1e5 + 5;

int ls[N], rs[N], siz[N], key[N];
ll val[N], tag[N];
int a[N];
ll ans, sum;
int n, tot, root;

inline int newNode(ll x = 0) {
    ++tot; ls[tot] = rs[tot] = tag[tot] = 0;
    siz[tot] = 1; val[tot] = x; key[tot] = ((rand() << 15) ^ rand());
    return tot;
}

void update(int u) { siz[u] = siz[ls[u]] + siz[rs[u]] + 1; }

void addTag(int u, ll x) {
    if(!u) return;
    val[u] += x;
    tag[u] += x;
}

void pushdown(int u) {
    if(tag[u]) {
        addTag(ls[u], tag[u]);
        addTag(rs[u], tag[u]);
        tag[u] = 0;
    }
}

int merge(int u, int v) {
    if(!u || !v) return u | v;
    pushdown(u); pushdown(v);
    if(key[u] <= key[v]) {
        rs[u] = merge(rs[u], v); return update(u), u;
    } else {
        ls[v] = merge(u, ls[v]); return update(v), v;
    }
}

// a[i] = x, find f[i][j - 1] + a[i] * j >= f[i][j], a[i] * j >= f[i][j] - f[i][j - 1]

void split(int u, int s, int x, int &l, int &r) {
    if(!u) { l = r = 0; return; }
    pushdown(u);
    if(val[u] <= 1ll * (s + siz[ls[u]] + 1) * x) {
        r = u; split(ls[u], s, x, l, ls[r]); update(r);
    } else {
        l = u; split(rs[u], s + siz[ls[u]] + 1, x, rs[l], r); update(l);
    }
}

void dfs1(int u) {
    if(!u) return;
    pushdown(u);
    dfs1(ls[u]);
    sum += val[u];
    ans = max(ans, sum);
    dfs1(rs[u]);
}

int main() {
    srand(time(0));
    read(n);
    for(register int i = 1; i <= n; i++) {
        read(a[i]);
        int l, r;
        split(root, 0, a[i], l, r);
        int now = newNode(1ll * (siz[l] + 1) * a[i]);
        addTag(r, a[i]);
        root = merge(merge(l, now), r);
    }
    dfs1(root); print(ans, '\n');
    return 0;
}
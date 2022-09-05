#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5;

struct vec {
    int x, y;
    vec (int a = 0, int b = 0) : x(a), y(b) {}
};

bool operator < (const vec a, const vec b) {
    return 1ll * a.y * b.x < 1ll * b.y * a.x;
}

vec operator + (const vec a, const vec b) {
    return vec(a.x + b.x, a.y + b.y);
}

vec operator - (const vec a, const vec b) {
    return vec(a.x - b.x, a.y - b.y);
}

mt19937 rng(20050403);
vec val[N], sum[N];
int lc[N], rc[N], key[N], siz[N];
int tot;

inline int newNode(vec x) {
    ++tot;
    val[tot] = sum[tot] = x; key[tot] = rng(); siz[tot] = 1;
    return tot;
}

void update(int u) {
    sum[u] = sum[lc[u]] + sum[rc[u]] + val[u];
    siz[u] = siz[lc[u]] + siz[rc[u]] + 1;
}

int merge(int u, int v) {
    if (!u || !v) return u | v;
    if (key[u] < key[v]) {
        rc[u] = merge(rc[u], v);
        update(u);
        return u;
    } else {
        lc[v] = merge(u, lc[v]);
        update(v);
        return v;
    }
}

void split(int u, vec x, int &l, int &r) {
    if (!u) { l = r = 0; return; }
    if (x < val[u]) {
        l = u;
        split(rc[u], x, rc[l], r);
        update(l);
    } else {
        r = u;
        split(lc[u], x, l, lc[r]);
        update(r);
    }
}

void splitk(int u, int k, int &l, int &r) {
    if (!u) { l = r = 0; return; }
    if (k > siz[lc[u]]) {
        l = u;
        splitk(rc[u], k - siz[lc[u]] - 1, rc[l], r);
        update(l);
    } else {
        r = u;
        splitk(lc[u], k, l, lc[r]);
        update(r);
    }
}

int seq[N], slen;
void getseq(int u) {
    if (!u) return;
    getseq(lc[u]);
    seq[++slen] = u;
    getseq(rc[u]);
}

vector <pii> qry[N];
vector <int> adj[N];
int ans[N], rt[N];
int n, q;

void dfs1(int u, int fa) {
    vec sum = vec(1, 0);
    int wson = 0, maxn = 0;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        dfs1(v, u); ++sum.y;
        if (siz[rt[v]] >= maxn) {
            maxn = siz[rt[v]];
            wson = v;
        }
    }
    // cout << 1 << endl;
    rt[u] = rt[wson];
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa || v == wson) continue;
        slen = 0; getseq(rt[v]);
        for (int j = 1; j <= slen; j++) {
            int l, r;
            lc[seq[j]] = rc[seq[j]] = 0; siz[seq[j]] = 1; ::sum[seq[j]] = val[seq[j]];
            split(rt[u], val[seq[j]], l, r);
            rt[u] = merge(l, merge(seq[j], r));
        }
    }
    // if (u == 2) {
    //     fprintf(stderr, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    //     slen = 0; getseq(rt[u]);
    //     fprintf(stderr, "%d : ", u);
    //     for (int i = 1; i <= slen; i++) {
    //         fprintf(stderr, "{%d, %d, %d}, ", seq[i], val[seq[i]].x, val[seq[i]].y);
    //     }
    //     fprintf(stderr, "\n");
    // }
    for (auto i : qry[u]) {
        if (!wson) continue;
        int l, r;
        split(rt[u], vec(1, i.first), l, r);
        ans[i.second] = ::sum[l].y + sum.y - ::sum[l].x * i.first;
        rt[u] = merge(l, r);
    }
    while (rt[u]) {
        int l, r;
        splitk(rt[u], 1, l, r);
        if (sum - vec(0, 1) < val[l]) {
            sum = sum + val[l];
            rt[u] = r;
        } else {
            rt[u] = merge(l, r);
            break;
        }
    }
    // fprintf(stderr, "sum = {%d, %d}\n", sum.x, sum.y);
    // fprintf(stderr, "u = %d\n", u);
    rt[u] = merge(newNode(sum - vec(0, 1)), rt[u]);
    // fprintf(stderr, "tot = %d, val[tot] = {%d, %d}\n", tot, val[tot].x, val[tot].y);
    // slen = 0; getseq(rt[u]);
    // fprintf(stderr, "%d : ", u);
    // for (int i = 1; i <= slen; i++) {
    //     fprintf(stderr, "{%d, %d, %d}, ", seq[i], val[seq[i]].x, val[seq[i]].y);
    // }
    // fprintf(stderr, "\n");
}

int main() {
    read(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    read(q);
    for (int i = 1; i <= q; i++) {
        int v, k;
        read(v); read(k);
        qry[v].emplace_back(k, i);
    }
    dfs1(1, 0);
    for (int i = 1; i <= q; i++) print(ans[i], '\n');
    return 0;
}
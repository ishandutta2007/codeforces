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

const int N = 2e5 + 5, M = N * 60, ALL = (1 << 20) - 1;

int ch[M][2], tag0[M], tag1[M], tagx[M], siz[M], can[M], tot;
int a[N];

void update(int u, int dep) {
    siz[u] = siz[ch[u][0]] + siz[ch[u][1]];
    can[u] = can[ch[u][0]] | can[ch[u][1]];
    if (ch[u][0] && ch[u][1]) can[u] |= (1 << dep);
}

void add_tag(int u, int tg0, int tg1, int tgx) {
    int tem = ALL ^ tg0 ^ tg1 ^ tgx, temu = ALL ^ tag0[u] ^ tag1[u] ^ tagx[u];
    int ans0 = tg0 | (tag1[u] & tgx) | (tag0[u] & tem);
    int ans1 = tg1 | (tag0[u] & tgx) | (tag1[u] & tem);
    tagx[u] = (tagx[u] & tem) | (tgx & temu);
    tag0[u] = ans0; tag1[u] = ans1;
}

int merge(int u, int v, int dep);

void pushdown(int u, int dep) {
    if ((tag0[u] >> dep) & 1) {
        ch[u][0] = merge(ch[u][0], ch[u][1], dep - 1); ch[u][1] = 0;
    }
    if ((tag1[u] >> dep) & 1) {
        ch[u][1] = merge(ch[u][0], ch[u][1], dep - 1); ch[u][0] = 0;
    }
    if ((tagx[u] >> dep) & 1) {
        swap(ch[u][0], ch[u][1]);
    }
    update(u, dep);
    for (int i = 0; i <= 1; i++) {
        if (ch[u][i]) {
            add_tag(ch[u][i], tag0[u], tag1[u], tagx[u]);
        }
    }
    tag0[u] = tag1[u] = tagx[u] = 0;
}

void check(int u, int dep) {
    if (!u || dep == -1) return;
    if (((tag0[u] | tag1[u]) & can[u]) == 0) return;
    pushdown(u, dep);
    check(ch[u][0], dep - 1); check(ch[u][1], dep - 1);
    update(u, dep);
}

int merge(int u, int v, int dep) {
    if (!u || !v) return u | v;
    if (dep == -1) return u;
    pushdown(u, dep); pushdown(v, dep);
    ch[u][0] = merge(ch[u][0], ch[v][0], dep - 1);
    ch[u][1] = merge(ch[u][1], ch[v][1], dep - 1);
    update(u, dep); return u;
}   

// split <= x
void split(int u, int x, int &l, int &r, int dep) {
    if (!u) { l = r = 0; return; }
    if (dep == -1) {
        l = u; r = 0;
        return;
    }
    pushdown(u, dep);
    if ((x >> dep) & 1) {
        l = u; r = ++tot;
        split(ch[u][1], x, ch[l][1], ch[r][1], dep - 1);
        update(l, dep); update(r, dep);
        if (!siz[r]) r = 0;
    } else {
        l = ++tot; r = u;
        split(ch[u][0], x, ch[l][0], ch[r][0], dep - 1);
        update(l, dep); update(r, dep);
        if (!siz[l]) l = 0;
    }
}

void insert(int &u, int x, int dep) {
    if (dep == -1) {
        u = ++tot;
        siz[tot] = 1;
        return;
    }
    if (!u) u = ++tot;
    insert(ch[u][(x >> dep) & 1], x, dep - 1);
    update(u, dep);
}

void dfs(int u, int dep) {
    if (!u) return;
    // if (dep != -1) pushdown(u, dep);
    fprintf(stderr, "u = %d, tag0[u] = %d, tag1[u] = %d, tagx[u] = %d, ch[u][0] = %d, ch[u][1] = %d, siz[u] = %d, dep = %d\n", u, tag0[u], tag1[u], tagx[u], ch[u][0], ch[u][1], siz[u], dep);
    dfs(ch[u][0], dep - 1); dfs(ch[u][1], dep - 1);
}

int n, q, root;

int main() {
    read(n); read(q);
    for (int i = 1; i <= n; i++) {
        int a; read(a);
        insert(root, a, 19);
    }
    while (q--) {
        int opt, l, r; read(opt); read(l); read(r);
        int a = 0, b = 0, c = 0;
        // fprintf(stderr, "root = %d\n", root);
        if (l != 0) split(root, l - 1, a, b, 19);
        else b = root;
        split(b, r, b, c, 19);
        if (opt <= 3) {
            int x; read(x);
            if (opt == 1) add_tag(b, ALL ^ x, 0, 0);
            if (opt == 2) add_tag(b, 0, x, 0);
            if (opt == 3) add_tag(b, 0, 0, x);
            // fprintf(stderr, ">>> %d\n", can[b] & (tag0[b] | tag1[b]));
            check(b, 19);
        }
        // dfs(b, 19);
        if (opt == 4) print(siz[b], '\n');
        // fprintf(stderr, "b = %d, tag0[b] = %d, tag1[b] = %d, tag2[b] = %d\n", b, tag0[b], tag1[b], tagx[b]);
        root = merge(merge(a, b, 19), c, 19);
        // dfs(root, 19);
    }
    return 0;
}
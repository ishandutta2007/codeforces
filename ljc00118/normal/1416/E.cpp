#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

mt19937 R(std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 5e5 + 5, INF = 1e9;

struct node_t { int lc, rc, siz, len, minn, val, tag, rev, key; } p[N * 5];

int a[N];
int T, n, tot, root, add, naive;

inline int newNode(int len, int val) {
    ++tot; p[tot].lc = p[tot].rc = p[tot].rev = 0; p[tot].tag = INF;
    p[tot].siz = p[tot].len = len; p[tot].val = p[tot].minn = val; p[tot].key = (int)R();
    return tot;
}

void update(int u) {
    p[u].minn = min(p[u].val, min(p[p[u].lc].minn, p[p[u].rc].minn));
    p[u].siz = p[p[u].lc].siz + p[p[u].rc].siz + p[u].len;
}

void add_tag(int u, int x) {
    p[u].val = min(p[u].val, x);
    p[u].tag = min(p[u].tag, x);
    p[u].minn = min(p[u].minn, x);
}

void add_rev(int u) {
    p[u].rev ^= 1;
    swap(p[u].lc, p[u].rc);
}

void pushdown(int u) {
    if (p[u].tag != INF) {
        if (p[u].lc) add_tag(p[u].lc, p[u].tag);
        if (p[u].rc) add_tag(p[u].rc, p[u].tag);
        p[u].tag = INF;
    }
    if (p[u].rev) {
        if (p[u].lc) add_rev(p[u].lc);
        if (p[u].rc) add_rev(p[u].rc);
        p[u].rev = 0;
    }
}

int merge(int u, int v) {
    if (!u || !v) return u | v;
    pushdown(u); pushdown(v);
    if (p[u].key < p[v].key) {
        p[u].rc = merge(p[u].rc, v);
        return update(u), u;
    } else {
        p[v].lc = merge(u, p[v].lc);
        return update(v), v;
    }
}

pii operator + (const pii a, const int b) {
    return make_pair(a.first, a.second + b);
}

pii find(int u, int x) {
    // cout << u << " " << x << " " << p[p[u].lc].siz << " " << p[u].len << " " << p[p[u].rc].siz << " " << p[u].siz << endl;
    if (p[p[u].lc].siz < x && x <= p[p[u].lc].siz + p[u].len) return make_pair(u, p[p[u].lc].siz);
    pushdown(u);
    if (x <= p[p[u].lc].siz) return find(p[u].lc, x);
    return find(p[u].rc, x - p[p[u].lc].siz - p[u].len) + (p[p[u].lc].siz + p[u].len);
}

void split(int u, int x, int &l, int &r) {
    // cout << u << " " << x << " " << p[u].siz << endl;
    if (!u) { l = r = 0; return; }
    pushdown(u);
    if (p[p[u].lc].siz + p[u].len <= x) {
        l = u;
        split(p[u].rc, x - p[p[u].lc].siz - p[u].len, p[l].rc, r);
        update(l);
    } else {
        r = u;
        split(p[u].lc, x, l, p[r].lc);
        update(r);
    }
}

void split(int x) {
    pii u = find(root, x);
    // fprintf(stderr, "x = %d, len = %d, lsiz = %d\n", x, p[u.first].len, u.second);
    if (p[u.first].len + u.second != x) {
        int l, mid, r;
        split(root, p[u.first].len + u.second, mid, r);
        split(mid, u.second, l, mid);
        int mid2 = newNode(p[u.first].len + u.second - x, p[u.first].val);
        p[mid].len = p[mid].siz = x - u.second;
        root = merge(merge(merge(l, mid), mid2), r);
    }
}

void changev(int u, int x, int val) {
    pushdown(u);
    if (p[p[u].lc].siz + 1 == x) {
        p[u].val = min(p[u].val, val);
        update(u);
        return;
    }
    if (x <= p[p[u].lc].siz) changev(p[u].lc, x, val);
    else changev(p[u].rc, x - p[p[u].lc].siz - p[u].len, val);
    update(u);
}

int main() {
    p[0].minn = INF;
    read(T);
    while (T--) {
        read(n); root = tot = add = 0;
        for (int i = 1; i <= n; i++) read(a[i]);
        root = newNode(INF, 1);
        for (int i = 1; i <= n; i++) {
            int half, all = p[root].minn + add;
            // cout << "!" << p[find(root, a[i] / 2).first].val << endl;
            if (a[i] % 2 == 0) half = p[find(root, a[i] / 2).first].val + add;
            // fprintf(stderr, "half = %d, all = %d\n", half, all);
            split(a[i] - 1); split(root, a[i] - 1, root, naive);
            add_rev(root); ++add; add_tag(root, all + 2 - add);
            if (a[i] % 2 == 0) {
                if (a[i] / 2 != 1) split(a[i] / 2 - 1);
                split(a[i] / 2);
                // fprintf(stderr, "val = %d, len = %d\n", min(p[mid].val, min(half, all + 1) - add), p[l].len);
                changev(root, a[i] / 2, min(half, all + 1) - add);
            }
            root = merge(root, newNode(INF, INF));
        }
        print(p[root].minn + add, '\n');
    }
    return 0;
}
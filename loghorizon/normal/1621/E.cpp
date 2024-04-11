// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 4e5 + 5;

int n, m, a[N], t, pa[N], pc[N];

vector<int> b[N], pb[N];

struct Node{
    LL a, b;
    int o, x, y;
    bool operator < (const Node &c) const {
        LL A = 1ll * a * c.b, B = 1ll * c.a * b;
        if (A == B) return o > c.o;
        return A < B;
    }
} e[N];

#define ls p << 1
#define rs p << 1 | 1

int mn[N << 2], tag[N << 2];

void inline pushup(int p) {
    mn[p] = min(mn[ls], mn[rs]);
}

void inline add(int p, int k) {
    tag[p] += k, mn[p] += k;
}

void inline pushdown(int p) {
    if (tag[p]) {
        add(ls, tag[p]), add(rs, tag[p]);
        tag[p] = 0;
    }
}

void build(int p, int l, int r) {
    tag[p] = 0; mn[p] = 0;
    if (l == r){
         return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(p);
}

void change(int p, int l, int r, int x, int y, int k) {
    if (x <= l && r <= y) {
        add(p, k);
        return;
    }
    pushdown(p);
    int mid = (l + r) >> 1;
    if (x <= mid) change(ls, l, mid, x, y, k);
    if (mid < y) change(rs, mid + 1, r, x, y, k);
    pushup(p);
}
 
void inline clr() {
    for (int i = 1; i <= m; i++) b[i].clear(), pb[i].clear();
}

int main() {
    int T; read(T);
    while (T--) {
        t = 0;
        read(n), read(m);
        for (int i = 1; i <= n; i++) read(a[i]), e[++t] = (Node) { a[i], 1, 1, i, 0 };
        for (int i = 1; i <= m; i++) {
            int k; read(k);
            LL s = 0;
            for (int j = 0; j < k; j++) {
                int x; read(x);
                b[i].pb(x);
                s += x;
            }
            e[++t] = (Node) { s, k, 2, i, 0 };
            for (int j = 0; j < k; j++) {
                e[++t] = (Node) { s - b[i][j], k - 1, 3, i, j };
            }
            pb[i].resize(k, 0);
        }
        sort(e + 1, e + 1 + t);
        build(1, 1, t);
        for (int i = 1; i <= t; i++) {
            Node u = e[i];
            if (u.o == 1) {
                pa[u.x] = i;
                change(1, 1, t, 1, i, 1);
            } else if (u.o == 2) {
                pc[u.x] = i;
                change(1, 1, t, 1, i, -1);
            } else {
                pb[u.x][u.y] = i;
            }
        }
        for (int i = 1; i <= m; i++) {
            change(1, 1, t, 1, pc[i], 1);
            for (int j = 0; j < b[i].size(); j++) {
                change(1, 1, t, 1, pb[i][j], -1);
                putchar(mn[1] < 0 ? '0' : '1');
                change(1, 1, t, 1, pb[i][j], 1);
            }
            change(1, 1, t, 1, pc[i], -1);
        }
        puts("");
        clr();
    }
    return 0;
}
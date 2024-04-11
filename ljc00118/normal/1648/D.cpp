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

const ll INF = 1e18;
const int N = 5e5 + 5;

struct node_t { int l, r; ll tag1, tag2, maxn, mxk; } p[N << 2];

vector <int> add[N], del[N];
ll s[4][N], ans = -INF;
int a[4][N], l[N], r[N], k[N];
int n, q;

void update(int u) {
    p[u].maxn = max(p[u << 1].maxn, p[u << 1 | 1].maxn);
    p[u].mxk = max(p[u << 1].mxk, p[u << 1 | 1].mxk);
}

void add_tag1(int u, ll x) {
    p[u].tag1 += x;
    if (p[u].tag2 != -INF) p[u].tag2 += x;
    p[u].maxn += x;
}

void add_tag2(int u, ll x) {
    if (p[u].mxk == -INF) return;
    p[u].maxn = max(p[u].maxn, x + p[u].mxk);
    p[u].tag2 = max(p[u].tag2, x);
}

void pushdown(int u) {
    if (p[u].tag1) {
        add_tag1(u << 1, p[u].tag1);
        add_tag1(u << 1 | 1, p[u].tag1);
        p[u].tag1 = 0;
    }
    if (p[u].tag2 != -INF) {
        add_tag2(u << 1, p[u].tag2);
        add_tag2(u << 1 | 1, p[u].tag2);
        p[u].tag2 = -INF;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r; p[u].tag2 = -INF;
    if (l == r) {
        p[u].mxk = p[u].maxn = -INF;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    update(u);
}

void ins(int u, int x, ll y) {
    if (p[u].l == p[u].r) {
        p[u].maxn = y - k[x];
        p[u].mxk = -k[x];
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= x) ins(u << 1, x, y);
    else ins(u << 1 | 1, x, y);
    update(u);
}

void era(int u, int x) {
    if (p[u].l == p[u].r) {
        p[u].maxn = p[u].mxk = -INF;
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= x) era(u << 1, x);
    else era(u << 1 | 1, x);
    update(u);
}

int main() {
    read(n); read(q);
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) read(a[i][j]), s[i][j] = s[i][j - 1] + a[i][j];
    }
    for (int i = 1; i <= q; i++) {
        read(l[i]); read(r[i]); read(k[i]);
        add[l[i]].push_back(i);
        del[r[i] + 1].push_back(i);
    }
    build(1, 1, q);
    for (int i = 1; i <= n; i++) {
        for (auto j : add[i]) {
            ll maxn = max(s[1][i], p[1].maxn);
            ins(1, j, maxn);
        }
        add_tag2(1, s[1][i]);
        add_tag1(1, a[2][i]);
        for (auto j : del[i]) era(1, j);
        ans = max(ans, p[1].maxn + s[3][n] - s[3][i - 1]);
    }
    print(ans, '\n');
    return 0;
}
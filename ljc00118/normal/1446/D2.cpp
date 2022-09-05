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

const int N = 2e5 + 5;

struct node_t { int l, r, maxn, minn, tag; } p[N << 2];

void update(int u) {
    p[u].maxn = max(p[u << 1].maxn, p[u << 1 | 1].maxn);
    p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn);
}

void add_tag(int u, int x) {
    p[u].maxn += x;
    p[u].minn += x;
    p[u].tag += x;
}

void pushdown(int u) {
    if (p[u].tag) {
        add_tag(u << 1, p[u].tag);
        add_tag(u << 1 | 1, p[u].tag);
        p[u].tag = 0;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
}

void add(int u, int l, int r, int x) {
    if (l <= p[u].l && p[u].r <= r) {
        add_tag(u, x);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= l) add(u << 1, l, r, x);
    if (mid + 1 <= r) add(u << 1 | 1, l, r, x);
    update(u);
}

int query(int u, int l, int r) {
    if (l <= p[u].l && p[u].r <= r) return p[u].maxn;
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1, ans = -N;
    if (mid >= l) ans = max(ans, query(u << 1, l, r));
    if (mid + 1 <= r) ans = max(ans, query(u << 1 | 1, l, r));
    return ans;
}

int queryl(int u, int x) {
    if (p[u].l == p[u].r) return p[u].l;
    pushdown(u);
    if (p[u << 1].minn <= x && x <= p[u << 1].maxn) return queryl(u << 1, x);
    return queryl(u << 1 | 1, x);
}

int queryr(int u, int x) {
    if (p[u].l == p[u].r) return p[u].l;
    pushdown(u);
    if (p[u << 1 | 1].minn <= x && x <= p[u << 1 | 1].maxn) return queryr(u << 1 | 1, x);
    return queryr(u << 1, x);
}

vector <int> pos[N];
int a[N], cnt[N];
int n, maxn, mxcnt, ans;

int main() {
    // freopen("input.txt", "r", stdin);
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        ++cnt[a[i]];
        if (cnt[a[i]] > maxn) {
            maxn = cnt[a[i]];
            mxcnt = 1;
        } else if (cnt[a[i]] == maxn) ++mxcnt;
        pos[a[i]].push_back(i);
    }
    if (mxcnt > 1) {
        print(n, '\n');
        return 0;
    }
    maxn = 1;
    for (int i = 2; i <= n; i++) {
        if (cnt[i] > cnt[maxn]) {
            maxn = i;
        }
    }
    build(1, 0, n);
    for (int i = 1; i <= n; i++) {
        if (a[i] == maxn) {
            add(1, i, n, 1);
        }
    }
    for (int _ = 1; _ <= n; _++) {
        if (_ == maxn) continue;
        reverse(pos[_].begin(), pos[_].end());
        for (auto i : pos[_]) {
            add(1, i, n, -1);
        }
        int las = N;
        for (auto i : pos[_]) {
            int now = query(1, i, i), pre = query(1, 0, i);
            pre = min(pre, las);
            if (pre >= now) {
                for (int j = pre; j >= now; j--) {
                    int L = queryl(1, j), R = queryr(1, j);
                    // fprintf(stderr, "_ = %d, j = %d, L = %d, R = %d\n", _, j, L, R);
                    ans = max(ans, R - L);
                }
                las = now - 1;
            }
        }
        for (auto i : pos[_]) {
            add(1, i, n, 1);
        }
    }
    print(ans, '\n');
    return 0;
}
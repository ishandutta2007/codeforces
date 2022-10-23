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

struct node_t { int l, r, minn; ll ans; } p[N << 2];

multiset <int> v[N];
int a[N], val[N];
int n, q;

ll query(int u, int x) {
    if (p[u].l == p[u].r) return min(p[u].minn, x);
    if (p[u << 1 | 1].minn > x) return query(u << 1, x) + 1ll * x * (p[u << 1 | 1].r - p[u << 1 | 1].l + 1);
    return p[u].ans - p[u << 1 | 1].ans + query(u << 1 | 1, x);
}

void update(int u) {
    p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn);
    p[u].ans = p[u << 1 | 1].ans + query(u << 1, p[u << 1 | 1].minn);
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if (l == r) {
        p[u].minn = p[u].ans = val[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    update(u);
}

void modify(int u, int x, int y) {
    if (p[u].l == p[u].r) {
        p[u].minn = p[u].ans = y;
        return;
    }
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= x) modify(u << 1, x, y);
    else modify(u << 1 | 1, x, y);
    update(u);
}

void del(int i, int j) {
    int prev = val[i];
    v[i].erase(v[i].find(j));
    val[i] = n;
    if (v[i].size()) val[i] = *v[i].begin();
    if (prev != val[i]) modify(1, i, val[i]);
}

void ins(int i, int j) {
    int prev = val[i];
    v[i].insert(j);
    val[i] = *v[i].begin();
    if (prev != val[i]) modify(1, i, val[i]);
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        if (i > a[i]) v[i - a[i]].insert(i - 1);
    }
    for (int i = 1; i <= n; i++) {
        if (v[i].size()) val[i] = *v[i].begin();
        else val[i] = n;
    }
    build(1, 1, n);
    read(q);
    while (q--) {
        int x, y;
        read(x); read(y);
        if (x > a[x]) del(x - a[x], x - 1);
        if (x > y) ins(x - y, x - 1);
        print(p[1].ans - 1ll * n * (n - 1) / 2, '\n');
        if (x > a[x]) ins(x - a[x], x - 1);
        if (x > y) del(x - y, x - 1);
    }
    return 0;
}
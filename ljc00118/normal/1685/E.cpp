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

struct seg_t {
    ll mx[N << 2], tag[N << 2];

    void update(int u) {
        mx[u] = max(mx[u << 1], mx[u << 1 | 1]);
    }

    void add_tag(int u, ll x) {
        mx[u] += x;
        tag[u] += x;
    }

    void pushdown(int u) {
        if (tag[u]) {
            add_tag(u << 1, tag[u]);
            add_tag(u << 1 | 1, tag[u]);
            tag[u] = 0;
        }
    }

    void add(int u, int L, int R, int l, int r, int x) {
        if (l <= L && R <= r) {
            add_tag(u, x);
            return;
        }
        pushdown(u);
        int mid = (L + R) >> 1;
        if (mid >= l) add(u << 1, L, mid, l, r, x);
        if (mid + 1 <= r) add(u << 1 | 1, mid + 1, R, l, r, x);
        update(u);
    }

    ll query(int u, int l, int r, int x) {
        if (l == r) return mx[u];
        pushdown(u);
        int mid = (l + r) >> 1;
        if (mid >= x) return query(u << 1, l, mid, x);
        return query(u << 1 | 1, mid + 1, r, x);
    }

    int getpos(int u, int l, int r) {
        if (l == r) return l;
        pushdown(u);
        int mid = (l + r) >> 1;
        if (mx[u << 1] > mx[u << 1 | 1]) return getpos(u << 1, l, mid);
        return getpos(u << 1 | 1, mid + 1, r);
    }
} tr1, tr2;

int a[N], pos[N];
int n, q;

void add1(int i, int coef) {
    int val = 0;
    if (a[i] <= n) val = 1;
    if (a[i] >= n + 2) val = -1;
    // fprintf(stderr, "i = %d, val = %d, coef = %d\n", i, val, coef);
    tr1.add(1, 1, n * 2 + 1, i, 2 * n + 1, val * coef);
}

void add2(int i, int coef) {
    int l = max(1, i - n + 1), r = min(n + 1, i);
    int dis = (pos[i] < pos[i + 1] ? pos[i + 1] - pos[i] : pos[i + 1] + 2 * n + 1 - pos[i]);
    tr2.add(1, 1, n + 1, l, r, dis * coef);
}

int main() {
    read(n); read(q);
    for (int i = 1; i <= n * 2 + 1; i++) read(a[i]), pos[a[i]] = i;
    for (int i = 1; i <= n * 2 + 1; i++) add1(i, 1);
    for (int i = 1; i <= n * 2; i++) add2(i, 1);
    while (q--) {
        int x, y;
        read(x); read(y);
        add1(x, -1); add1(y, -1);
        if (a[x] > a[y]) swap(x, y);
        vector <int> vec;
        vec.push_back(a[x]);
        if (a[x] != 1) vec.push_back(a[x] - 1);
        if (a[y] != n * 2 + 1) vec.push_back(a[y]);
        if (a[x] != a[y] - 1) vec.push_back(a[y] - 1);
        for (auto i : vec) add2(i, -1);
        swap(pos[a[x]], pos[a[y]]); swap(a[x], a[y]);
        add1(x, 1); add1(y, 1);
        for (auto i : vec) add2(i, 1);
        int tmp = tr1.getpos(1, 1, 2 * n + 1);
        if (tr1.query(1, 1, 2 * n + 1, pos[n + 1]) != tr1.query(1, 1, 2 * n + 1, tmp)) {
            print(tmp % (2 * n + 1), '\n');
            continue;
        }
        if (tr2.query(1, 1, n + 1, 1) > n * 2) {
            print(pos[n + 1] % (2 * n + 1), '\n');
            continue;
        }
        if (tr2.query(1, 1, n + 1, n + 1) > n * 2) {
            print(pos[n + 1] - 1, '\n');
            continue;
        }
        print(-1, '\n');
    }
    return 0;
}
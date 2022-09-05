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

struct seg {
    int l, r, mn;
    seg (int a = 0, int b = 0, int c = 0) : l(a), r(b), mn(c) {}
    bool operator < (const seg A) const { return mn < A.mn; }
} se[N];

set <int> all;
set <int> :: iterator it;
int a[N], b[N], id[N], mx[N][20], mn[N][20], mnb[N][20], lg[N], f[N];
int n, m, x, len; ll ans;

void add(int x, int y) {
    while (x <= 200000) {
        f[x] += y;
        x += (x & -x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
        ans += f[x];
        x &= (x - 1);
    }
    return ans;
}

bool cmp(int i, int j) { return b[i] > b[j]; }

int qmax(int l, int r) {
    int k = lg[r - l + 1];
    if (a[mx[l][k]] > a[mx[r - (1 << k) + 1][k]]) return mx[l][k];
    return mx[r - (1 << k) + 1][k];
}

int qmin(int l, int r) {
    int k = lg[r - l + 1];
    if (a[mn[l][k]] < a[mn[r - (1 << k) + 1][k]]) return mn[l][k];
    return mn[r - (1 << k) + 1][k];
}

int qminb(int l, int r) {
    int k = lg[r - l + 1];
    if (b[mnb[l][k]] < b[mnb[r - (1 << k) + 1][k]]) return mnb[l][k];
    return mnb[r - (1 << k) + 1][k];
}

void solve(int l, int r) {
    if (l > r) return;
    se[++len] = seg(l, r, a[qmin(l, r)]);
    int pos = qmax(l, r);
    solve(l, pos - 1); solve(pos + 1, r);
}

void gao(int l, int r, int opt) {
    if (l > r) return;
    int val = b[qminb(l, r)];
    add(val, opt);
}

int main() {
    read(n); read(m); read(x);
    for (int i = 1; i <= n; i++) read(a[i]), mx[i][0] = mn[i][0] = i;
    for (int i = 1; i <= m; i++) read(b[i]), mnb[i][0] = i, id[i] = i;
    sort(id + 1, id + m + 1, cmp);
    lg[0] = -1;
    for (int i = 1; i <= 200000; i++) lg[i] = lg[i >> 1] + 1;
    for (int j = 1; j <= 19; j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            if (a[mx[i][j - 1]] > a[mx[i + (1 << (j - 1))][j - 1]]) mx[i][j] = mx[i][j - 1];
            else mx[i][j] = mx[i + (1 << (j - 1))][j - 1];
            if (a[mn[i][j - 1]] < a[mn[i + (1 << (j - 1))][j - 1]]) mn[i][j] = mn[i][j - 1];
            else mn[i][j] = mn[i + (1 << (j - 1))][j - 1];
        }
        for (int i = 1; i <= m - (1 << j) + 1; i++) {
            if (b[mnb[i][j - 1]] < b[mnb[i + (1 << (j - 1))][j - 1]]) mnb[i][j] = mnb[i][j - 1];
            else mnb[i][j] = mnb[i + (1 << (j - 1))][j - 1];
        }
    }
    solve(1, n);
    sort(se + 1, se + len + 1);
    all.insert(0); all.insert(m + 1);
    gao(1, m, 1);
    for (int i = 1, j = 1; i <= len; i++) {
        while (j <= m && b[id[j]] + se[i].mn > x) {
            it = all.lower_bound(id[j]);
            int r = *it; --it; int l = *it;
            gao(l + 1, r - 1, -1);
            gao(l + 1, id[j] - 1, 1);
            gao(id[j] + 1, r - 1, 1);
            all.insert(id[j]);
            ++j;
        }
        int lim = N;
        if (se[i].l != 1) lim = min(lim, a[se[i].l - 1]);
        if (se[i].r != n) lim = min(lim, a[se[i].r + 1]);
        int l = max(1, x - lim + 1), r = x - a[qmax(se[i].l, se[i].r)];
        if (l <= r) ans += query(r) - query(l - 1);
    }
    print(ans, '\n');
    return 0;
}
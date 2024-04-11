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

const int N = 50005, INF = 1e9;

vector <int> vec[N];
int lc[N * 300], rc[N * 300], minn[N * 300], rt[N];
int l[N * 2], r[N * 2], ans[N];
int n, m, tot;

void ins(int &u, int l, int r, int x, int y) {
    if (!u) {
        u = ++tot;
        minn[u] = y;
    } else minn[u] = min(minn[u], y);
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (mid >= x) ins(lc[u], l, mid, x, y);
    else ins(rc[u], mid + 1, r, x, y);
}

int query(int u, int l, int r, int x) {
    if (r < x || !u) return INF;
    if (l >= x) return minn[u];
    int mid = (l + r) >> 1;
    int ans = query(rc[u], mid + 1, r, x);
    if (mid >= x) ans = min(ans, query(lc[u], l, mid, x));
    return ans;
}

void add(int l, int r, int t) {
    while (r <= n) {
        ins(rt[r], 1, n, l, t);
        r += (r & -r);
    }
}

int query(int l, int r) {
    int ans = INF;
    while (r) {
        ans = min(ans, query(rt[r], 1, n, l));
        r &= (r - 1);
    }
    return ans;
}

int solve(int l, int r) {
    if (l > r) return 0;
    int id = query(l, r);
    if (id == INF) return 0;
    return ::r[id] - ::l[id] + 1 + solve(l, ::l[id] - 1) + solve(::r[id] + 1, r);
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        read(l[i]); read(r[i]);
        vec[r[i] - l[i] + 1].push_back(i);
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < (int)vec[i].size(); j++) add(l[vec[i][j]], r[vec[i][j]], vec[i][j]);
        ans[i] = solve(1, n);
    }
    for (int i = 1; i <= n; i++) print(ans[i], '\n');
    return 0;
}
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const ll INF = 0x3fffffffffffffff;
const int N = 5e5 + 5;

ll minn[N << 2], tag[N << 2], dep[N], alltag;
int fa[N], w[N], isLeaf[N], siz[N], n, m;

inline void update(int u) { minn[u] = min(minn[u << 1], minn[u << 1 | 1]); }

inline void pushdown(int u) {
    if(tag[u]) {
        tag[u << 1] += tag[u];
        tag[u << 1 | 1] += tag[u];
        minn[u << 1] += tag[u];
        minn[u << 1 | 1] += tag[u];
        tag[u] = 0;
    }
}

void change(int u, int l, int r, int L, int R, ll x) {
    if(l <= L && R <= r) {
        minn[u] += x; tag[u] += x;
        return;
    }
    pushdown(u);
    int mid = (L + R) >> 1;
    if(mid >= l) change(u << 1, l, r, L, mid, x);
    if(mid + 1 <= r) change(u << 1 | 1, l, r, mid + 1, R, x);
    update(u);
}

ll query(int u, int l, int r, int L, int R) {
    if(l <= L && R <= r) return minn[u];
    pushdown(u);
    int mid = (L + R) >> 1;
    ll ans = INF;
    if(mid >= l) ans = min(ans, query(u << 1, l, r, L, mid));
    if(mid + 1 <= r) ans = min(ans, query(u << 1 | 1, l, r, mid + 1, R));
    return ans;
}

struct ele {
    int u, l, r, id;
    bool operator < (const ele A) const { return u < A.u; }
} q[N];

ll ans[N];

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) isLeaf[i] = 1, siz[i] = 1;
    for(register int i = 2; i <= n; i++) {
        read(fa[i]); read(w[i]);
        dep[i] = dep[fa[i]] + w[i];
        isLeaf[fa[i]] = 0;
    }
    for(register int i = n; i >= 2; i--) siz[fa[i]] += siz[i];
    for(register int i = 1; i <= n; i++) {
        if(isLeaf[i]) change(1, i, i, 1, n, dep[i]);
        else change(1, i, i, 1, n, INF);
    }
    for(register int i = 1; i <= m; i++) read(q[i].u), read(q[i].l), read(q[i].r), q[i].id = i;
    sort(q + 1, q + m + 1); int now = 1;
    for(register int i = 1; i <= n; i++) {
        while(now <= m && q[now].u == i) {
            ans[q[now].id] = query(1, q[now].l, q[now].r, 1, n) + alltag;
            ++now;
        }
        if(i == n) continue;
        int x = i;
        while(x != fa[i + 1]) {
            alltag -= w[x];
            change(1, x, x + siz[x] - 1, 1, n, w[x] * 2);
            x = fa[x];
        }
        alltag += w[i + 1];
        change(1, i + 1, i + siz[i + 1], 1, n, -w[i + 1] * 2);
    }
    for(register int i = 1; i <= m; i++) print(ans[i], '\n');
    return 0;
} //
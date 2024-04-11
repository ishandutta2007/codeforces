// time-limit: 2000
// problem-url: https://codeforces.com/contest/1628/problem/E

// No temptation has overtaken you except what is common to mankind. And God 
// is faithful; he will not let you be tempted beyond what you can bear.
// But when you are tempted, he will also provide a way out so that you can 
// endure it.
// 1 Corinthians 10:13
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MAXN 300005

int n, q;
vi adj[MAXN];
vector<iii> eg;
int up[MAXN], sze[MAXN];
ii p[MAXN];

int findp(int i) {
    if (up[i] == i) return i;
    return up[i] = findp(up[i]);
}

int pre[MAXN], pst[MAXN], ptr;
void dfs(int u, int p) {
    pre[u] = ptr++;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    pst[u] = ptr;
}

#define MLR int mid = lo + hi >> 1; int lc = u << 1, rc = u << 1 ^ 1
ii mn[MAXN * 4], mx[MAXN * 4], rmn[MAXN * 4], rmx[MAXN * 4];
int lz[MAXN * 4];
void init(int u = 1, int lo = 1, int hi = n) {
    rmn[u] = MP(INF, -1);
    rmx[u] = MP(-INF, -1);
    lz[u] = -1;
    if (lo == hi) {
        mn[u] = mx[u] = MP(pre[lo], lo);
    } else {
        MLR;
        init(lc, lo, mid);
        init(rc, mid + 1, hi);
        mn[u] = min(mn[lc], mn[rc]);
        mx[u] = max(mx[lc], mx[rc]);
    }
}
void propo(int u, int lo, int hi) {
    if (lo == hi || lz[u] == -1) return;
    MLR;
    lz[lc] = lz[u];
    lz[rc] = lz[u];
    if (lz[u]) {
        rmn[lc] = mn[lc];
        rmx[lc] = mx[lc];
        rmn[rc] = mn[rc];
        rmx[rc] = mx[rc];
    } else {
        rmn[lc] = MP(INF, -1);
        rmx[lc] = MP(-INF, -1);
        rmn[rc] = MP(INF, -1);
        rmx[rc] = MP(-INF, -1);
    }
    lz[u] = -1;
}
void upd(int s, int e, int x, int u = 1, int lo = 1, int hi = n) {
    if (lo >= s && hi <= e) {
        lz[u] = x;
        if (x) {
            rmn[u] = mn[u];
            rmx[u] = mx[u];
        } else {
            rmn[u] = MP(INF, -1);
            rmx[u] = MP(-INF, -1);
        }
        return;
    }
    propo(u, lo, hi);
    MLR;
    if (s <= mid) {
        upd(s, e, x, lc, lo, mid);
    }
    if (e > mid) {
        upd(s, e, x, rc, mid + 1, hi);
    }
    rmn[u] = min(rmn[lc], rmn[rc]);
    rmx[u] = max(rmx[lc], rmx[rc]);
}

int main() {
    scanf("%d%d", &n, &q);
    REP (i, 0, n + 1) {
        up[i] = i;
        sze[i] = 1;
        p[i] = MP(-1, -1);
    }
    REP (i, 1, n) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        eg.pb(MT(w, u, v));
    }
    sort(ALL(eg));
    for (auto [w, u, v] : eg) {
        u = findp(u), v = findp(v);
        if (sze[u] < sze[v]) swap(u, v);
        up[v] = u;
        sze[v] += sze[u];
        adj[u].pb(v);
        p[v] = MP(u, w);
    }
    dfs(findp(1), -1);
    init();
    while (q--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int l, r; scanf("%d%d", &l, &r);
            upd(l, r, 1);
        } else if (t == 2) {
            int l, r; scanf("%d%d", &l, &r);
            upd(l, r, 0);
        } else {
            int x; scanf("%d", &x);
            int l = rmn[1].SE, r = rmx[1].SE;
            if (l == -1 || r == -1) {
                printf("-1\n");
                continue;
            }
            if (pre[l] > pre[x]) {
                l = x;
            }
            if (pre[r] < pre[x]) {
                r = x;
            }
            if (l == r) {
                printf("-1\n");
                continue;
            }
            int u = r;
            while (p[u].FI != -1 && !(pre[p[u].FI] <= pre[l] &&
                        pre[l] < pst[p[u].FI])) {
                u = p[u].FI;
            }
            assert(p[u].FI != -1);
            printf("%d\n", p[u].SE);
        }
    }
    return 0;
}
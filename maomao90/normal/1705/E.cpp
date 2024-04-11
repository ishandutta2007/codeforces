// time-limit: 2000
// problem-url: https://codeforces.com/contest/1705/problem/E

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int) _a.size()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 200035;

int n, q;
int a[MAXN];

int st[MAXN * 4];
bool lz[MAXN * 4], has[MAXN * 4];
#define MLR int mid = lo + hi >> 1, lc = u << 1, rc = u << 1 ^ 1;
void propo(int u, int lo, int hi) {
    if (lo == hi || !has[u]) return;
    MLR;
    st[lc] = lz[u] ? (mid - lo + 1) : 0;
    st[rc] = lz[u] ? (hi - mid) : 0;
    lz[lc] = lz[u];
    lz[rc] = lz[u];
    has[lc] = has[rc] = 1;
    has[u] = 0;
}
void upd(int s, int e, bool x, int u = 1, int lo = 1, int hi = MAXN) {
    if (lo >= s && hi <= e) {
        st[u] = x ? (hi - lo + 1) : 0;
        lz[u] = x;
        has[u] = 1;
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
    st[u] = st[lc] + st[rc];
}
int getlbz(int x, int u = 1, int lo = 1, int hi = MAXN) {
    if (lo == hi) {
        return lo;
    }
    propo(u, lo, hi);
    MLR;
    int res = -1;
    if (mid >= x && st[lc] != mid - lo + 1) {
        res = getlbz(x, lc, lo, mid);
    }
    if (res == -1 && st[rc] != hi - mid) {
        res = getlbz(x, rc, mid + 1, hi);
    }
    return res;
}
int getlbo(int x, int u = 1, int lo = 1, int hi = MAXN) {
    if (lo == hi) {
        return lo;
    }
    propo(u, lo, hi);
    MLR;
    int res = -1;
    if (mid >= x && st[lc] != 0) {
        res = getlbo(x, lc, lo, mid);
    }
    if (res == -1 && st[rc] != 0) {
        res = getlbo(x, rc, mid + 1, hi);
    }
    return res;
}
int getans(int u = 1, int lo = 1, int hi = MAXN) {
    if (lo == hi) {
        return lo;
    }
    propo(u, lo, hi);
    MLR;
    int res = -1;
    if (st[rc] > 0) {
        return getans(rc, mid + 1, hi);
    } else if (st[lc] > 0) {
        return getans(lc, lo, mid);
    } else {
        return -1;
    }
}

inline void add(int x) {
    int e = getlbz(x);
    assert(e != -1);
    upd(e, e, 1);
    if (x <= e - 1) {
        upd(x, e - 1, 0);
    }
}
inline void rmv(int x) {
    int e = getlbo(x);
    assert(e != -1);
    upd(e, e, 0);
    if (x <= e - 1) {
        upd(x, e - 1, 1);
    }
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> q;
    REP (i, 1, n + 1) {
        cin >> a[i];
        add(a[i]);
    }
    while (q--) {
        int k, l; cin >> k >> l;
        rmv(a[k]);
        a[k] = l;
        add(a[k]);
        cout << getans() << ' ';
    }
    return 0;
}
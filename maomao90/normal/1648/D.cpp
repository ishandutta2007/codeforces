// time-limit: 5000
// problem-url: https://codeforces.com/contest/1648/problem/D

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 500005

int n, q;
ll a[MAXN], b[MAXN], c[MAXN];
vii ranges[MAXN];
ll ans;

#define MLR int mid = lo + hi >> 1; int lc = u << 1, rc = u << 1 ^ 1
ll mxa[MAXN * 4], mxb[MAXN * 4], mx[MAXN * 4], lz[MAXN * 4];
inline void propo(int u, int lo, int hi) {
    if (lz[u] == -LINF || lo == hi) return;
    MLR;
    mxto(lz[lc], lz[u]);
    mxto(lz[rc], lz[u]);
    mxto(mxb[lc], lz[u]);
    mxto(mxb[rc], lz[u]);
    mxto(mx[lc], mxb[lc] + mxa[lc]);
    mxto(mx[rc], mxb[rc] + mxa[rc]);
    lz[u] = -LINF;
}
void upd(int i, ll x, int u = 1, int lo = 1, int hi = n) {
    if (lo == hi) {
        mxa[u] = x;
        return;
    }
    MLR;
    if (i <= mid) {
        upd(i, x, lc, lo, mid);
    } else {
        upd(i, x, rc, mid + 1, hi);
    }
    mxa[u] = max(mxa[lc], mxa[rc]);
}
ll qmx(int s, int e, int u = 1, int lo = 1, int hi = n) {
    if (lo >= s && hi <= e) {
        return mxa[u];
    }
    ll res = -LINF;
    MLR;
    if (s <= mid) {
        mxto(res, qmx(s, e, lc, lo, mid));
    }
    if (e > mid) {
        mxto(res, qmx(s, e, rc, mid + 1, hi));
    }
    return res;
}
void upd2(int s, int e, ll x, int u = 1, int lo = 1, int hi = n) {
    if (lo >= s && hi <= e) {
        mxto(mxb[u], x);
        mxto(lz[u], x);
        mxto(mx[u], mxb[u] + mxa[u]);
        return;
    }
    MLR;
    propo(u, lo, hi);
    if (s <= mid) {
        upd2(s, e, x, lc, lo, mid);
    }
    if (e > mid) {
        upd2(s, e, x, rc, mid + 1, hi);
    }
    mx[u] = max(mx[lc], mx[rc]);
}
ll qmx2(int s, int e, int u = 1, int lo = 1, int hi = n) {
    if (lo >= s && hi <= e) {
        return mx[u];
    }
    ll res = -LINF;
    propo(u, lo, hi);
    MLR;
    if (s <= mid) {
        mxto(res, qmx2(s, e, lc, lo, mid));
    }
    if (e > mid) {
        mxto(res, qmx2(s, e, rc, mid + 1, hi));
    }
    return res;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> q;
    REP (i, 1, n + 1) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    REP (i, 1, n + 1) {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    REP (i, 1, n + 1) {
        cin >> c[i];
        c[i] += c[i - 1];
    }
    ans = -LINF;
    REP (i, 0, MAXN * 4) {
        lz[i] = -LINF;
        mxb[i] = -LINF;
        mx[i] = -LINF;
        mxa[i] = -LINF;
    }
    // a[i] means move down from row 1 at position i
    REP (i, 1, n + 1) {
        a[i] -= b[i - 1];
    }
    // b[i] means move down from row 2 at position i
    REP (i, 1, n + 1) {
        b[i] -= c[i - 1];
    }
    // assume take a[i] + b[j]. Then i <= j
    REP (i, 0, q) {
        int l, r, k; cin >> l >> r >> k;
        ranges[r].pb(MP(l, k));
    }
    REP (i, 1, n + 1) {
        upd(i, a[i]);
    }
    REP (r, 1, n) {
        if (ranges[r].empty()) continue;
        for (auto [l, k] : ranges[r]) {
            mxto(a[r + 1], qmx(l, r + 1) - k);
        }
        upd(r + 1, a[r + 1]);
    }
    REP (r, 1, n + 1) {
        upd2(1, r, b[r]);
        for (auto [l, k] : ranges[r]) {
            mxto(ans, qmx2(l, r) - k);
        }
    }
    ans += c[n];
    cout << ans << '\n';
    return 0;
}
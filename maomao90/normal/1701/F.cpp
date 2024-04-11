// time-limit: 6500
// problem-url: https://codeforces.com/contest/1701/problem/F

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
const int MAXN = 200005;

int q, d;
set<int> st;
ll ans;

#define MLR int mid = lo + hi >> 1, lc = u << 1, rc = u << 1 ^ 1
ll sm[MAXN * 4], lzsm[MAXN * 4];
int occ[MAXN * 4];
void propo(int u, int lo, int hi) {
    if (lzsm[u] == 0 || lo == hi) return;
    MLR;
    sm[lc] += lzsm[u] * occ[lc];
    sm[rc] += lzsm[u] * occ[rc];
    lzsm[lc] += lzsm[u];
    lzsm[rc] += lzsm[u];
    lzsm[u] = 0;
}
void incre(int s, int e, ll xsm, int xocc, int u = 1, int lo = 0, int hi = MAXN) {
    if (s > e) {
        return;
    }
    if (lo >= s && hi <= e) {
        if (xocc != 0) {
            occ[u] += xocc;
            sm[u] += xsm;
        } else {
            sm[u] += xsm * occ[u];
            lzsm[u] += xsm;
        }
        return;
    }
    propo(u, lo, hi);
    MLR;
    if (s <= mid) {
        incre(s, e, xsm, xocc, lc, lo, mid);
    }
    if (e > mid) {
        incre(s, e, xsm, xocc, rc, mid + 1, hi);
    }
    sm[u] = sm[lc] + sm[rc];
    occ[u] = occ[lc] + occ[rc];
}
ll qsm(int s, int e, int u = 1, int lo = 0, int hi = MAXN) {
    if (s > e) {
        return 0;
    }
    if (lo >= s && hi <= e) {
        return sm[u];
    }
    propo(u, lo, hi);
    MLR;
    ll res = 0;
    if (s <= mid) {
        res += qsm(s, e, lc, lo, mid);
    }
    if (e > mid) {
        res += qsm(s, e, rc, mid + 1, hi);
    }
    return res;
}
ll qocc(int s, int e, int u = 1, int lo = 0, int hi = MAXN) {
    if (s > e) {
        return 0;
    }
    if (lo >= s && hi <= e) {
        return occ[u];
    }
    propo(u, lo, hi);
    MLR;
    ll res = 0;
    if (s <= mid) {
        res += qocc(s, e, lc, lo, mid);
    }
    if (e > mid) {
        res += qocc(s, e, rc, mid + 1, hi);
    }
    return res;
}

ll contri(int p) {
    ll res = 0, occ;
    // handle j = p
    int lft = p - d;
    res += qsm(lft, p - 1);
    occ = qocc(lft, p - 1);
    res -= occ * (occ + 1) / 2;
    // handle k = p
    res += occ * (occ + 1) / 2;
    // handle i = p
    int rht = p + d;
    occ = qocc(p + 1, rht);
    res += occ * (occ - 1) / 2;
    cerr << ' ' << p << ": " << res << '\n';
    return res;
}

void add(int p) {
    int rht = p + d;
    int occ = qocc(p + 1, rht);
    incre(p, p, occ, 1);
    cerr << "+ " << p << ": " << occ << '\n';
    int lft = p - d;
    incre(lft, p - 1, 1, 0);
    cerr << "+ " << lft << ' ' << p - 1 << ": " << 1 << '\n';
    cerr << p << '\n';
    REP (i, 1, 9) {
        cerr << qsm(i, i) << ' ';
    }
    cerr << '\n';
    REP (i, 1, 9) {
        cerr << qocc(i, i) << ' ';
    }
    cerr << '\n';
}

void remove(int p) {
    int rht = p + d;
    int occ = qocc(p + 1, rht);
    incre(p, p, -occ, -1);
    int lft = p - d;
    incre(lft, p - 1, -1, 0);
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> q >> d;
    while (q--) {
        int a; cin >> a;
        cerr << a << '\n';
        if (st.find(a) == st.end()) {
            st.insert(a);
            ans += contri(a);
            add(a);
        } else {
            st.erase(st.find(a));
            remove(a);
            ans -= contri(a);
        }
        cout << ans << '\n';
    }
    return 0;
}
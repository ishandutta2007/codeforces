// time-limit: 3000
// problem-url: https://codeforces.com/contest/1401/problem/F

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
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
const int MAXN = 300005;
const int MAXK = 20;

int n, q;

#define MLR int mid = lo + hi >> 1, lc = u << 1, rc = u << 1 ^ 1
bool rev[MAXK], swp[MAXK];
ll st[MAXN * 4];
void upd(int p, int x, int l = n, int u = 1, int lo = 1, int hi = 1 << n) {
    if (rev[l]) {
        p = hi - (p - lo);
    }
    if (lo == hi) {
        st[u] = x;
        return;
    }
    MLR;
    if (p <= mid) {
        upd(p, x, l - 1, lc ^ swp[l], lo, mid);
    } else {
        upd(p, x, l - 1, rc ^ swp[l], mid + 1, hi);
    }
    st[u] = st[lc] + st[rc];
}
ll qsm(int s, int e, int l = n, int u = 1, int lo = 1, int hi = 1 << n) {
    if (rev[l]) {
        s = hi - (s - lo);
        e = hi - (e - lo);
        swap(s, e);
    }
    cerr << lo << ' ' << hi << ' ' << s << ' ' << e << '\n';
    if (lo == 1 && hi == 1) {
        //return 0;
    }
    if (lo >= s && hi <= e) {
        return st[u];
    }
    MLR;
    ll sm = 0;
    cerr << swp[l] << '\n';
    if (s <= mid) {
        sm += qsm(max(s, lo), min(e, mid), l - 1, lc ^ swp[l], lo, mid);
    }
    if (e > mid) {
        sm += qsm(max(s, mid + 1), min(e, hi), l - 1, rc ^ swp[l], mid + 1, hi);
    }
    return sm;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> q;
    REP (i, 1, (1 << n) + 1) {
        int a; cin >> a;
        upd(i, a);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, k; cin >> x >> k;
            upd(x, k);
        } else if (t == 2) {
            int k; cin >> k;
            rev[k] ^= 1;
        } else if (t == 3) {
            int k; cin >> k;
            swp[k + 1] ^= 1;
        } else {
            int l, r; cin >> l >> r;
            cout << qsm(l, r) << '\n';
        }
    }
    return 0;
}
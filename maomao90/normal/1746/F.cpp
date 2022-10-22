// time-limit: 3000
// problem-url: https://codeforces.com/contest/1746/problem/F

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

const int INF = 7000;
const ll LINF = 1000000000000000005ll;
const int MAXN = 300005;
const int MAXL = 30;

mt19937 rnd(1245713);

int n, q;
int a[MAXN];
int hsh[MAXL][MAXN * 2];
int t[MAXN], p[MAXN], x[MAXN], l[MAXN], r[MAXN], k[MAXN];

int fw[MAXL][MAXN];
void incre(int i, int x, int l) {
    for (; i <= n; i += i & -i) {
        fw[l][i] += x;
    }
}
int qsm(int i, int l) {
    ll res = 0;
    for (; i > 0; i -= i & -i) {
        res += fw[l][i];
    }
    return res;
}
int qsm(int s, int e, int l) {
    return qsm(e, l) - qsm(s - 1, l);
}

void rmv(int i, int x) {
    REP (l, 0, MAXL) {
        while (hsh[l][x] == 0) {
            hsh[l][x] = rnd() % INF;
            if (hsh[l][x] < 0) {
                hsh[l][x] += INF;
            }
        }
        incre(i, -hsh[l][x], l);
    }
}
void add(int i, int x) {
    REP (l, 0, MAXL) {
        while (hsh[l][x] == 0) {
            hsh[l][x] = rnd() % INF;
            if (hsh[l][x] < 0) {
                hsh[l][x] += INF;
            }
        }
        incre(i, hsh[l][x], l);
    }
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> q;
    vii disc;
    REP (i, 1, n + 1) {
        cin >> a[i];
        disc.pb({a[i], i});
    }
    REP (i, 1, q + 1) {
        cin >> t[i];
        if (t[i] == 1) {
            cin >> p[i] >> x[i];
            disc.pb({x[i], i + n});
        } else {
            cin >> l[i] >> r[i] >> k[i];
        }
    }
    sort(ALL(disc));
    int prv = -1, cnt = -1;
    for (auto [v, id] : disc) {
        if (prv != v) {
            prv = v;
            cnt++;
        }
        if (id <= n) {
            a[id] = cnt;
        } else {
            x[id - n] = cnt;
        }
    }
    REP (i, 1, n + 1) {
        add(i, a[i]);
    }
    REP (i, 1, q + 1) {
        if (t[i] == 1) {
            rmv(p[i], a[p[i]]);
            a[p[i]] = x[i];
            add(p[i], a[p[i]]);
        } else {
            bool pos = 1;
            REP (z, 0, MAXL) {
                ll sm = qsm(l[i], r[i], z);
                if (sm % k[i] != 0) {
                    pos = 0;
                    break;
                }
            }
            if (pos) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
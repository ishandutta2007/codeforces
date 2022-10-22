// time-limit: 3000
// problem-url: https://codeforces.com/contest/707/problem/E

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
const int MAXN = 2005;

int n, m, k;
vector<iii> gar[MAXN];
int q;
bool on[MAXN];
vector<tuple<int, int, int, int, int>> ev[MAXN];
ll ans[MAXN];

ll fw[MAXN][MAXN];
void incre(int i, int j, int c) {
    int oj = j;
    for (; i <= n; i += i & -i) {
        for (j = oj; j <= m; j += j & -j) {
            fw[i][j] += c;
        }
    }
}
ll qsm(int i, int j) {
    ll res = 0;
    int oj = j;
    for (; i > 0; i -= i & -i) {
        for (j = oj; j > 0; j -= j & -j) {
            res += fw[i][j];
        }
    }
    return res;
}
ll qsm(int x1, int y1, int x2, int y2) {
    return qsm(x2, y2) - qsm(x1 - 1, y2) - qsm(x2, y1 - 1) + qsm(x1 - 1, y1 - 1);
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> m >> k;
    REP (i, 0, k) {
        int l; cin >> l;
        gar[i].resize(l);
        REP (j, 0, l) {
            int a, b, c; cin >> a >> b >> c;
            gar[i][j] = {a, b, c};
        }
    }
    cin >> q;
    REP (i, 0, k) {
        on[i] = 1;
    }
    int ptr = 0;
    REP (i, 0, q) {
        string s; cin >> s;
        if (s == "SWITCH") {
            int id; cin >> id;
            id--;
            on[id] ^= 1;
        } else {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            vi vec;
            REP (j, 0, k) {
                if (on[j]) {
                    ev[j].pb({ptr, x1, y1, x2, y2});
                }
            }
            ptr++;
        }
    }
    REP (i, 0, k) {
        REP (j, 0, SZ(gar[i])) {
            auto [a, b, c] = gar[i][j];
            cerr << "+ " << a << ' ' << b << ' ' << c << '\n';
            incre(a, b, c);
        }
        cerr << i << '\n';
        for (auto [id, x1, y1, x2, y2] : ev[i]) {
            ll tmp = qsm(x1, y1, x2, y2);
            cerr << ' ' << id << ' ' << tmp << '\n';
            ans[id] += tmp;
        }
        REP (j, 0, SZ(gar[i])) {
            auto [a, b, c] = gar[i][j];
            incre(a, b, -c);
        }
    }
    REP (i, 0, ptr) {
        cout << ans[i] << '\n';
    }
    return 0;
}
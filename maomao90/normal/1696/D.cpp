// time-limit: 2000
// problem-url: https://codeforces.com/contest/1696/problem/D

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
const int MAXN = 250005;
const int MAXL = 20;

int t;
int n;
int a[MAXN];
int p[MAXL][MAXN];
ii mn[MAXL][MAXN], mx[MAXL][MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 0, n) {
            cin >> a[i];
        }
        RREP (i, n - 1, 0) {
            if (i == n - 1) {
                p[0][i] = -1;
                mn[0][i] = {INF, -1};
                mx[0][i] = {-INF, -1};
            } else {
                p[0][i] = i + 1;
                mn[0][i] = mx[0][i] = {a[i], i};
                mnto(mn[0][i], {a[i + 1], i + 1});
                mxto(mx[0][i], {a[i + 1], i + 1});
            }
            REP (k, 1, MAXL) {
                if (p[k - 1][i] == -1) {
                    p[k][i] = -1;
                    mn[k][i] = {INF, -1};
                    mx[k][i] = {-INF, -1};
                } else {
                    p[k][i] = p[k - 1][p[k - 1][i]];
                    mn[k][i] = min(mn[k - 1][i], mn[k - 1][p[k - 1][i]]);
                    mx[k][i] = max(mx[k - 1][i], mx[k - 1][p[k - 1][i]]);
                }
            }
        }
        int u = 0;
        int ans = 0;
        while (u != n - 1) {
            ans++;
            int v = u;
            int nu = u;
            cerr << u << '\n';
            if (a[u + 1] > a[u]) { // up
                RREP (k, MAXL - 1, 0) {
                    if (p[k][v] == -1) {
                        continue;
                    }
                    if (mn[k][v].FI >= a[u]) {
                        //assert(mn[k][v].FI == a[u]);
                        v = p[k][v];
                    }
                }
                cerr << ' ' << v << '\n';
                ii res = {-INF, -1};
                RREP (k, MAXL - 1, 0) {
                    if (p[k][nu] == -1) {
                        continue;
                    }
                    if (p[k][nu] <= v) {
                        mxto(res, mx[k][nu]);
                        nu = p[k][nu];
                    }
                }
                nu = res.SE;
            } else {
                RREP (k, MAXL - 1, 0) {
                    if (p[k][v] == -1) {
                        continue;
                    }
                    if (mx[k][v].FI <= a[u]) {
                        //assert(mx[k][v].FI == a[u]);
                        v = p[k][v];
                    }
                }
                cerr << ' ' << v << '\n';
                ii res = {INF, -1};
                RREP (k, MAXL - 1, 0) {
                    if (p[k][nu] == -1) {
                        continue;
                    }
                    if (p[k][nu] <= v) {
                        mnto(res, mn[k][nu]);
                        nu = p[k][nu];
                    }
                }
                nu = res.SE;
            }
            u = nu;
        }
        cout << ans << '\n';
    }
    return 0;
}
// time-limit: 1000
// problem-url: https://codeforces.com/contest/1687/problem/C

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
const int MAXN = 400015;

int t;
int n, m;
int a[MAXN], b[MAXN];
ll pa[MAXN], pb[MAXN];
int l[MAXN], r[MAXN];
bool in[MAXN];
int pfill[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n >> m;
        REP (i, 1, n + 1) {
            cin >> a[i];
        }
        REP (i, 1, n + 1) {
            cin >> b[i];
        }
        REP (i, 0, m) {
            cin >> l[i] >> r[i];
        }
        REP (i, 0, n + 1) {
            pa[i] = pb[i] = 0;
        }
        REP (i, 1, n + 1) {
            pa[i] = pa[i - 1] + a[i];
        }
        REP (i, 1, n + 1) {
            pb[i] = pb[i - 1] + b[i];
        }
        if (pa[n] != pb[n]) {
            cout << "NO\n";
            continue;
        }
        vi stk;
        set<ii> lst, rst;
        auto check = [&] (int i) {
            return pa[l[i]] == pb[l[i]] && pa[r[i]] == pb[r[i]] && l[i] < r[i];
        };
        REP (i, 0, n + 5) {
            pfill[i] = 0;
        }
        REP (i, 0, m + n + 5) {
            in[i] = 0;
        }
        REP (i, 0, m + n) {
            if (i >= m) {
                l[i] = r[i] = i - m + 1;
            }
            l[i]--;
            rst.insert({r[i], i});
            lst.insert({l[i], i});
            if (check(i)) {
                stk.pb(i);
                in[i] = 1;
            }
        }
        while (!stk.empty()) {
            int u = stk.back(); stk.pop_back();
            cerr << u << ' ' << l[u] << ' ' << r[u] << '\n';
            pfill[l[u] + 1]++; pfill[r[u] + 1]--;
            {
                auto ptr = rst.upper_bound({l[u], -1});
                while (ptr != rst.end() && ptr -> FI <= r[u]) {
                    int v = ptr -> SE;
                    cerr << ' ' << v << ' ' << l[v] << ' ' << r[v] << '\n';
                    if (!in[v]) {
                        r[v] = l[u];
                        if (check(v)) {
                            stk.pb(v);
                            in[v] = 1;
                        }
                    }
                    ptr = rst.erase(ptr);
                }
            }
            {
                auto ptr = lst.upper_bound({l[u], -1});
                while (ptr != lst.end() && ptr -> FI <= r[u]) {
                    int v = ptr -> SE;
                    cerr << ' ' << v << ' ' << l[v] << ' ' << r[v] << '\n';
                    if (!in[v]) {
                        l[v] = r[u];
                        if (check(v)) {
                            stk.pb(v);
                            in[v] = 1;
                        }
                    }
                    ptr = lst.erase(ptr);
                }
            }
        }
        bool pos = 1;
        REP (i, 1, n + 1) {
            pfill[i] += pfill[i - 1];
            if (pfill[i] == 0) {
                pos = 0;
                break;
            }
        }
        if (pos) {
            assert(pa[n] == pb[n]);
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
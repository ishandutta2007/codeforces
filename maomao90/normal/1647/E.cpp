// time-limit: 2000
// problem-url: https://codeforces.com/contest/1647/problem/E

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
#define MAXN 100005
#define MAXL 30

int n;
int p[MAXL][MAXN];
int a[MAXN];
vi adj[MAXN];
int steps;
vi comp[MAXN];
bool used[MAXN];
int lo[MAXN];
int ans[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    REP (i, 1, n + 1) {
        cin >> p[0][i];
        adj[p[0][i]].pb(i);
    }
    REP (k, 1, MAXL) {
        REP (i, 1, n + 1) {
            p[k][i] = p[k - 1][p[k - 1][i]];
        }
    }
    int leaves = 0;
    REP (i, 1, n + 1) {
        if (adj[i].empty()) {
            leaves++;
        }
    }
    int mxa = 0;
    REP (i, 1, n + 1) {
        cin >> a[i];
        mxto(mxa, a[i]);
    }
    mxa -= n;
    assert(mxa % leaves == 0);
    steps = mxa / leaves;
    cerr << steps << '\n';
    REP (i, 1, n + 1) {
        int u = i;
        REP (k, 0, MAXL) {
            if (steps >> k & 1) {
                u = p[k][u];
            }
        }
        comp[u].pb(i);
    }
    REP (i, 1, n + 1) {
        if (a[i] > n) {
            continue;
        }
        sort(ALL(comp[i]));
        assert(!comp[i].empty());
        ans[comp[i][0]] = a[i];
        used[a[i]] = 1;
        REP (j, 1, comp[i].size()) {
            lo[comp[i][j]] = a[i];
        }
    }
    set<int> rem;
    REP (i, 1, n + 1) {
        if (!used[i]) {
            rem.insert(i);
        }
    }
    REP (i, 1, n + 1) {
        cerr << ans[i] << ' ';
    }
    cerr << '\n';
    REP (i, 1, n + 1) {
        if (ans[i] != 0) continue;
        auto itr = rem.lower_bound(lo[i]);
        assert(itr != rem.end());
        ans[i] = *itr;
        rem.erase(itr);
    }
    assert(rem.empty());
    REP (i, 1, n + 1) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
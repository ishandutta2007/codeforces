// time-limit: 1500
// problem-url: https://codeforces.com/contest/1585/problem/G

// For the wages of sin is death, but the gift of
// God is eternal life in Christ Jesus our Lord
// Romans 6:23
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
#define MOD 1000000007
#define MAXN 500005

int t;
int n;
int p[MAXN];
vi adj[MAXN];

vi glob;
int used[MAXN];
int dfs(int u) {
    vi res;
    if (adj[u].empty()) {
        used[0] = 1;
        res.pb(0);
        used[1] = 1;
        res.pb(1);
        swap(glob, res);
        debug("%d: %d\n", u, 1);
        return 1;
    }
    if (adj[u].size() == 1) {
        int v = adj[u][0];
        int mex = dfs(v);
        for (; used[mex]; mex++) {}
        used[mex] = 1;
        glob.pb(mex);
        debug("%d: %d\n", u, mex);
        return mex;
    }
    for (int v : adj[u]) {
        glob.clear();
        dfs(v);
        for (int i : glob) {
            used[i] = 0;
        }
        if (res.empty()) {
            swap(glob, res);
        } else {
            if (glob.size() < res.size()) {
                swap(glob, res);
            }
            REP (i, 0, res.size()) {
                res[res.size() - i - 1] ^= glob[glob.size() - i - 1];
            }
        }
    }
    for (int i : res) {
        used[i] = 1;
    }
    int mex = 0;
    for (; used[mex]; mex++) {}
    used[mex] = 1;
    res.pb(mex);
    swap(glob, res);
    debug("%d: %d\n", u, mex);
    return mex;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        REP (i, 1, n + 1) {
            p[i] = 0;
            adj[i].clear();
        }
        REP (i, 1, n + 1) {
            scanf("%d", &p[i]);
            adj[p[i]].pb(i);
        }
        int ans = 0;
        REP (i, 1, n + 1) {
            if (p[i] == 0) {
                ans ^= dfs(i);
            }
            for (int j : glob) {
                used[j] = 0;
            }
            glob.clear();
        }
        if (ans != 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
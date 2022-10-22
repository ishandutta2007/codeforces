// time-limit: 5000
// problem-url: https://codeforces.com/problemset/problem/757/G

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
const int MAXL = 20;

int n, q;
int a[MAXN], mp[MAXN];
vii adj[MAXN];

int cp[MAXN], l[MAXN], sub[MAXN];
ll dist[MAXL][MAXN];
int getSub(int u, int p, int cl) {
    sub[u] = 1;
    for (auto [v, w] : adj[u]) {
        if (l[v] != -1 || v == p) continue;
        if (cl) {
            dist[cl - 1][v] = dist[cl - 1][u] + w;
        }
        sub[u] += getSub(v, u, cl);
    }
    return sub[u];
}
int getCent(int u, int p, int s) {
    for (auto [v, w] : adj[u]) {
        if (l[v] != -1 || v == p) continue;
        if (sub[v] > s / 2) {
            return getCent(v, u, s);
        }
    }
    return u;
}
vector<pll> subv[MAXN], usubv[MAXN];
void dfs(int u, int p, int cl, int cent) {
    subv[cent].pb({mp[u], dist[cl][u]});
    if (cl) {
        usubv[cent].pb({mp[u], dist[cl - 1][u]});
    }
    for (auto [v, w] : adj[u]) {
        if (l[v] < cl || v == p) continue;
        dfs(v, u, cl, cent);
    }
}
void build(int u, int p, int cl) {
    int cent = getCent(u, p, getSub(u, p, cl));
    cp[cent] = p;
    l[cent] = cl;
    for (auto [v, w] : adj[cent]) {
        if (l[v] != -1) continue;
        dist[cl][v] = w;
        build(v, cent, cl + 1);
    }
    dfs(cent, -1, cl, cent);
    sort(ALL(subv[cent]));
    sort(ALL(usubv[cent]));
    REP (i, 1, SZ(subv[cent])) {
        subv[cent][i].SE += subv[cent][i - 1].SE;
    }
    REP (i, 1, SZ(usubv[cent])) {
        usubv[cent][i].SE += usubv[cent][i - 1].SE;
    }
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> q;
    REP (i, 1, n + 1) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    REP (i, 1, n) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    memset(l, -1, sizeof l);
    build(1, -1, 0);
    int pans = 0;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, e, v; cin >> s >> e >> v;
            s ^= pans; e ^= pans; v ^= pans;
            ll ans = 0;
            int lb = lower_bound(ALL(subv[v]), pll{s, -1}) - subv[v].begin(),
                ub = upper_bound(ALL(subv[v]), pll{e, LINF}) - subv[v].begin() - 1;
            if (lb <= ub) {
                ans += subv[v][ub].SE - (lb == 0 ? 0 : subv[v][lb - 1].SE);
            }
            int ov = v;
            RREP (k, l[ov] - 1, 0) {
                int u = cp[v];
                {
                    int lb = lower_bound(ALL(subv[u]), pll{s, -1}) - 
                        subv[u].begin();
                    int ub = upper_bound(ALL(subv[u]), pll{e, LINF}) - 
                        subv[u].begin() - 1;
                    if (lb <= ub) {
                        ans += subv[u][ub].SE -
                            (lb == 0 ? 0 : subv[u][lb - 1].SE);
                        ans += dist[k][ov] * (ub - lb + 1);
                    }
                }
                {
                    int lb = lower_bound(ALL(usubv[v]), pll{s, -1}) -
                        usubv[v].begin();
                    int ub = upper_bound(ALL(usubv[v]), pll{e, LINF}) -
                        usubv[v].begin() - 1;
                    if (lb <= ub) {
                        ans -= usubv[v][ub].SE -
                            (lb == 0 ? 0 : usubv[v][lb - 1].SE);
                        ans -= dist[k][ov] * (ub - lb + 1);
                    }
                }
                v = u;
            }
            cout << ans << '\n';
            pans = ans % (1 << 30);
        } else {
            int x; cin >> x;
            x ^= pans;
            int stop = 0;
            {
                int v = a[x];
                int ov = v;
                RREP (k, l[ov], 0) {
                    int u = cp[v];
                    int lb = lower_bound(ALL(subv[v]), pll{x, -1}) - subv[v].begin();
                    cerr << v << ' ' << lb << '\n';
                    if (lb + 1 < SZ(subv[v]) && subv[v][lb + 1].FI == x + 1) {
                        subv[v][lb].SE -= dist[k][ov];
                        subv[v][lb].SE += dist[k][a[x + 1]];
                        mxto(stop, k + 1);
                        cerr << ' ' << lb << ": " << subv[v][lb].SE << '\n';
                    } else {
                        subv[v][lb].FI++;
                        cerr << " ++\n";
                    }
                    v = u;
                }
            }
            {
                int v = a[x + 1];
                int ov = v;
                RREP (k, l[ov], stop) {
                    int u = cp[v];
                    int lb = lower_bound(ALL(subv[v]), pll{x + 1, -1}) - subv[v].begin();
                    cerr << v << ' ' << lb << '\n';
                    cerr << " --\n";
                    subv[v][lb].FI--;
                    v = u;
                }
            }
            stop = 0;
            {
                int v = a[x];
                int ov = v;
                RREP (k, l[ov] - 1, 0) {
                    int u = cp[v];
                    int lb = lower_bound(ALL(usubv[v]), pll{x, -1}) - usubv[v].begin();
                    cerr << v << ' ' << lb << '\n';
                    if (lb + 1 < SZ(usubv[v]) && usubv[v][lb + 1].FI == x + 1) {
                        usubv[v][lb].SE -= dist[k][ov];
                        usubv[v][lb].SE += dist[k][a[x + 1]];
                        mxto(stop, k + 1);
                        cerr << ' ' << lb << ": " << usubv[v][lb].SE << '\n';
                    } else {
                        usubv[v][lb].FI++;
                        cerr << " ++\n";
                    }
                    v = u;
                }
            }
            {
                int v = a[x + 1];
                int ov = v;
                RREP (k, l[ov] - 1, stop) {
                    int u = cp[v];
                    int lb = lower_bound(ALL(usubv[v]), pll{x + 1, -1}) - usubv[v].begin();
                    cerr << v << ' ' << lb << '\n';
                    cerr << " --\n";
                    usubv[v][lb].FI--;
                    v = u;
                }
            }
            swap(a[x], a[x + 1]);
            swap(mp[a[x]], mp[a[x + 1]]);
        }
    }
    return 0;
}

/*
   8 1
   1 2 3 4 5 6 7 8
   1 2 1
   2 3 1
   3 4 1
   4 5 1
   5 6 1
   6 7 1
   7 8 1
   1 1 8 8
   */
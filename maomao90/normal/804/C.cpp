// time-limit: 2000
// problem-url: https://codeforces.com/contest/804/problem/C

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

int n, m;
int s[MAXN];
vi ic[MAXN];
int ans[MAXN];
vi adj[MAXN];
int sze;

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        set<int> st;
        for (int i : ic[v]) {
            if (ans[i] != 0) {
                st.insert(ans[i]);
            }
        }
        int j = 1;
        for (int i : ic[v]) {
            if (ans[i] == 0) {
                while (st.find(j) != st.end()) {
                    j++;
                }
                assert(j <= sze);
                ans[i] = j++;
            }
        }
        dfs(v, u);
    }
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    sze = 1;
    cin >> n >> m;
    REP (i, 0, n) {
        cin >> s[i];
        mxto(sze, s[i]);
        ic[i].resize(s[i]);
        REP (j, 0, s[i]) {
            cin >> ic[i][j];
        }
        sort(ALL(ic[i]));
    }
    REP (i, 1, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    REP (i, 0, s[0]) {
        ans[ic[0][i]] = i + 1;
    }
    dfs(0, -1);
    cout << sze << '\n';
    REP (i, 1, m + 1) {
        mxto(ans[i], 1);
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
// time-limit: 2000
// problem-url: https://codeforces.com/contest/1200/problem/F

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
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 1005
#define MOD 2520

int n;
int k[MAXN];
int m[MAXN];
int e[MAXN][15];
int q;
ii nxt[MAXN][MOD];
int vis[MAXN][MOD], dis[MAXN][MOD], ans[MAXN][MOD];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    REP (i, 1, n + 1) {
        cin >> k[i];
        k[i] = (k[i] % MOD + MOD) % MOD;
    }
    REP (i, 1, n + 1) {
        cin >> m[i];
        REP (j, 0, m[i]) {
            cin >> e[i][j];
        }
    }
    REP (i, 1, n + 1) {
        REP (j, 0, MOD) {
            int l = (j + k[i]) % MOD;
            nxt[i][j] = {e[i][l % m[i]], l};
        }
    }
    REP (i, 1, n + 1) {
        REP (j, 0, MOD) {
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            int ui = i, uj = j;
            while (nxt[ui][uj] != ii{i, j}) {
                auto [vi, vj] = nxt[ui][uj];
                if (vis[vi][vj]) break;
                vis[vi][vj] = 1;
                dis[vi][vj] = dis[ui][uj] + 1;
                tie(ui, uj) = nxt[ui][uj];
            }
            auto [vi, vj] = nxt[ui][uj];
            int l = -1;
            if (vis[vi][vj] == 1) {
                ui = vi, uj = vj;
                auto [oi, oj] = ii{vi, vj};
                set<int> st;
                st.insert(oi);
                while (nxt[ui][uj] != ii{oi, oj}) {
                    auto [vi, vj] = nxt[ui][uj];
                    st.insert(vi);
                    tie(ui, uj) = nxt[ui][uj];
                }
                l = st.size();
            } else {
                l = ans[vi][vj];
            }
            vis[i][j] = 2;
            ans[i][j] = l;
            ui = i, uj = j;
            while (nxt[ui][uj] != ii{i, j}) {
                auto [vi, vj] = nxt[ui][uj];
                if (vis[vi][vj] == 2) break;
                vis[vi][vj] = 2;
                ans[vi][vj] = l;
                tie(ui, uj) = nxt[ui][uj];
            }
        }
    }
    cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        y = (y % MOD + MOD) % MOD;
        cout << ans[x][y] << '\n';
    }
    return 0;
}
// time-limit: 1000
// problem-url: https://codeforces.com/contest/1296/problem/E1

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
const int MAXN = 205;

int n;
string s;
vi adj[MAXN];

bool pos;
bool vis[MAXN];
int col[MAXN];
void dfs(int u) {
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            col[v] = col[u] ^ 1;
            dfs(v);
        } else {
            if (col[v] == col[u]) {
                pos = 0;
            }
        }
    }
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    cin >> s;
    REP (i, 0, n) {
        REP (j, i + 1, n) {
            if (s[i] > s[j]) {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    pos = 1;
    REP (i, 0, n) {
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(i);
    }
    if (!pos) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        REP (i, 0, n) {
            cout << col[i];
        }
        cout << '\n';
    }
    return 0;
}
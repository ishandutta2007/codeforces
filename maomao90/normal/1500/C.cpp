// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/1500/C

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
#define MAXN 1505
#define MOD 998244353

int n, m;
vector<vi> a, b;
int inv[MAXN];
bool used[MAXN], inq[MAXN];
vi ans;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> m;
    a.resize(n, vi(m));
    b.resize(n, vi(m));
    REP (i, 0, n) {
        REP (j, 0, m) {
            cin >> a[i][j];
        }
    }
    REP (i, 0, n) {
        REP (j, 0, m) {
            cin >> b[i][j];
        }
    }
    queue<int> qu;
    REP (i, 0, m) {
        REP (j, 1, n) {
            if (b[j][i] < b[j - 1][i]) {
                inv[i]++;
            }
        }
        if (inv[i] == 0) {
            qu.push(i);
            inq[i] = 1;
        }
    }
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        ans.pb(u);
        cerr << u << '\n';
        REP (i, 0, n - 1) {
            if (used[i]) continue;
            if (b[i][u] != b[i + 1][u]) {
                cerr << ' ' << i << '\n';
                used[i] = 1;
                REP (j, 0, m) {
                    if (inq[j]) continue;
                    if (b[i + 1][j] < b[i][j]) {
                        if (--inv[j] == 0) {
                            inq[j] = 1;
                            qu.push(j);
                        }
                    }
                }
            }
        }
    }
    bool pos = 1;
    reverse(ALL(ans));
    vi id(n, 0);
    iota(ALL(id), 0);
    for (auto i : ans) {
        stable_sort(ALL(id), [&] (int l, int r) {
                return a[l][i] < a[r][i];
                });
    }
    REP (i, 0, n) {
        REP (j, 0, m) {
            if (a[id[i]][j] != b[i][j]) {
                pos = 0;
                break;
            }
        }
        if (!pos) {
            break;
        }
    }
    if (!pos) {
        cout << -1 << '\n';
    } else {
        cout << ans.size() << '\n';
        for (int i : ans) {
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/*
4 4
2 2 2 1
2 2 1 2
1 2 2 2
2 1 2 2
2 2 1 2
2 1 2 2
1 2 2 2
2 2 2 1
*/
// time-limit: 2000
// problem-url: https://codeforces.com/contest/1701/problem/E

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
const int MAXN = 5005;

int _t;
int n, m;
string s, t;
int dp[MAXN][MAXN], pd[MAXN][MAXN], far[2][MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> _t;
    while (_t--) {
        cin >> n >> m;
        cin >> s >> t;
        s = "+" + s;
        t = "+" + t;
        REP (i, 0, n + 1) {
            REP (j, 0, m + 1) {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        REP (i, 1, n + 1) {
            dp[i][0] = i * 2;
            REP (j, 1, m + 1) {
                dp[i][j] = dp[i - 1][j] + 2;
                if (s[i] == t[j]) {
                    mnto(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        REP (i, 0, n + 2) {
            REP (j, 0, m + 2) {
                pd[i][j] = INF;
            }
        }
        pd[n + 1][m + 1] = 0;
        RREP (i, n, 1) {
            pd[i][m + 1] = n - i + 1;
            RREP (j, m, 1) {
                pd[i][j] = pd[i + 1][j] + 1;
                if (s[i] == t[j]) {
                    mnto(pd[i][j], pd[i + 1][j + 1] + 1);
                }
            }
        }
        int ans = INF;
        REP (i, 0, n + 2) {
            REP (j, 0, m + 2) {
                far[i & 1][j] = 0;
            }
        }
        RREP (i, n, 0) {
            RREP (j, m, 1) {
                far[i & 1][j] = 0;
                if (s[i] == t[j]) {
                    far[i & 1][j] = 1 + far[i + 1 & 1][j + 1];
                }
            }
            REP (j, 0, m + 1) {
                int id = far[i + 1 & 1][j + 1] + 1;
                cerr << i << ' ' << j << ' ' << id << '\n';
                mnto(ans, dp[i][j] + pd[i + id][j + id] + (i != 0 || j != 0));
            }
        }
        if (ans == INF) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
}
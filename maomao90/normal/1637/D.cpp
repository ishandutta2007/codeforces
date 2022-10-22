// time-limit: 2000
// problem-url: https://codeforces.com/contest/1637/problem/D

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
#define MAXN 105

int t;
int n;
int a[MAXN], b[MAXN];
int ta[MAXN], tb[MAXN];
int dp[MAXN][2 * MAXN * MAXN];

int solve(int x) {
    REP (i, 0, n) {
        ta[i] = a[i];
        tb[i] = b[i];
    }
    RREP (i, n - 1, 0) {
        if (dp[i][x] == 1) {
            swap(ta[i], tb[i]);
        }
        x -= ta[i];
    }
    int res = 0;
    REP (z, 0, 2) {
        REP (i, 0, n) {
            REP (j, i + 1, n) {
                res += (ta[i] + ta[j]) * (ta[i] + ta[j]);
            }
        }
        swap(ta, tb);
    }
    return res;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        int sm = 0;
        REP (i, 0, n) {
            cin >> a[i];
            sm += a[i];
        }
        REP (i, 0, n) {
            cin >> b[i];
            sm += b[i];
        }
        REP (i, 0, n + 1) {
            REP (j, 0, n * MAXN + 1) {
                dp[i][j] = -1;
            }
        }
        dp[0][a[0]] = 0;
        dp[0][b[0]] = 1;
        REP (i, 1, n) {
            REP (j, 0, sm + 1) {
                if (j - a[i] >= 0 && dp[i - 1][j - a[i]] != -1) {
                    dp[i][j] = 0;
                } else if (j - b[i] >= 0 && dp[i - 1][j - b[i]] != -1) {
                    dp[i][j] = 1;
                }
                cerr << i << ' ' << j << ": " << dp[i][j] << '\n';
            }
        }
        int ans = INF;
        RREP (i, sm / 2, 0) {
            if (dp[n - 1][i] != -1) {
                mnto(ans, solve(i));
                break;
            }
        }
        REP (i, sm / 2 + 1, sm + 1) {
            if (dp[n - 1][i] != -1) {
                mnto(ans, solve(i));
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
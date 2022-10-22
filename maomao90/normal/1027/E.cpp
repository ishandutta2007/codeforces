// time-limit: 2000
// problem-url: https://codeforces.com/contest/1027/problem/E

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
#define MAXN 505
#define MOD 998244353

int n, k;
ll dp1[MAXN][MAXN];
ll dp[MAXN];
ll ans;

int main() {
    cin >> n >> k;
    dp1[0][0] = 1;
    REP (i, 1, n + 1) {
        REP (j, 1, i + 1) {
            REP (k, 1, j) {
                dp1[i][j] += dp1[i - k][j];
                if (dp1[i][j] >= MOD) {
                    dp1[i][j] -= MOD;
                }
            }
            REP (k, 0, j + 1) {
                dp1[i][j] += dp1[i - j][k];
                if (dp1[i][j] >= MOD) {
                    dp1[i][j] -= MOD;
                }
            }
            cerr << i << ' ' << j << ' ' << dp1[i][j] << '\n';
        }
    }
    REP (i, 1, n + 1) {
        ll fi = dp1[n][i] * 2 % MOD;
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        cerr << i << '\n';
        REP (j, 1, n + 1) {
            REP (k, 1, j + 1) {
                if ((ll) i * k >= ::k) {
                    break;
                }
                dp[j] += dp[j - k];
                if (dp[j] >= MOD) {
                    dp[j] -= MOD;
                }
            }
            cerr << ' ' << j << ' ' << dp[j] << '\n';
        }
        ans += fi * dp[n] % MOD;
        if (ans >= MOD) {
            ans -= MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}
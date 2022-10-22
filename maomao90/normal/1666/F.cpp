// time-limit: 3000
// problem-url: https://codeforces.com/contest/1666/problem/F

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
#define MAXN 5005
#define MOD 998244353

int t;
int n;
int a[MAXN];
ll dp[MAXN][MAXN];
int cnt[MAXN], psm[MAXN];
ll choose[MAXN][MAXN];

ll c(int n, int r) {
    if (n < r || r < 0) {
        return 0;
    }
    return choose[n][r];
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    REP (i, 0, MAXN) {
        choose[i][0] = choose[i][i] = 1;
        REP (j, 1, i) {
            choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
            if (choose[i][j] >= MOD) {
                choose[i][j] -= MOD;
            }
        }
    }
    while (t--) {
        cin >> n;
        REP (i, 0, n + 5) {
            REP (j, 0, n + 5) {
                dp[i][j] = 0;
            }
        }
        int m = 0;
        REP (i, 1, n + 1) {
            cin >> a[i];
            a[i] = n + 1 - a[i];
            mxto(m, a[i]);
        }
        REP (i, 0, n + 5) {
            cnt[i] = 0;
            psm[i] = 0;
        }
        REP (i, 1, n + 1) {
            cnt[a[i]]++;
            psm[a[i]]++;
        }
        REP (i, 1, n + 1) {
            psm[i] += psm[i - 1];
        }
        int i;
        for (i = 1; i <= n; i++) {
            if (cnt[i] != 0) {
                break;
            }
        }
        assert(i <= n);
        if (cnt[i] > 1) {
            cout << 0 << '\n';
            continue;
        }
        ll ans = 0;
        dp[i][1] = 1;
        for (i++; i <= n; i++) {
            REP (j, 0, n / 2 + 1) {
                if (cnt[i] == 0) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                dp[i][j] = dp[i - 1][j] * c(j - 1 - (psm[i - 1] - j), cnt[i]) % MOD;
                if (j == n / 2) {
                    dp[i][j] = dp[i - 1][j] * c(n / 2 - (psm[i - 1] - j), cnt[i]) % MOD;
                }
                if (j > 0) {
                    dp[i][j] += dp[i - 1][j - 1] * c(j - 2 - (psm[i - 1] - (j - 1)), cnt[i] - 1) % MOD;
                    if (dp[i][j] >= MOD) {
                        dp[i][j] -= MOD;
                    }
                }
                cerr << n + 1 - i << ' ' << j << ": " << dp[i][j] << '\n';
            }
            //ans = dp[i - 1][n / 2] * c(n / 2 - (psm[i - 1] - n / 2), cnt[i]) % MOD;
        }
        ans = dp[n][n / 2];
        cout << ans << '\n';
    }
    return 0;
}
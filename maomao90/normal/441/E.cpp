// time-limit: 2000
// problem-url: https://codeforces.com/contest/441/problem/E

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
#define MAXN 405

const int LG = 9;
const int MOD = 1 << LG;

int x, n, _p;
ld p;
ld dp[2][MOD][2][MAXN];
ld ans;

int main() {
    cin >> x >> n >> _p;
    p = _p;
    p /= 100;
    int bits = x % MOD;
    int len = 0;
    int odd = x >> LG & 1;
    REP (i, LG, 32) {
        if ((x >> i & 1) != odd) {
            break;
        } else {
            len++;
        }
    }
    dp[0][bits][odd][len] = 1;
    REP (_i, 1, n + 1) {
        int i = _i & 1;
        memset(dp[i], 0, sizeof dp[i]);
        REP (j, 0, MOD) {
            REP (k, 1, MAXN) {
                int c = j >> LG - 1 & 1;
                REP (z, 0, 2) {
                    dp[i][(j << 1) % MOD][c][1 + k * (c == z)] += 
                        dp[i ^ 1][j][z][k] * p;
                }
                int nj = j + 1;
                if (nj == MOD) {
                    dp[i][0][0][k] += dp[i ^ 1][j][1][k] * (1 - p);
                    dp[i][0][1][1] += dp[i ^ 1][j][0][k] * (1 - p);
                } else {
                    dp[i][nj][1][k] += dp[i ^ 1][j][1][k] * (1 - p);
                    dp[i][nj][0][k] += dp[i ^ 1][j][0][k] * (1 - p);
                }
            }
        }
    }
    REP (z, 0, 2) {
        REP (k, 1, MAXN) {
            ans += dp[n & 1][0][z][k] * (9 + k * (z == 0));
        }
    }
    REP (j, 1, MOD) {
        REP (z, 0, 2) {
            REP (k, 1, MAXN) {
                ans += dp[n & 1][j][z][k] * __builtin_ctz(j);
            }
        }
    }
    cout << setprecision(10) << ans << '\n';
    return 0;
}
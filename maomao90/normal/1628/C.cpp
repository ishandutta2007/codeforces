// time-limit: 2000
// problem-url: https://codeforces.com/contest/1628/problem/C

// No temptation has overtaken you except what is common to mankind. And God 
// is faithful; he will not let you be tempted beyond what you can bear.
// But when you are tempted, he will also provide a way out so that you can 
// endure it.
// 1 Corinthians 10:13
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

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MAXN 1005

int t;
int n;
int a[MAXN][MAXN], p[MAXN][MAXN];
int dp[MAXN];
int ans;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        REP (i, 1, n + 1) {
            REP (j, 1, n + 1) {
                scanf("%d", &a[i][j]);
            }
        }
        REP (i, 1, n + 1) {
            REP (j, 1, n + 1) {
                p[i][j] = a[i][j] ^ p[i - 1][j] ^ p[i][j - 1] ^ p[i - 1][j - 1];
            }
        }
        ans = 0;
        REP (i, 0, n / 2) {
            dp[i] = p[n - i][n - i] ^ p[n - i][i] ^ p[i][n - i] ^ p[i][i];
            if (i > 0) {
                dp[i] ^= dp[i - 1];
            }
            debug("%d: %d\n", i, dp[i]);
            ans ^= dp[i];
        }
        REP (_, 0, 2) {
            REP (i, 1, n + 1) {
                REP (j, 1, i) {
                    if (i % 2 == 0 && j % 2 == 1) {
                        ans ^= a[i][j];
                    }
                }
            }
            REP (i, 1, n + 1) {
                REP (j, 1, n / 2 + 1) {
                    swap(a[i][j], a[i][n - j + 1]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
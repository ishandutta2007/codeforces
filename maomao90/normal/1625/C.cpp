// time-limit: 3000
// problem-url: https://codeforces.com/contest/1625/problem/C

// But let justice roll on like a river,
// righteousness like a never-failing stream!
// Amos 5:24
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
#define MAXN 505

int n, l, k;
int d[MAXN], a[MAXN];
int dp[MAXN][MAXN];

int main() {
    scanf("%d%d%d", &n, &l, &k);
    REP (i, 0, n) {
        scanf("%d", &d[i]);
    }
    REP (i, 0, n) {
        scanf("%d", &a[i]);
    }
    d[n] = l;
    REP (i, 0, n + 1) {
        REP (j, 0, n + 1) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    REP (i, 1, n + 1) {
        REP (j, 0, min(k + 1, i)) {
            RREP (k, i - 1, i - j - 1) {
                // j - (i - k - 1) >= 0
                // j - i + k + 1 >= 0
                // k >= i - j - 1
                mnto(dp[i][j], dp[k][j - (i - k - 1)] + a[k] * (d[i] - d[k]));
            }
        }
    }
    int ans = INF;
    REP (i, 0, k + 1) {
        mnto(ans, dp[n][i]);
    }
    printf("%d\n", ans);
    return 0;
}
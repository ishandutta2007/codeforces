#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
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
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 55

int n;
int a[MAXN];
int p;
vi arr;
ll c[MAXN][MAXN];

ld ans;
ll dp[MAXN][MAXN][MAXN];
void countDp(int x) {
    REP (i, 0, arr.size()) {
        REP (j, 0, p + 1) {
            REP (k, 0, arr.size() + 1) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    dp[0][arr[0]][1] = 1;
    REP (i, 1, arr.size()) {
        dp[i][0][0] = 1;
        REP (j, 0, p + 1) {
            REP (k, 1, arr.size() + 1) {
                dp[i][j][k] = (j - arr[i] < 0 ? 0 : dp[i - 1][j - arr[i]][k - 1]) + dp[i - 1][j][k];
                //printf("%d %d %d: %lld\n", i, j, k, dp[i][j][k]);
            }
        }
    }
    REP (i, p - x + 1, p + 1) {
        REP (j, 1, arr.size() + 1) {
            //printf("%d %d %lld\n", i, j, dp[arr.size() - 1][i][j]);
            ans += dp[arr.size() - 1][i][j] * 1.0 / ((ld) c[n][j] * (n - j)) * j;
        }
    }
}

int main() {
    scanf("%d", &n);
    int sum = 0;
    REP (i, 0, n) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    REP (i, 0, MAXN) {
        c[i][0] = c[i][i] = 1;
        REP (j, 1, i) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    scanf("%d", &p);
    if (sum <= p) {
        printf("%d\n", n);
        return 0;
    }
    REP (i, 0, n) {
        arr.pb(a[i]);
    }
    REP (i, 0, n) {
        arr.erase(arr.begin() + i);
        countDp(a[i]);
        arr.insert(arr.begin() + i, a[i]);
    }
    printf("%.9Lf\n", ans);
    return 0;
}
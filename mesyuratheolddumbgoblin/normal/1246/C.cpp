#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN (1<<20)
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll x1, p1, x2, p2;
map<ll, ll> g[600500];
ll row[2005][2005], col[2005][2005], dp[2005][2005][2], rdp[2005][2005], cdp[2005][2005];
ll rows[2005][2005], cols[2005][2005];
char c[2005][2005];
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%s", c[i]);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cols[i][j] = rows[i][j] = 0;
        }
    }
    if (c[n-1][m-1] == 'R') {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = m-1; j >= 0; j--) {
            row[i][j] = row[i][j+1] + (c[i][j] == 'R');
        }
        for (int j = 0; j < m; j++) {
            rows[i][row[i][j]] = j;
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = n-1; j >= 0; j--) {
            col[j][i] = col[j+1][i] + (c[j][i] == 'R');
        }
        for (int j = 0; j < n; j++) {
            cols[i][col[j][i]] = j;
        }
    }

    for (int i = 0; i < n - col[0][0]; i++) {
        dp[i][0][1] = 1;
        rdp[i][1] = 1;
    }
    for (int i = 0; i < m - row[0][0]; i++) {
        dp[0][i][0] = 1;
        cdp[1][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            ll min_r = rows[i][m-j];
            if (min_r < j) {
                dp[i][j][0] = (rdp[i][j] - rdp[i][min_r] + MOD) % MOD;
            }
            cdp[i+1][j] = (cdp[i][j] + dp[i][j][0]) % MOD;
            ll min_c = cols[j][n-i];
            if (min_c < i) {
                dp[i][j][1] = (cdp[i][j] - cdp[min_c][j] + MOD) % MOD;
            }
            rdp[i][j+1] = (rdp[i][j] + dp[i][j][1]) % MOD;
        }
    }

    ll ans = (dp[n-1][m-1][0] + dp[n-1][m-1][1]) % MOD;
    if (n == 1 && m == 1) {
        ans = min(ans, 1LL);
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dp[i][j][0];
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dp[i][j][1];
        }
        cout << "\n";
    }*/
    cout << ans << "\n";
    return 0;
}
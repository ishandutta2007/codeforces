#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
    
const int M = 12, N = 2000;
    
int t, m, n, a[M][N], ind[N], mx[N], val[1 << M], dp[1 << M][2];
    
int solve() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        mx[i] = 0;
        ind[i] = i;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            mx[j] = max(mx[j], a[i][j]);
        }
    }
    sort(ind, ind + n, [](const int &u, const int &v) {
        return mx[u] > mx[v];
    });
    for (int msk = 0; msk < (1 << m); msk++)
        dp[msk][0] = dp[msk][1] = 0;
    int cur = 0, pre = 1;
    for (int i = 0; i < min(m, n); i++) {
        int u = ind[i];
        swap(cur, pre);
        for (int msk = 0; msk < (1 << m); msk++) {
            val[msk] = 0;
            for (int rot = 0; rot < m; rot++) {
                int sum = 0;
                for (int j = 0; j < m; j++) {
                    if (msk >> j & 1) {
                        sum += a[(rot + j) % m][u];
                    }
                }
                val[msk] = max(val[msk], sum);
            }
            dp[msk][cur] = val[msk];
            for (int lst = msk; lst > 0; lst = (lst - 1) & msk) {
                dp[msk][cur] = max(dp[msk][cur], dp[lst][pre] + val[msk ^ lst]);
            }
        }
    }
    return dp[(1 << m) - 1][cur];
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
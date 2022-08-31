#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
const int maxN = 405;
const int maxK = 55;
const ll INF = (ll)1e18 + 100;
ll f[maxN][maxK][3];
ll pref[maxN];
int n, k;
int a[maxN];
ll max_sum[maxN][maxN];
ll min_sum[maxN][maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for (int d = 1; d <= n; d++) {
        for (int l = 1; l + d - 1 <= n; l++) {
            int r = l + d - 1;
            max_sum[l][r] = -INF;
            min_sum[l][r] = INF;
            if (l + 1 <= r) {
                max_sum[l][r] = max(max_sum[l + 1][r], max_sum[l][r]);
                min_sum[l][r] = min(min_sum[l + 1][r], min_sum[l][r]);
            }
            for (int j = l; j <= r; j++) {
                max_sum[l][r] = max(max_sum[l][r], pref[j] - pref[l - 1]);
                min_sum[l][r] = min(min_sum[l][r], pref[j] - pref[l - 1]);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int t = 0; t < 3; t++) {
                f[i][j][t] = -INF;
                if (j == 0) f[i][j][t] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int t = 0; t < 3; t++) {
                int coef = t - 1;
                if (j == 1) {
                    f[i][j][t] = max(coef * max_sum[1][i], coef * min_sum[1][i]);
                    continue;
                }
                for (int take = i; take >= 1; take--) {
                    for (int sgn = -1; sgn <= 1; sgn += 2) {
                        ll upd1 = (coef - sgn) * max_sum[take][i];
                        ll upd2 = (coef - sgn) * min_sum[take][i];
                        f[i][j][t] = max(f[i][j][t], upd1 + f[take - 1][j - 1][sgn + 1]);
                        f[i][j][t] = max(f[i][j][t], upd2 + f[take - 1][j - 1][sgn + 1]);
                    }
                }
            }
        }
    }
    cout << f[n][k][1];
    return 0;
}
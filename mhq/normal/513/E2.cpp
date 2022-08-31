#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
typedef double ld;
const int maxN = 3 * (int)1e4 + 10;
const int maxK = 205;
const ll INF = (ll)1e15 + 100;
ll f[maxN][maxK][3];
ll mn_pref[maxN], mx_pref[maxN];
ll pref[maxN];
int n, k;
int a[maxN];
ll mx[10][10];
main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        mn_pref[i] = min(mn_pref[i - 1], pref[i]);
        mx_pref[i] = max(mx_pref[i - 1], pref[i]);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int t = 0; t < 3; t++) {
                f[i][j][t] = -INF;
                if (j == 0) f[i][j][t] = 0;
            }
        }
    }
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            for (int t = 0; t < 3; t++) {
                f[i][j - 1][t] = max(f[i][j - 1][t], f[i - 1][j - 1][t]);
            }
        }
        for (int sgn = -1; sgn <= 1; sgn += 2) {
            for (int t = 0; t < 3; t++) {
                int coef = t - 1;
                mx[t][sgn + 1] = f[0][j - 1][sgn + 1] - (coef - sgn) * pref[0];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int t = 0; t < 3; t++) {
                int coef = t - 1;
                if (j == 1) {
                    f[i][j][t] = max(coef * pref[i] - coef * mn_pref[i - 1], coef * pref[i]  - coef * mx_pref[i - 1]);
                   // if (t == 0 && j == 1 && i == 2) cout << "HERE " << f[2][1][0] << " " << pref[i] << " " << mn_pref[i - 1] << " " << mx_pref[i - 1] << endl;
                    continue;
                }
                for (int sgn = -1; sgn <= 1; sgn += 2) {
                    f[i][j][t] = max(f[i][j][t], (coef - sgn) * pref[i] + mx[t][sgn + 1]);
                }
            }
            for (int t = 0; t < 3; t++) {
                int coef = t - 1;
                for (int sgn = -1; sgn <= 1; sgn += 2) {
                    mx[t][sgn + 1] = max(mx[t][sgn + 1], f[i][j - 1][sgn + 1] - (coef - sgn) * pref[i]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        f[i][k][1] = max(f[i - 1][k][1], f[i][k][1]);
    }
   /* for (int i = 1; i <= n; i++) {
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
    }*/
    cout << f[n][k][1];
    return 0;
}
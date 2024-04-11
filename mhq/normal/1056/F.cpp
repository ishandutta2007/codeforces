#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
int tst;
const int maxN = 105;
const ld INF = (ld)1e20;
ld dp[maxN][maxN][maxN * 10];
int n;
ld c, t;
int a[maxN], p[maxN];
ld pw[maxN];
void solve() {
    cin >> n >> c >> t;
    pw[0] = 1.0;
    for (int i = 1; i <= n + 1; i++) {
        pw[i] = pw[i - 1] * (10 * 1.0 / 9);
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i];
        sum += p[i];
    }
    if (t == 0) {
        cout << 0 << '\n';
        return ;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
                swap(p[i], p[j]);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int k = 0; k <= n; k++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][k][j] = INF;
            }
        }
    }
    dp[0][0][0] = 0.0;
    for (int i = 0; i + 1 <= n; i++) {
        for (int cnt = 0; cnt <= i; cnt++) {
            for (int score = 0; score <= 10 * cnt; score++) {
                dp[i + 1][cnt][score] = min(dp[i + 1][cnt][score], dp[i][cnt][score]);
                dp[i + 1][cnt + 1][score + p[i + 1]] = min(dp[i + 1][cnt + 1][score + p[i + 1]],
                        dp[i][cnt][score] + a[i + 1] * pw[cnt + 1]);
            }
        }
    }
    for (int score = sum; score >= 0; score--) {
        for (int cnt = 0; cnt <= n; cnt++) {
            ld opt = dp[n][cnt][score];
            if (opt > (ld)1e19) continue;
            ld cur = 10 * cnt;
            ld val = opt;
            if (opt * c >= 1) {
                ld ti = (sqrt(opt * c) - 1) / c;
                val = min(val, ti + (opt / (1 + c * ti)));
            }
            if (val + cur < t) {
                cout << score << '\n';
                return ;
            }
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tst;
    while (tst--) solve();
    return 0;
}
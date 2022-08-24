#include <bits/stdc++.h>

using namespace std;
const int mod = (int)1e9 + 7;

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = (int)1e6 + 100;
int n, m;
int a[maxN];
int cnt[maxN];
int dp[maxN][3][3];
const int INF = (int)1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < maxN; i++) {
        for (int take1 = 0; take1 <= 2; take1++) {
            for (int take2 = 0; take2 <= 2; take2++) {
                dp[i][take1][take2] = -INF;
            }
        }
    }
    dp[1][0][0] = 0;
    int mx = 0;
    for (int i = 1; i <= m; i++) {
        for (int take1 = 0; take1 <= 2; take1++) {
            for (int take2 = 0; take2 <= 2; take2++) {
                for (int take3 = 0; take3 <= 2; take3++) {
                    int f1 = cnt[i] - take1 - take2 - take3;
                    int f2 = cnt[i + 1] - take2 - take3;
                    int f3 = cnt[i + 2] - take3;
                    if (f1 < 0 || f2 < 0 || f3 < 0) continue;
                    dp[i + 1][take2][take3] = max(dp[i + 1][take2][take3], dp[i][take1][take2] + take3 + (f1 / 3));
                    mx = max(mx, dp[i + 1][take2][take3]);
                }
            }
        }
    }
    cout << mx;
    return 0;
}
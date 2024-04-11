
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 705;
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
bool f[maxN][maxN];
bool dp[maxN][maxN][2];
int a[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = gcd(a[i], a[j]);
            f[i][j] = (x > 1);
            f[j][i] = (x > 1);
        }
    }
    for (int l = 1; l <= n; l++) {
        dp[l][l][0] = f[l][l + 1];
        dp[l][l - 1][0] = true;
    }
    for (int r = 1; r <= n; r++) {
        dp[r][r][1] = f[r - 1][r];
        dp[r + 1][r][1] = true;
    }
    for (int dif = 1; dif <= n; dif++) {
        for (int l = 1; l <= n; l++) {
            for (int k = 0; k < 2; k++) {
                int r = dif + l;
                if (r > n) continue;
                if (k == 0 && r == n) continue;
                if (k == 1 && l == 1) continue;
                int pos;
                if (k == 0) pos = r + 1;
                else pos = l - 1;
                for (int j = l; j <= r; j++) {
                    if (f[j][pos] == false) continue;
                    dp[l][r][k] |= (dp[l][j - 1][0] & dp[j + 1][r][1]);
                }
            }
        }
    }
    bool ok = false;
    for (int x = 1; x <= n; x++) {
        ok |= (dp[1][x - 1][0] & dp[x + 1][n][1]);
    }
    if (ok) cout << "Yes";
    else cout << "No";
    return 0;
}
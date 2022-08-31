#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
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
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = 3605;
int c[maxN][maxN];
int h, w, n;
int dp[maxN][maxN];
int f[2][maxN];
void solve(vector<int>& X, int z) {
    memset(dp, 0, sizeof dp);
    sort(X.begin(), X.end());
    int c = X.back() - 1;
    vector<bool> bad(c + 2, false);
    for (int v : X) bad[v] = true;
    dp[0][0] = 1;
    for (int i = 1; i <= c; i++) {
        for (int cnt = 0; 2 * cnt <= i - 1; cnt++) {
            dp[i][cnt] = sum(dp[i][cnt], dp[i - 1][cnt]);
            if (i >= 2 && !bad[i] && !bad[i - 1]) {
                dp[i][cnt + 1] = sum(dp[i][cnt + 1], dp[i - 2][cnt]);
            }
        }
    }
    for (int v = 0; v < maxN; v++) {
        f[z][v] = dp[c][v];
    }
}
int fact[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w >> n;
    vector<int> badX, badY;
    c[0][0] = 1;
    fact[0] = 1;
    for (int i = 1; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
    }
    badX.emplace_back(0);
    badX.emplace_back(h + 1);
    badY.emplace_back(w + 1);
    badY.emplace_back(0);
    int freeX = h;
    int freeY = w;
    for (int i = 1; i <= n; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 == r2) {
            badX.emplace_back(r1);
            badY.emplace_back(c1);
            badY.emplace_back(c2);
            freeX -= 1;
            freeY -= 2;
        }
        else {
            badX.emplace_back(r1);
            badX.emplace_back(r2);
            badY.emplace_back(c1);
            freeX -= 2;
            freeY -= 1;
        }
    }
    for (int z = 0; z < 2; z++) {
        solve(badX, z);
        swap(badX, badY);
    }
    int ans = 0;
    for (int takeX = 0; 2 * takeX <= freeX; takeX++) {
        for (int takeY = 0; 2 * takeY <= freeY; takeY++) {
            int z = mult(c[freeX - 2 * takeX][takeY], mult(c[freeY - 2 * takeY][takeX], mult(f[0][takeX], f[1][takeY])));
 //           cout << " ????? " << z << " " << takeX << " " << takeY << endl;
            ans = sum(ans, mult(fact[takeX], mult(fact[takeY], mult(c[freeX - 2 * takeX][takeY], mult(c[freeY - 2 * takeY][takeX], mult(f[0][takeX], f[1][takeY]))))));
        }
    }
    cout << ans;
}
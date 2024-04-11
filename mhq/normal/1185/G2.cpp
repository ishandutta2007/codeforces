#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
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
int n, T;
const int maxN = 55;
int t[maxN], g[maxN];
vector < int > f[3];
int dp[maxN][maxN][maxN * maxN];
int total[3][maxN][maxN * maxN];
void calc_dp(int v) {
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    int n = f[v].size();
    for (int i = 0; i + 1 <= n; i++) {
        for (int cnt = 0; cnt <= i; cnt++) {
            for (int s = 0; s <= T; s++) {
                dp[i + 1][cnt][s] = sum(dp[i + 1][cnt][s], dp[i][cnt][s]);
                if (s + f[v][i] <= T) {
                    dp[i + 1][cnt + 1][s + f[v][i]] = sum(dp[i + 1][cnt + 1][s + f[v][i]], dp[i][cnt][s]);
                }
            }
        }
    }
    for (int i = 0; i <= T; i++) {
        for (int cnt = 0; cnt <= n; cnt++) {
            total[v][cnt][i] = dp[n][cnt][i];
        }
    }
}
int coef[maxN][maxN][maxN];
vector < int > poly1(4096), poly2(4096);
vector <int> add (vector <int> a, vector <int> b)
{
    vector <int> c (a.size());
    for (int g=0; g<a.size(); g++) c[g]=a[g]+b[g];
    return c;
}
vector <int> sub (vector <int> a, vector <int> b)
{
    vector <int> c (a.size());
    for (int g=0; g<a.size(); g++) c[g]=a[g]-b[g];
    return c;
}
int pw2[20];
vector < int > kar(vector < int >& x, vector < int >& y, int n) {
    if (n <= 4) {
        vector < int > f(pw2[n + 1]);
        for (int i = 0; i < pw2[n]; i++) {
            for (int j = 0; j < pw2[n]; j++) {
                f[i + j] = sum(f[i + j], mult(x[i], y[j]));
            }
        }
        return f;
    }
    vector < int > a[2], b[2];
    for (int i = 0; i < 2; i++) {
        a[i].resize(pw2[n - 1]);
        b[i].resize(pw2[n - 1]);
        for (int j = i * pw2[n - 1]; j < (i + 1) * pw2[n - 1]; j++) {
            a[i][j - i * pw2[n - 1]] = x[j];
            b[i][j - i * pw2[n - 1]] = y[j];
        }
    }
    vector < int > ans(pw2[n + 1]);
    auto kar1 = kar(a[0], b[0], n - 1);
    auto kar2 = kar(a[1], b[1], n - 1);
    for (int i = 0; i < pw2[n - 1]; i++) {
        a[0][i] = sum(a[0][i], a[1][i]);
        b[0][i] = sum(b[0][i], b[1][i]);
    }
    auto kar3 = kar(a[0], b[0], n - 1);
    for (int i = 0; i < pw2[n]; i++) {
        ans[i] = kar1[i];
    }
    for (int i = 0; i < pw2[n]; i++) {
        kar3[i] = sub(kar3[i], sum(kar2[i], kar1[i]));
    }
    for (int i = 0; i < pw2[n]; i++) {
        ans[i + pw2[n]] = sum(ans[i + pw2[n]], kar2[i]);
    }
    for (int i = 0; i < pw2[n]; i++) {
        ans[i + pw2[n - 1]] = sum(ans[i + pw2[n - 1]], kar3[i]);
    }
    return ans;
}

int s[maxN][maxN][maxN * maxN];
int ways[maxN][maxN][maxN][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pw2[0] = 1;
    for (int i = 1; i < 20; i++) pw2[i] = 2 * pw2[i - 1];
    //freopen("input.txt", "r", stdin);
    cin >> n >> T;
    //n = 50;
    //T = 2500;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> g[i];
        //t[i] = 50;
        //g[i] = i % 3 + 1;
        g[i]--;
        f[g[i]].push_back(t[i]);
    }
    if (f[0].size() > f[2].size()) swap(f[0], f[2]);
    if (f[1].size() > f[2].size()) swap(f[1], f[2]);
    for (int i = 0; i < 3; i++) {
        calc_dp(i);
    }
    for (int i = 0; i <= f[0].size(); i++) {
        for (int j = 0; j <= f[1].size(); j++) {
            for (int k = 0; k <= T; k++) {
                poly1[k] = total[0][i][k];
                poly2[k] = total[1][j][k];
            }
            auto kara = kar(poly1, poly2, 12);
            for (int k = 0; k <= T; k++) {
                s[i][j][k] = kara[k];
            }
        }
    }
    for (int f = 0; f < 3; f++) {
        ways[0][0][0][f] = 1;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                for (int lst = 0; lst < 3; lst++) {
                    if (lst != 0 && i > 0) {
                        ways[i][j][k][lst] = sum(ways[i][j][k][lst], mult(i, ways[i - 1][j][k][0]));
                    }
                    if (lst != 1 && j > 0) {
                        ways[i][j][k][lst] = sum(ways[i][j][k][lst], mult(j, ways[i][j - 1][k][1]));
                    }
                    if (lst != 2 && k > 0) {
                        ways[i][j][k][lst] = sum(ways[i][j][k][lst], mult(k, ways[i][j][k - 1][2]));
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i1 = 0; i1 <= f[0].size(); i1++) {
        for (int i2 = 0; i2 <= f[1].size(); i2++) {
            for (int i3 = 0; i3 <= f[2].size(); i3++) {
                for (int k = 0; k <= T; k++) {
                    coef[i1][i2][i3] = sum(coef[i1][i2][i3], mult(s[i1][i2][k], total[2][i3][T - k]));
                }
                if (i1 > 0) {
                    ans = sum(ans, mult(i1, mult(coef[i1][i2][i3], ways[i1 - 1][i2][i3][0])));
                }
                if (i2 > 0) {
                    ans = sum(ans, mult(i2, mult(coef[i1][i2][i3], ways[i1][i2 - 1][i3][1])));
                }
                if (i3 > 0) {
                    ans = sum(ans, mult(i3, mult(coef[i1][i2][i3], ways[i1][i2][i3 - 1][2])));
                }
            }
        }
    }
    cout << ans;
    return 0;
}
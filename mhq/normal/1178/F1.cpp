#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 505;
int c[maxN];
int n, m;
int dp[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int len = 0; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (len == 0) {
                dp[l][r] = 1;
                continue;
            }
            pair < int, int > mn = make_pair(n + 1, -1);
            for (int j = l; j <= r; j++) {
                mn = min(mn, make_pair(c[j], j));
            }
            int where = mn.second;
            int le = 0;
            int ri = 0;
            for (int x = l - 1; x <= where - 1; x++) {
                le = sum(le, mult(dp[l][x], dp[x + 1][where - 1]));
            }
            for (int x = where; x <= r; x++) {
                ri = sum(ri, mult(dp[where + 1][x], dp[x + 1][r]));
            }
            dp[l][r] = mult(le, ri);
        }
    }
    cout << dp[1][n];
    return 0;
}
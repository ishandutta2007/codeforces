#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 405;
const int mod = 1e9 + 7;

int dp[maxn][maxn];

void add(int& a, int b) { a = (a + b) % mod; }

void init() {
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            for (int k = 0; k <= j + 1; k++) {
                if (j >= k) add(dp[i][j], ll(2 * j + 1) * dp[i - 1][k] % mod * dp[i - 1][j - k] % mod);
                if (j > 0 && j - 1 >= k) add(dp[i][j], ll(dp[i - 1][k]) * dp[i - 1][j - 1 - k] % mod);
                int mult = ll(j + 1) * j;
                if (j + 1 < maxn) add(dp[i][j], ll(mult) * dp[i - 1][k] % mod * dp[i - 1][j + 1 - k] % mod);
            }
}

int main() {
    init();

    int k; cin >> k;
    cout << dp[k][1] << endl;
}
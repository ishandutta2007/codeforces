#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int n, d[55];
int dp[2][55][55][55][55]; //i, k1, k2, k1', k2' - 0, 0, k1', k2' -> k1', k2', 0, 0

void add(int& a, int b) { a = (a + b) % mod; }

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> d[i];
    
    dp[0][d[0] == 2][d[0] == 3][d[1] == 2][d[1] == 3] = 1;
    for (int i = 2; i < n; i++) {
        for (int k1 = 0; k1 <= 50; k1++)
            for (int k2 = 0; k2 <= 50; k2++)
                for (int l1 = 0; l1 <= 50; l1++)
                    for (int l2 = 0; l2 <= 50; l2++)
                        if (dp[0][k1][k2][l1][l2]) {
                            int v = dp[0][k1][k2][l1][l2];
                            if (!v) continue;
                            if (d[i] == 2) {
                                if (k2) {
                                    add(dp[1][k1+1][k2-1][l1+1][l2], ll(k2) * v % mod);
                                    if (l1) add(dp[1][k1+1][k2-1][l1-1][l2], ll(k2) * l1 * v % mod);
                                    if (l2) add(dp[1][k1+1][k2-1][l1+1][l2-1], ll(k2) * l2 * v % mod);
                                }

                                if (k1) {
                                    add(dp[1][k1-1][k2][l1+1][l2], ll(k1) * v % mod);
                                    if (l1) add(dp[1][k1-1][k2][l1-1][l2], ll(k1) * l1 * v % mod);
                                    if (l2) add(dp[1][k1-1][k2][l1+1][l2-1], ll(k1) * l2 * v % mod);
                                }
                            } else {
                                if (k2) {
                                    add(dp[1][k1+1][k2-1][l1][l2+1], ll(k2) * v % mod);
                                    if (l1) add(dp[1][k1+1][k2-1][l1][l2], ll(k2) * l1 * v % mod);
                                    if (l2) add(dp[1][k1+1][k2-1][l1+2][l2-1], ll(k2) * l2 * v % mod);
                                    if (l1 > 1) add(dp[1][k1+1][k2-1][l1-2][l2], ll(k2) * l1 * (l1 - 1) / 2 * v % mod);
                                    if (l2 > 1) add(dp[1][k1+1][k2-1][l1+2][l2-2], ll(k2) * l2 * (l2 - 1) / 2 * v % mod);
                                    if (l1 && l2) add(dp[1][k1+1][k2-1][l1][l2-1], ll(k2) * l1 * l2 * v % mod);
                                }

                                if (k1) {
                                    add(dp[1][k1-1][k2][l1][l2+1], ll(k1) * v % mod);
                                    if (l1) add(dp[1][k1-1][k2][l1][l2], ll(k1) * l1 * v % mod);
                                    if (l2) add(dp[1][k1-1][k2][l1+2][l2-1], ll(k1) * l2 * v % mod);
                                    if (l1 > 1) add(dp[1][k1-1][k2][l1-2][l2], ll(k1) * l1 * (l1 - 1) / 2 * v % mod);
                                    if (l2 > 1) add(dp[1][k1-1][k2][l1+2][l2-2], ll(k1) * l2 * (l2 - 1) / 2 * v % mod);
                                    if (l1 && l2) add(dp[1][k1-1][k2][l1][l2-1], ll(k1) * l1 * l2 * v % mod);
                                }
                            }
                        }

        for (int l1 = 0; l1 <= 50; l1++)
            for (int l2 = 0; l2 <= 50; l2++)
                if (l1 || l2) {
                    add(dp[1][l1][l2][0][0], dp[1][0][0][l1][l2]);
                    dp[1][0][0][l1][l2] = 0;
                }

        for (int k1 = 0; k1 <= 50; k1++) for (int k2 = 0; k2 <= 50; k2++) for (int l1 = 0; l1 <= 50; l1++) for (int l2 = 0; l2 <= 50; l2++) {
            dp[0][k1][k2][l1][l2] = dp[1][k1][k2][l1][l2], dp[1][k1][k2][l1][l2] = 0;
            //if (dp[0][k1][k2][l1][l2] > 0) cout << i << ' ' << k1 << ' ' << k2 << ' ' << l1 << ' ' << l2 << ' ' << dp[0][k1][k2][l1][l2] << endl;
        }


    }

    cout << dp[0][0][0][0][0] << '\n';
}
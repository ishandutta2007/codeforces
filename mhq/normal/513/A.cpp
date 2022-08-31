#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld  ;
const int maxN = 55;
bool dp[2][maxN][maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            for (int move = 0; move < 2; move++) {
                if (move == 0) {
                    dp[move][i][j] = false;
                    if (i == 0) {
                        continue;
                    }
                    if (j == 0) {
                        dp[move][i][j] = true;
                        continue;
                    }
                    for (int x = 1; x <= min(i, k1); x++) {
                        dp[move][i][j] |= (!dp[move ^ 1][i - x][j]);
                    }
                }
                else {
                    dp[move][i][j] = false;
                    if (j == 0) {
                        continue;
                    }
                    if (i == 0) {
                        dp[move][i][j] = true;
                    }
                    for (int x = 1; x <= min(j, k2); x++) {
                        dp[move][i][j] |= (!dp[move ^ 1][i][j - x]);
                    }
                }
            }
        }
    }
    if (dp[0][n1][n2]) {
        cout << "First";
    }
    else {
        cout << "Second";
    }
    return 0;
}
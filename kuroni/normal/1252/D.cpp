#include <bits/stdc++.h>
using namespace std;

const int LG = 31;

int t, l, r;
long long dp[LG][2][2];

bool status(int pre, int cur, int pos, int bit) {
    if (((bit >> pos) & 1) < cur) {
        return true;
    } else if (((bit >> pos) & 1) > cur) {
        return false;
    } else {
        return pre;
    }
}

long long solve(int l, int r) {
    if (l == -1 || r == -1) {
        return 0;
    }
    for (int i = 1; i < LG; i++) {
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                dp[i][x][y] = 0;
            }
        }
    }
    for (int i = 1; i < LG; i++) {
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                for (int msk = 0; msk < 3; msk++) {
                    int nx = status(x, msk & 1, i - 1, l);
                    int ny = status(y, msk >> 1, i - 1, r);
                    dp[i][nx][ny] += dp[i - 1][x][y];
                }
            }
        }
    }
    return dp[LG - 1][0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[0][0][0] = 1;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        cout << solve(r, r) - solve(l - 1, r) - solve(r, l - 1) + solve(l - 1, l - 1) << '\n';
    }
}
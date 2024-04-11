#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int n;
int ans[1005][1005];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int cop = n;
    if (n % 2 == 1) {
        while (n > 1) {
                for (int i = n - 2; i >= 1; i--) {
                    ans[i][n] = 1;
                    ans[n - 1][i] = 1;
                    ans[n][n - 1] = 1;
                }
                n -= 2;
        }
        n = cop;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
        return 0;
    }
    if (n == 2 || n == 4) {
        cout << -1;
        return 0;
    }
    ans[1][2] = 1;
    ans[2][3] = 1;
    ans[3][1] = 1;
    ans[4][5] = 1;
    ans[5][6] = 1;
    ans[6][4] = 1;
    ans[1][4] = 1;
    ans[5][2] = 1;
    ans[3][6] = 1;
    ans[2][4] = 1;
    ans[5][3] = 1;
    ans[6][1] = 1;
    ans[4][3] = 1;
    ans[1][5] = 1;
    ans[6][2] = 1;
    while (n > 6) {
        for (int i = n - 2; i >= 1; i--) {
                ans[i][n] = 1;
                ans[n - 1][i] = 1;
                ans[n][n - 1] = 1;
            }
            n -= 2;
    }
    n = cop;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
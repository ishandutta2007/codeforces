/*
    07.02.2019 17:08:53
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#include "C:/C++ libs/print.h"
#define show(x) cout << "     " << #x << " = " << to_string(x) << endl;
#else
#define show(x) 42;
#define print(x) 42;
#define printTree(x) 42;
#define printMatrix(x) 42;
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector< int > a(m);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        --k;
        ++a[k];
    }
    if (m <= 2) {
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans += a[i] / 3;
        }
        cout << ans << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (a[i] > 9) {
            int k = a[i] % 3;
            if (k == 0) k = 3;
            k += 6;
            ans += (a[i] - k) / 3;
            a[i] = k;
        }
    }
    show(a);
    vector< vector< vector< int > > > dp(2, vector< vector< int > >(10, vector< int >(10, 0)));
    int i1 = 0, i2 = 1;
    for (int i = 0; i <= a[0]; ++i) {
        for (int j = 0; j <= a[1]; ++j) {
            dp[i1][i][j] = i / 3 + j / 3;
        }
    }
    for (int i = 2; i < m; ++i) {
        for (int j = 0; j <= a[i - 1]; ++j) {
            for (int k = 0; k <= a[i]; ++k) {
                dp[i2][j][k] = 0;
                if (a[i - 1] < j || a[i] < k) {
                    continue;
                }
                for (int u = 0; u <= k; ++u) {
                    if (a[i - 2] < u || j < u) {
                        break;
                    }
                    dp[i2][j][k] = max(dp[i2][j][k], dp[i1][a[i - 2] - u][j - u] + u + (k - u) / 3);
                }
            }
        }
        swap(i1, i2);
    }
    // show(a);
    cout << ans + dp[i1][a[a.size() - 2]][a[a.size() - 1]] << '\n';
    return 0;
}
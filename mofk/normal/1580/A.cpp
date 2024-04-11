#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[505][505];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> (a[i] + 1);
        vector<vector<int>> s(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) s[i][j] = s[i][j-1] + (a[i][j] == '1');
        int ans = n * m;
        for (int l = 1; l <= m; ++l) {
            for (int r = l + 3; r <= m; ++r) {
                vector<int> v(n + 1, 0), u(n + 1, 0), best(n + 1, 1e8);
                for (int i = 1; i <= n; ++i) {
                    u[i] = v[i] = s[i][r-1] - s[i][l];
                    if (a[i][l] == '0') ++v[i];
                    if (a[i][r] == '0') ++v[i];
                    u[i] = r - l - 1 - u[i];
                }
                for (int i = 1; i + 4 <= n; ++i) {
                    best[i] = min(u[i], best[i-1] + v[i]);
                    int opt = best[i] + v[i+1] + v[i+2] + v[i+3] + u[i+4];
                    ans = min(ans, opt);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(4, -INF));
        f[0][0] = 0;
        f[0][1] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                int c = j % 2, b = j / 2;
                if (b && c && s[i] == s[i-1]) continue;
                if (i == 1) {
                    f[i][j] = b + c;
                    continue;
                }
                for (int a = 0; a < 2; ++a) {
                    if (a && b && s[i-1] == s[i-2]) continue;
                    if (a && c && s[i] == s[i-2]) continue;
                    f[i][j] = max(f[i][j], f[i-1][2 * a + b] + c);
                }
            }
        }
        int ans = n;
        for (int i = 0; i < 4; ++i) ans = min(ans, n - f[n-1][i]);
        cout << ans << '\n';
    }
    return 0;
}
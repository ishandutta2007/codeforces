#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m, ans = 160000;
        cin >> n >> m;
        vector<vector<int>> A(n, vector<int>(m)), S(n, vector<int>(m));
        for (int i = 0; i < n; i += 1) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j += 1) {
                S[i][j] = A[i][j] = s[j] - '0';
                if (i) S[i][j] += S[i - 1][j];
            }
        }
        for (int i = 0; i < n; i += 1) {
            for (int j = i + 4; j < n; j += 1) {
                vector<int> a(m), b(m);
                for (int k = 0; k < m; k += 1) {
                    a[k] = j - i - 1 - (S[j - 1][k] - S[i][k]);
                    b[k] = (S[j - 1][k] - S[i][k]) + not A[i][k] + not A[j][k];
                    if (k) b[k] += b[k - 1];
                }
                int pre = 160000;
                for (int k = 3; k < m; k += 1) {
                    pre = min(pre, a[k - 3] - b[k - 3]);
                    ans = min(ans, pre + b[k - 1] + a[k]);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
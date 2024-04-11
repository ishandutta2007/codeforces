#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                a[i][j] = s[j] - '0';
                cnt += a[i][j];
            }
        }
        int ans = numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                cur += a[j][(i + j) % n];
            }
            ans = min(ans, cnt - cur + n - cur);
        }
        cout << ans << '\n';
    }
}
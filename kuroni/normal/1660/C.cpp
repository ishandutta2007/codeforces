#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        vector<int> dp(n + 1), lst(26);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            int ind = s[i - 1] - 'a';
            if (lst[ind] != 0) {
                dp[i] = max(dp[i], dp[lst[ind] - 1] + 2);
            }
            lst[ind] = i;
        }
        cout << n - dp[n] << '\n';
    }
}
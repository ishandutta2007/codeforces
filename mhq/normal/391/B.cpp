#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
string s;
const int maxN = 1005;
int dp[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (j % 2 != i % 2 && s[i] == s[j]) {
                dp[i] = dp[j] + 1;
                break;
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
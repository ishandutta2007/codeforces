#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << fixed << setprecision(10);

    int n, k;
    cin >> n >> k;
    ld ans = 0;
    vector<ld> dp(n + 2), new_dp(n + 2);
    dp[1] = 1;
    int sz = 1;

    for (int i = 1; i <= n; i++) {
        static constexpr int FLEX = 800;
        int new_sz = min(sz + 1, FLEX);
        fill(new_dp.begin(), new_dp.begin() + new_sz + 1, 0);

        for (int j = 1; j <= new_sz; j++) {
            static ld here = ld(1) / k;
            new_dp[j] += dp[j] * (1 - here);
            ans += dp[j] * here * (ld(j + 1) / 2 + 1) * ld(j) / (j + 1);
            new_dp[j] += dp[j] * here * ld(j) / (j + 1);
            if (j + 1 <= new_sz) new_dp[j + 1] += dp[j] * here * ld(1) / (j + 1);
        }

        sz = new_sz;
        swap(dp, new_dp);
    }
    cout << ans * k << '\n';
}
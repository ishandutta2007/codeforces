#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        string s;
        cin >> n >> s;

        array<array<int, 2>, 2> dp;
        dp[s[0] - '0'] = {n, 0};
        dp[(s[0] - '0') ^ 1] = {n, 1};

        for (int i = 1; i < n; i++) {
            array<array<int, 2>, 2> new_dp;
            new_dp.fill({n, n});

            for (int c : {0, 1}) {
                int cost = c != s[i] - '0';
                for (int parity : {0, 1}) {
                    new_dp[c][parity] = min(dp[c][parity ^ 1], parity == 1 ? dp[c ^ 1][0] : n) + cost;
                }
            }
            swap(dp, new_dp);
        }
        cout << min(dp[0][0], dp[1][0]) << '\n';
    }
}
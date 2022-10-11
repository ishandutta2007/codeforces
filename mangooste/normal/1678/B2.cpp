#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

template<typename T>
void setmin(T &a, T b) {
    if (b < a) a = b;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        string s;
        cin >> n >> s;

        array<array<pair<int, int>, 2>, 2> dp;
        dp[s[0] - '0'] = {pair{n, n}, {0, 1}};
        dp[(s[0] - '0') ^ 1] = {pair{n, n}, {1, 1}};

        for (int i = 1; i < n; i++) {
            array<array<pair<int, int>, 2>, 2> new_dp;
            new_dp.fill({pair{n, n}, {n, n}});

            for (int c : {0, 1}) {
                int cost = c != s[i] - '0';
                for (int parity : {0, 1}) {
                    setmin(new_dp[c][parity], {dp[c][parity ^ 1].first + cost, dp[c][parity ^ 1].second});
                    if (parity == 1) {
                        setmin(new_dp[c][parity], {dp[c ^ 1][0].first + cost, dp[c ^ 1][0].second + 1});
                    }
                }
            }
            swap(dp, new_dp);
        }
        
        auto ans = min(dp[0][0], dp[1][0]);
        cout << ans.first << ' ' << ans.second << '\n';
    }
}
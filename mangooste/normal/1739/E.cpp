#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
    #define dprint(...)
#endif // LOCAL

template<typename A, typename B>
bool setmax(A &a, const B &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    array<string, 2> s;
    cin >> n >> s[0] >> s[1];
    s[0][0] = '1';

    constexpr int INF = 1e9;
    vector<array<array<int, 3>, 2>> dp(n + 3);
    for (int i = 0; i < n; i++) {
        for (int row : {0, 1}) {
            for (int d : {0, 1, 2}) {
                dp[i][row][d] = -INF;
            }
        }
    }

    array<array<int, 3>, 2> last;
    last.fill({n, n + 1, n + 2});
    for (int i = n - 1; i >= 0; i--) {
        for (int row : {0, 1}) {
            if (s[row][i] == '1') {
                last[row][2] = last[row][1];
                last[row][1] = last[row][0];
                last[row][0] = i;
            }
        }
        for (int d : {2, 1, 0}) {
            for (int row : {0, 1}) {
                if (s[row][i] != '1') continue;
                for (int same : last[row]) {
                    if (same == i) continue;
                    setmax(dp[i][row][d], dp[same][row][max(0, d - (same - i))] + 1);
                }
                for (int diff : last[row ^ 1]) {
                    if (diff < i + d) continue;
                    setmax(dp[i][row][d], dp[diff][row ^ 1][2] + 1);
                }
            }
        }
    }
    cout << dp[0][0][0] - 1 << '\n';
}
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

constexpr int N = 102;
bool dp[N][N][2][2][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    for (int p1 : {0, 1}) for (int p2 : {0, 1}) {
        if (p1 == 0) {
            dp[0][0][p1][p2][0] = true;
            dp[0][0][p1][p2][1] = false;
        } else {
            dp[0][0][p1][p2][0] = false;
            dp[0][0][p1][p2][1] = true;
        }
    }

    for (int n1 = 0; n1 < N; n1++) {
        for (int n2 = 0; n2 < N; n2++) {
            if (n1 == 0 && n2 == 0) continue;
            for (int p1 : {0, 1}) {
                for (int p2 : {0, 1}) {
                    { // alice
                        if (n1 > 0) {
                            dp[n1][n2][p1][p2][0] |= !dp[n1 - 1][n2][p1 ^ 1][p2][1];
                        }
                        if (n2 > 0) {
                            dp[n1][n2][p1][p2][0] |= !dp[n1][n2 - 1][p1][p2][1];
                        }
                    }
                    { // bob
                        if (n1 > 0) {
                            dp[n1][n2][p1][p2][1] |= !dp[n1 - 1][n2][p1][p2 ^ 1][0];
                        }
                        if (n2 > 0) {
                            dp[n1][n2][p1][p2][1] |= !dp[n1][n2 - 1][p1][p2][0];
                        }
                    }
                }
            }
        }
    }

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        int n;
        cin >> n;
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            (x % 2 ? odd : even)++;
        }
        cout << (dp[odd][even][0][0][0] ? "Alice" : "Bob") << '\n';
    }
}
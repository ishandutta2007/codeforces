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

void solve(int test_num) {
    string s;
    cin >> s;
    int n = len(s);
    assert(n % 2 == 0);

    vector dp(n, vector<pair<int, int>>(n));
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = {0, 0};
        } else {
            dp[i][i + 1] = {0, 1};
        }
    }
    for (int length = 3; length <= n; length += 2) {
        for (int i = 0; i + length < n; i++) {
            int j = i + length;

            auto solve = [&](int l, int r, char last) -> pair<int, int> {
                bool can_draw = false;
                for (int my : {l, r}) {
                    int nl = l + (my == l);
                    int nr = r - (my == r);
                    pair<int, int> alice{dp[nl][nr].first, last};
                    pair<int, int> bob{dp[nl][nr].second, s[my]};
                    auto mn = min(alice, bob);
                    pair<int, int> cur{alice != mn, bob != mn};
                    if (cur.first > cur.second) return cur;
                    if (cur.first == cur.second) {
                        can_draw = true;
                    }
                }
                return can_draw ? pair{0, 0} : pair{0, 1};
            };

            [&]() {
                bool can_draw = false;
                for (int my : {i, j}) {
                    int nl = i + (my == i);
                    int nr = j - (my == j);
                    auto res = solve(nl, nr, s[my]);
                    if (res.first < res.second) {
                        dp[i][j] = res;
                        return;
                    }
                    if (res.first == res.second) {
                        can_draw = true;
                    }
                }
                dp[i][j] = can_draw ? pair{0, 0} : pair{1, 0};
            }();
        }
    }

    auto res = dp[0][n - 1];
    if (res.first == res.second) {
        cout << "Draw\n";
    } else if (res.first < res.second) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
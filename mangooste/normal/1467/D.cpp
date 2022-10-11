#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "/home/lesha/codes/Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

const int MOD = int(1e9) + 7;

inline void addSelf(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

inline void subSelf(int &a, int b) {
    a -= b;
    if (a < 0) a += MOD;
}

inline int mult(int a, int b) {
    return 1ll * a * b % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= k; j++) {
        for (int i = 0; i < n; i++) {
            if (i) addSelf(dp[i][j], dp[i - 1][j - 1]);
            if (i != n - 1) addSelf(dp[i][j], dp[i + 1][j - 1]);
        }
    }

    vector<int> ways(n);
    for (int i = 0; i < n; i++) {
        for (int id = 0; id <= k; id++) {
            addSelf(ways[i], mult(dp[i][id], dp[i][k - id]));
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        addSelf(ans, mult(a[i], ways[i]));
    }

    while (q--) {
        int i, x;
        cin >> i >> x;
        i--;
        subSelf(ans, mult(a[i], ways[i]));
        a[i] = x;
        addSelf(ans, mult(a[i], ways[i]));
        cout << ans << '\n';
    }
}
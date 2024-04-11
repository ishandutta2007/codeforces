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
bool setmin(A &a, const B &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    k = min(k, n - 1);

    vector<int> p(n), inv_p(n);
    vector suf(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> p[i], p[i]--;
        inv_p[p[i]] = i;
        suf[p[i]][i]++;
    }

    for (int val = 0; val < n; val++) {
        for (int i = n - 1, sum = 0; i >= 0; i--) {
            sum += suf[val][i];
            suf[val][i] = (val == 0 ? 0 : suf[val - 1][i]) + sum;
        }
    }

    auto query = [&](int val, int pos) {
        return val < 0 ? 0 : suf[val][pos];
    };

    vector<int> from(n), to(n);
    for (int i = 0; i < n; i++) {
        from[i] = i;
        to[i] = min(n - 1, from[i] + k);
    }
    assert(to[0] - from[0] + 1 == k + 1);

    const int MASK = 1 << k + 1, INF = n * n;
    vector dp(k + 1, vector<int>(MASK, INF));
    for (int val = 0; val <= k; val++) {
        dp[val][1] = 0;
    }

    for (int i = 1; i < n; i++) {
        vector ndp(to[i] - from[i] + 1, vector<int>(MASK, INF));
        for (int pmax = from[i - 1]; pmax <= to[i - 1]; pmax++) {
            for (int mask = 0; mask < MASK; mask++) {
                if (dp[pmax - from[i - 1]][mask] == INF) continue;

                auto count_invs = [&](int val) {
                    int res = dp[pmax - from[i - 1]][mask] + query(pmax - (k + 1), inv_p[val]);
                    for (int j = max(0, pmax - k); j <= pmax; j++) {
                        if (mask >> pmax - j & 1) res += inv_p[j] > inv_p[val];
                    }
                    return res;
                };

                for (int val = max(0, pmax - k); val <= pmax; val++) {
                    int id = pmax - val;
                    if (mask >> id & 1) continue;
                    assert(pmax >= from[i]);
                    setmin(ndp[pmax - from[i]][mask | (1 << id)], count_invs(val));
                }

                int min_unused = max(0, pmax - k);
                while (min_unused <= pmax && (mask >> pmax - min_unused & 1)) {
                    min_unused++;
                }
                for (int val = pmax + 1; val <= min(to[i], min_unused + k); val++) {
                    int nmask = ((mask << val - pmax) | 1) & MASK - 1;
                    assert(val >= from[i]);
                    setmin(ndp[val - from[i]][nmask], count_invs(val));
                }
            }
        }
        dp.swap(ndp);
    }

    assert(len(dp) == 1);
    cout << dp[0][MASK - 1] << '\n';
}
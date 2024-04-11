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

int bit(ll value, int bit) {
    return value >> bit & 1;
}

void solve(int test_num) {
    ll start, length;
    cin >> start >> length;
    length--;

    const int LG = 62;
    ll dp[2][2][2], ndp[2][2][2];
    memset(dp, 0, sizeof(dp));
    dp[1][0][0] = 1;
    for (int i = LG; i >= 0; i--) {
        memset(ndp, 0, sizeof(dp));
        for (int flag : {0, 1}) {
            for (int suffix_parity : {0, 1}) {
                for (int parity_have : {0, 1}) {
                    int nflag0 = bit(length, i) == 0 ? flag : 0;
                    int nflag1 = bit(length, i) == 0 ? (flag == 0 ? 0 : -1) : flag;
                    ll val = dp[flag][suffix_parity][parity_have];
                    if (bit(start, i) == 0) {
                        ndp[nflag0][0][parity_have] += val;
                        if (nflag1 != -1) ndp[nflag1][suffix_parity ^ 1][parity_have] += val;
                    } else {
                        ndp[nflag0][suffix_parity ^ 1][parity_have ^ 1] += val;
                        if (nflag1 != -1) ndp[nflag1][0][parity_have ^ suffix_parity] += val;
                    }
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }
    cout << dp[0][0][1] + dp[0][1][1] + dp[1][0][1] + dp[1][1][1] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
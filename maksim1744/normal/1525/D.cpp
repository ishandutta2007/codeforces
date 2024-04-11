/*
    author:  Maksim1744
    created: 18.05.2021 21:05:42
*/

#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> sum0(n), sum1(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) sum0[i] = i;
        else sum1[i] = i;
    }
    for (int i = 1; i < n; ++i) {
        sum0[i] += sum0[i - 1];
        sum1[i] += sum1[i - 1];
    }

    auto get_sum = [&](int l, int r) {
        if (l > r) return 0;
        int s0 = sum0[r] - (l == 0 ? 0 : sum0[l - 1]);
        int s1 = sum1[r] - (l == 0 ? 0 : sum1[l - 1]);
        return abs(s0 - s1);
    };

    vector<int> dp(n, 1e9);

    // offset for negative balance
    int N = n;
    vector<int> with_balance(N * 2 + 1, -1);

    int balance = N + 0;
    with_balance[N + 0] = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) --balance;
        else ++balance;
        if (with_balance[balance] != -1) {
            int l = with_balance[balance];
            int r = i;
            int sm = get_sum(l, r);
            // type 2 edge
            dp[r] = min(dp[r], sm + (l == 0 ? 0 : dp[l - 1]));
        }
        with_balance[balance] = i + 1;
        if (a[i] == 0) {
            // type 1 edge
            dp[i] = min(dp[i], (i == 0 ? 0 : dp[i - 1]));
        }
    }

    cout << dp.back() << '\n';

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using DP = array<array<ll, 3>, 3>;

const ll INF = 1e18;
const array<ll, 3> INF_ARRAY = {-INF, -INF, -INF};
const DP BASE{INF_ARRAY, INF_ARRAY, INF_ARRAY};

inline void setmax(ll &a, ll b) {
    if (a < b)
        a = b;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    if (n == 1)
        return cout << a[0] << '\n', 0;

    DP dp = BASE;
    dp[0][0] = a[0];
    dp[1][1] = -a[0];

    for (int i = 1; i < n; i++) {
        DP new_dp = BASE;
        for (int j : {0, 1, 2})
            for (int k : {0, 1}) {
                int coeff = 1 - 2 * k, nxt = (j + k) % 3;
                setmax(new_dp[nxt][k], dp[j][k ^ 1] + a[i] * coeff);
                setmax(new_dp[nxt][2], dp[j][2] + a[i] * coeff);
                setmax(new_dp[nxt][2], dp[j][k] + a[i] * coeff);
            }
        dp = new_dp;
    }
    cout << dp[((1 - n) % 3 + 3) % 3][2] << '\n';
}
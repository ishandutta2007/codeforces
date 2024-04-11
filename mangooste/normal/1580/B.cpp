#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
class y_combinator {
    const Fun fun_;
public:
    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, k, p;
    cin >> n >> m >> k >> p;

    if (p == 1) {
        cout << "0\n";
        return 0;
    }

    vector<vector<int>> choose(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++) {
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; j++) {
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
            if (choose[i][j] >= p)
                choose[i][j] -= p;
        }
    }

    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = 1ll * fact[i - 1] * i % p;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
    for (int m0 = 0; m0 <= m; m0++)
        for (int k0 = 0; k0 <= k; k0++)
            dp[0][m0][k0] = k0 == 0;

    cout << y_combinator([&](auto solve, int n, int m, int k) -> int {
        if (dp[n][m][k] != -1)
            return dp[n][m][k];
     
        if (n == 0)
            return dp[n][m][k] = k == 0;
     
        if (m > n)
            return dp[n][m][k] = k == 0 ? fact[n] : 0;
     
        if (m == 1)
            return dp[n][m][k] = k == 1 ? fact[n] : 0;
     
        ll answer = 0;
        for (int size = 0; size <= n - size - 1; size++) {
            ll current = 0;
            for (int cnt = 0; cnt <= k && cnt <= size; cnt++)
                current += 1ll * solve(size, m - 1, cnt) * solve(n - size - 1, m - 1, k - cnt) % p * choose[n - 1][size] % p;
     
            if (size == n - size - 1)
                answer += current;
            else
                answer += 2 * current;
        }
     
        return dp[n][m][k] = answer % p;
    })(n, m, k) << '\n';
}
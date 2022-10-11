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
#endif // LOCAL

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    auto sos = [&](vector<int> dp, int n) {
        assert(len(dp) <= n);
        dp.resize(n);
        for (int bit = 0; bit <= __lg(n); bit++) {
            for (int i = 0; i < n; i++) {
                if (i >> bit & 1) dp[i] ^= dp[i ^ (1 << bit)];
            }
        }
        return dp;
    };

    auto res = y_combinator([&](auto solve, const vector<int> &a) -> vector<int> {
        int n = len(a);
        assert(n > 0);
        const int LG = n == 1 ? 0 : __lg(n - 1) + 1, N = 1 << LG;
        assert(N >= n);
        if (n == N) {
            vector<int> res(n);
            for (int i = 0; i < n; i++) {
                res[(n - 1) ^ i] = a[i];
            }
            return sos(res, n);
        }

        vector<int> na;
        na.reserve(n - (N >> 1));
        for (int i = N >> 1; i < n; i++) {
            na.push_back(a[i] ^ a[i - (N >> 1)]);
        }
        auto top = solve(na);

        auto sum = sos(top, N >> 1);
        vector<int> bottom(a.begin(), a.begin() + (N >> 1));
        assert(len(bottom) == len(sum));
        for (int i = 0; i < len(bottom); i++) {
            bottom[i] ^= sum[((N >> 1) - 1) ^ i];
        }
        bottom = solve(bottom);

        bottom.insert(bottom.end(), all(top));
        return bottom;
    })(a);

    assert(len(res) == n);
    reverse(all(res));
    for (int i = 0; i < n; i++) {
        cout << res[i] << " \n"[i == n - 1];
    }
}

/*
reverse ans and now:
a[i] = XOR over all j if choose(i + j, j) is odd: ans[j]
choose(i + j, j) is odd when j is submask of (i+j) => j&i == 0

LG = floor(log(n - 1) + 1)
N = 2**LG

n == N => simple inverse SOS dp
else find elements n, n+1, ..., N-1 and then SOS dp + solve for N/2
*/
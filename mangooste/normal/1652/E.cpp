#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

template<typename Fun>
struct y_combinator {
    const Fun fun;

    y_combinator(const Fun&& fun) : fun(forward<const Fun>(fun)) {}

    template<typename... Tail>
    decltype(auto) operator()(Tail&&... tail) const {
        return fun(ref(*this), forward<Tail>(tail)...);
    }
};

constexpr int MAX_MEM = 500 * 100004;
constexpr int B = 450, A = 1e5 + 4, MAX_LEN = A / B + 2;
int ans = 1;
int dp[MAX_LEN + 1][2 * A];
vector<int> vv[MAX_LEN + 1];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    // mt19937 rng;
    // for (auto &x : a) x = rng() % int(1e5) + 1;
    // for (int i = 0; i < n; i++) a[i] = i;

    vector<ll> values(n);
    for (int d = -B; d <= B; d++) {
        for (int i = 0; i < n; i++) values[i] = a[i] - 1ll * i * d;
        sort(all(values));
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && values[i] == values[j]) j++;
            ans = max(ans, j - i);
        }
    }

    for (int i = 0; i < n; i++) {
        int pos = i % (MAX_LEN + 1);
        for (auto x : vv[pos]) dp[pos][x] = 0;
        vv[pos].clear();
        for (int j = max(0, i - MAX_LEN); j < i; j++) {
            if ((a[i] - a[j]) % (i - j) == 0) {
                int jpos = j % (MAX_LEN + 1);
                int d = (a[i] - a[j]) / (i - j);
                vv[pos].push_back(d + A);
                if (dp[pos][d + A] < dp[jpos][d + A] + 1) {
                    dp[pos][d + A] = dp[jpos][d + A] + 1;
                }
            }
        }
        for (auto x : vv[pos]) ans = max(ans, dp[pos][x] + 1);
    }

    cout << n - ans << '\n';
}
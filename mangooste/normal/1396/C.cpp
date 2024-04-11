#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

const ll INF = 2e18;

inline void setmin(ll &a, ll b) {
    if (a > b)
        a = b;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    ll r[3], d;
    cin >> n >> r[0] >> r[1] >> r[2] >> d;
    vec<ll> a(n);
    for (auto &x : a)
        cin >> x;

    auto get = [&](int i) {
        ar<ll, 3> ans;
        ans[0] = (a[i] + 2) * r[0];
        ans[1] = a[i] * r[0] + r[2];
        ans[2] = r[1] + r[0];
        return ans;
    };

    vec<ll> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
            ar<ar<ll, 3>, 2> ways{get(i), get(i + 1)};
            for (auto x : ways[0])
                for (auto y : ways[1])
                    setmin(dp[i + 2], dp[i] + x + y + 4 * d);
        }
        setmin(dp[i + 1], dp[i] + a[i] * r[0] + r[2] + d);
        for (auto x : get(i))
            setmin(dp[i + 1], dp[i] + 3 * d + x);
    }
    auto cur = get(n - 2);
    cout << min(dp[n] - d, dp[n - 2] + d + a[n - 1] * r[0] + r[2] + d + *min_element(all(cur))) << '\n';
}
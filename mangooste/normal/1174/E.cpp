#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

const int mod = int(1e9) + 7;

int power(int a, int b) {
    int prod = 1;
    for (; b; b /= 2) {
        if (b % 2)
            prod = 1ll * prod * a % mod;
        a = 1ll * a * a % mod;
    }
    return prod;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> p(n + 1);
    iota(all(p), 0);
    vec<vec<int>> primes(n + 1);
    for (int i = 2; i <= n; i++)
        if (p[i] == i)
            for (int j = i; j <= n; j += i) {
                primes[j].push_back(i);
                p[j] = i;
            }

    vec<int> cnt(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            cnt[i]++;

    vec<int> sum(n + 1);
    for (int i = 2; i <= n; i++) {
        for (int j = i; j != 1;) {
            int pr = p[j];
            while (j % pr == 0) {
                j /= pr;
                sum[i]++;
            }
        }
    }
    int mx = *max_element(all(sum));

    vec<int> fact(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = 1ll * fact[i - 1] * i % mod;
    vec<int> rfact(n + 1);
    rfact.back() = power(fact.back(), mod - 2);
    for (int i = n; i; i--)
        rfact[i - 1] = 1ll * rfact[i] * i % mod;

    auto C = [&](int n, int k) {
        return 1ll * fact[n] * rfact[k] % mod * rfact[n - k] % mod;
    };

    vec<int> sz(n + 1);
    for (int i = 2; i <= n; i++)
        sz[i] = n - cnt[i] + 1;
    vec<int> dp(n + 1);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (p[i] == i)
            dp[i] = fact[n - cnt[i]];
        else
            for (auto p : primes[i]) {
                int delta = cnt[i / p] - cnt[i];
                dp[i] += 1ll * dp[i / p] * C(sz[i / p] + delta - 2, delta - 1) % mod * fact[delta] % mod;
                if (dp[i] >= mod)
                    dp[i] -= mod;
            }
        if (sum[i] == mx) {
            ans += dp[i];
            if (ans >= mod)
                ans -= mod;
        }
    }
    cout << ans << '\n';
}
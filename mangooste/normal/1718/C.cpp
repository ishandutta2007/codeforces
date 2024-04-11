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

namespace sieve {
    std::vector<int> primes, smallest_factor_;

    void init(int n) {
        if (int(smallest_factor_.size()) >= n + 1)
            return;

        int previous_size = smallest_factor_.size();
        while (int(smallest_factor_.size()) != n + 1)
            smallest_factor_.push_back(smallest_factor_.size());

        for (int i = std::max(2, previous_size); i <= n; i++) {
            if (smallest_factor_[i] == i)
                primes.emplace_back(i);

            for (int j = 0; j < int(primes.size()) && primes[j] <= smallest_factor_[i] && primes[j] * i <= n; j++)
                smallest_factor_[primes[j] * i] = primes[j];
        }
    }

    struct sieve_info {
        std::vector<int> &data;

        sieve_info(std::vector<int> &data) : data(data) {}

        int operator[](int x) {
            if (x >= int(data.size()))
                init(x);

            return data[x];
        }
    } smallest_factor(smallest_factor_);

    bool is_prime(int n) {
        if (n <= 1)
            return false;

        return smallest_factor[n] == n;
    }

    std::vector<std::pair<int, int>> get_factors(int n) {
        std::vector<std::pair<int, int>> factors;
        while (n != 1) {
            int prime = smallest_factor[n];
            factors.emplace_back(prime, 0);

            while (smallest_factor[n] == prime) {
                factors.back().second++;
                n /= prime;
            }
        }
        return factors;
    }
} // namespace sieve

using sieve::primes;
using sieve::smallest_factor;
using sieve::is_prime;
using sieve::get_factors;

void solve(int test_num) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    
    vector<int> divs;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i) && n % i == 0) divs.push_back(n / i);
    }

    auto initial_a = a;
    vector<int> pos(q), delta(q);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> pos[i] >> x;
        pos[i]--;
        delta[i] = x - a[pos[i]];
        a[pos[i]] = x;
    }
    a = initial_a;

    vector<ll> ans(q + 1);
    for (auto x : divs) {
        struct segtree {
            int n;
            vector<ll> tree;

            segtree(int n) : n(n), tree(2 * n) {}

            void add(int pos, int delta) {
                pos += n;
                tree[pos] += delta;
                for (pos >>= 1; pos; pos >>= 1) {
                    tree[pos] = max(tree[pos << 1], tree[pos << 1 | 1]);
                }
            }

            ll query() {
                return tree[1];
            }
        } tree(x);

        for (int i = 0; i < n; i++) {
            tree.add(i % x, a[i]);
        }
        ans[0] = max(ans[0], tree.query() * x);
        for (int i = 0; i < q; i++) {
            tree.add(pos[i] % x, delta[i]);
            ans[i + 1] = max(ans[i + 1], tree.query() * x);
        }
    }

    for (auto x : ans) cout << x << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
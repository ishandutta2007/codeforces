#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> primes, sieve(n + 1);
    vector<ll> p_value(n + 1), value(n + 1), f_value(n + 1);
    iota(all(sieve), 0);
    for (int i = 2; i <= n; i++) {
        if (sieve[i] == i) {
            p_value[i] = rng();
            primes.push_back(i);
        }
        for (int j = 0; j < len(primes) && primes[j] <= sieve[i] && primes[j] * i <= n; j++) {
            sieve[primes[j] * i] = primes[j];
        }
        value[i] = value[i / sieve[i]] ^ p_value[sieve[i]];
        f_value[i] = f_value[i - 1] ^ value[i];
    }

    ll tot = 0;
    for (auto &x : f_value) tot ^= x;
    if (tot == 0) {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << " \n"[i == n];
        }
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (tot == f_value[i]) {
            cout << n - 1 << '\n';
            for (int j = 1; j <= n; j++) {
                if (i != j) cout << j << ' ';
            }
            cout << '\n';
            return 0;
        }
    }

    unordered_map<ll, int> mp;
    mp.reserve(n);
    for (int i = 1; i <= n; i++) {
        mp[f_value[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        ll need = tot ^ f_value[i];
        auto it = mp.find(need);
        if (it == mp.end()) continue;
        cout << n - 2 << '\n';
        for (int j = 1; j <= n; j++) {
            if (j != i && j != it->second) cout << j << ' ';
        }
        cout << '\n';
        return 0;
    }

    cout << n - 3 << '\n';
    for (int i = 1; i < n; i++) {
        if (i != 2 && i != (n - 1) / 2) cout << i << ' ';
    }
    cout << '\n';
}
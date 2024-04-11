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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    const int A = *max_element(all(a)) + 1;
    vector<bool> occ(A);
    for (auto &x : a) occ[x] = true;

    vector<bool> squared_free(A, true);
    for (int i = 2; i * i < A; i++) {
        for (int j = i * i; j < A; j += i * i) {
            squared_free[j] = false;
        }
    }
    vector<int> sieve(A);
    iota(all(sieve), 0);
    for (int i = 2; i < A; i++) {
        if (sieve[i] != i) continue;
        for (int j = i + i; j < A; j += i) {
            if (sieve[j] == j) sieve[j] = i;
        }
    }
    vector<int> mobius(A);
    mobius[1] = 1;
    for (int i = 2; i < A; i++) {
        if (!squared_free[i]) continue;
        mobius[i] = -mobius[i / sieve[i]];
    }

    vector<vector<int>> good_divs(A);
    for (int i = 1; i < A; i++) {
        if (!squared_free[i]) continue;
        for (int j = i; j < A; j += i) {
            good_divs[j].push_back(i);
        }
    }

    ll ans = *max_element(all(a));
    for (int g = 1; g < A; g++) {
        vector<int> cur;
        for (int i = g; i < A; i += g) {
            if (occ[i]) cur.push_back(i / g);
        }
        if (cur.empty()) continue;
        reverse(all(cur));

        const int A = *max_element(all(cur)) + 1;
        vector<int> tot(A);

        auto add = [&](int x, int coeff) {
            for (auto y : good_divs[x]) {
                tot[y] += coeff;
            }
        };

        for (auto x : cur) add(x, 1);
        for (int i = 0, j = len(cur) - 1; i < j; i++) {
            add(cur[i], -1);

            auto check = [&]() {
                ll sum = 0;
                for (auto x : good_divs[cur[i]]) {
                    sum += tot[x] * mobius[x];
                }
                return sum != 0;
            };

            if (!check()) continue;
            while (j > i && check()) {
                add(cur[j--], -1);
            }
            ans = max(ans, 1ll * cur[i] * cur[j + 1] * g);
        }
    }
    cout << ans << '\n';
}
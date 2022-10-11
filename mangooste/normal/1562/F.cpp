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


void solve(int test_num) {
    int n;
    cin >> n;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    auto query = [&](int i, int j) {
        cout << "? " << i + 1 << ' ' << j + 1 << endl;
        ll res;
        cin >> res;
        return res;
    };

    vector<int> ans(n);
    if (1ll * n * (n - 1) / 2 <= n + 5000) {
        vector res(n, vector<ll>(n));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res[i][j] = res[j][i] = query(i, j);
            }
        }

        for (int i = 0; i < n; i++) {
            ll g = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) g = gcd(g, res[i][j]);
            }
            ans[i] = g;
        }

        if (n == 3) {
            int pos_max = max_element(all(ans)) - ans.begin();
            if (ans[pos_max] > *min_element(all(ans)) + 2) {
                ans[pos_max] /= 2;
            }
        }
    } else {
        vector<int> ord(n);
        iota(all(ord), 0);
        shuffle(all(ord), rng);

        const int ITS = min(n - 1, 5000);
        int max_prime = -1, pos = -1;
        for (int i = 1; i < ITS; i++) {
            auto update_prime = [&](int prime) {
                if (max_prime < prime) {
                    max_prime = prime;
                    pos = i;
                }
            };

            ll res = query(ord[i - 1], ord[i]);
            for (int i = 2; i * i <= res; i++) {
                if (res % i == 0) {
                    update_prime(i);
                    while (res % i == 0) res /= i;
                }
            }
            if (res != 1) update_prime(res);
        }
        assert(pos != -1);

        ans[ord[pos]] = max_prime;
        for (int i = 0; i < n; i++) {
            if (i == pos) continue;
            ans[ord[i]] = query(ord[i], ord[pos]) / max_prime;
        }
    }

    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    cout << flush;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
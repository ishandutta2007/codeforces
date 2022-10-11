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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int k;
    cin >> k;
    vector<int> b(k);
    for (auto &x : b) cin >> x;

    if (accumulate(all(a), 0ll) != accumulate(all(b), 0ll)) {
        cout << "No\n";
        return;
    }

    auto transform = [&](const vector<int> &a) {
        vector<pair<int, ll>> c;

        auto add = [&](const pair<int, ll> &p) {
            if (c.empty() || c.back().first != p.first) {
                c.push_back(p);
            } else {
                c.back().second += p.second;
            }
        };

        for (auto x : a) {
            ll cnt = 1;
            while (x % m == 0) {
                cnt *= m;
                x /= m;
            }
            add({x, cnt});
        }
        return c;
    };

    cout << (transform(a) == transform(b) ? "Yes" : "No") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    auto f = [&](int x) {
        int a = x / 3, b = (x - a) / 2, c = x - a - b;
        return 2ll * (1ll * a * b + 1ll * b * c + 1ll * a * c);
    };

    vector<ll> dp;
    for (int x = 0;; x++) {
        dp.push_back(f(x));
        if (dp.back() > int(1e9)) break;
    }

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        cout << lower_bound(all(dp), n) - dp.begin() << '\n';
    }
}
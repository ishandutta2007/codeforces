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
    int n, c, q;
    string s;
    cin >> n >> c >> q >> s;
    vector<pair<ll, ll>> ops(c);
    for (auto &[l, r] : ops) {
        cin >> l >> r;
        l--;
    }

    vector<ll> pref(c + 1);
    pref[0] = n;
    for (int i = 0; i < c; i++) {
        pref[i + 1] = pref[i] + ops[i].second - ops[i].first;
    }

    while (q--) {
        ll pos;
        cin >> pos;
        pos--;
        for (int i = c - 1; i >= 0; i--) {
            ll cur_n = pref[i];
            if (pos < cur_n) continue;
            pos = ops[i].first + pos - cur_n;
        }
        assert(0 <= pos && pos < n);
        cout << s[pos] << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
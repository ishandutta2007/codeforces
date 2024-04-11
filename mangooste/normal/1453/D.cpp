#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "./Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

void solve() {
    ll n;
    cin >> n;
    if (n % 2) {
        cout << "-1\n";
        return;
    }

    vector<int> ans;
    for (ll len = 61; len >= 1;) {
        ll val = (1ll << (len + 1)) - 2;
        if  (n >= val) {
            n -= val;
            ans.emplace_back(1);
            for (int i = 0; i < len - 1; i++) {
                ans.emplace_back(0);
            }
        } else {
            len--;
        }
    }
    assert(n == 0);

    cout << len(ans) << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
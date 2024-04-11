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
    vector a(n, vector<ll>(m));
    for (auto &v : a) {
        for (auto &x : v) cin >> x;
    }

    map<ll, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        ll cur = 0;
        for (int j = 0; j < m; j++) {
            cur += 1ll * j * a[i][j];
        }
        mp[cur].push_back(i);
    }

    assert(len(mp) == 2);
    auto a1 = mp.begin()->first;
    auto b1 = mp.begin()->second;
    auto a2 = mp.rbegin()->first;
    auto b2 = mp.rbegin()->second;
    if (len(b1) != n - 1) {
        swap(a1, a2);
        swap(b1, b2);
    }
    assert(len(b1) == n - 1);
    cout << b2[0] + 1 << ' ' << a2 - a1 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
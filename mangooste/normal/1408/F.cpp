#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

vector<pair<int, int>> ops;

void go(int l, int r) {
    if (r - l == 1) return;
    int m = (l + r) / 2;
    go(l, m);
    go(m, r);
    for (int i = 0; i < m - l; i++) {
        ops.emplace_back(l + i, m + i);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int p2 = 1;
    while (p2 <= n) p2 *= 2;
    p2 /= 2;
    go(0, p2);
    go(n - p2, n);

    assert(len(ops) < 5'000'00);
    cout << len(ops) << '\n';
    for (auto [i, j] : ops) {
        cout << i + 1 << ' ' << j + 1 << '\n';
    }
}
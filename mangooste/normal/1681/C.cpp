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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    auto sorted_a = a;
    sort(all(sorted_a));
    auto sorted_b = b;
    sort(all(sorted_b));

    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
        int pos = 0;
        while (pos < n && (p[pos] != -1 || a[pos] != sorted_a[i] || b[pos] != sorted_b[i])) {
            pos++;
        }
        if (pos == n) {
            cout << "-1\n";
            return;
        }
        p[pos] = i;
    }

    vector<pair<int, int>> ops;
    vector<bool> used(n);
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        vector<int> cycle;
        for (int j = i; !used[j]; j = p[j]) {
            used[j] = true;
            cycle.push_back(j);
        }

        for (int i = 1; i < len(cycle); i++) {
            ops.emplace_back(cycle[0], cycle[i]);
            swap(p[cycle[0]], p[cycle[i]]);
        }
    }
    assert(is_sorted(all(p)));

    cout << len(ops) << '\n';
    for (auto &[i, j] : ops) {
        cout << i + 1 << ' ' << j + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}
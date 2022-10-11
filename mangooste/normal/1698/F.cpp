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

    auto read = [&]() {
        vector<int> a(n);
        for (auto &x : a) cin >> x, x--;
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n - 1; i++) {
            pairs.push_back(minmax(a[i], a[i + 1]));
        }
        sort(all(pairs));
        return pair{a, pairs};
    };

    auto [a, pa] = read();
    auto [b, pb] = read();

    if (pa != pb || a[0] != b[0]) {
        cout << "NO\n";
        return;
    }
    assert(a.back() == b.back());
    cout << "YES\n";
    vector<pair<int, int>> ops;

    auto make_operation = [&](int l, int r) {
        assert(a[l] == a[r]);
        ops.emplace_back(l, r);
        reverse(a.begin() + l, a.begin() + r + 1);
    };
    
    for (int i = 0; i < n - 1; i++) {
        assert(a[i] == b[i]);
        if (a[i + 1] == b[i + 1]) continue;

        auto run = [&]() {
            for (int j = i + 2; j < n; j++) {
                if (a[j] == a[i] && a[j - 1] == b[i + 1]) {
                    make_operation(i, j);
                    return true;
                }
            }
            return false;
        };
        if (run()) continue;

        int pos = i;
        while (a[pos] != a[i] || a[pos + 1] != b[i + 1]) {
            assert(pos < n - 2);
            pos++;
        }

        vector<int> left(n, -1);
        for (int j = i; j <= pos; j++) left[a[j]] = j;
        for (int j = pos + 1; j < n; j++) {
            if (left[a[j]] != -1) {
                make_operation(left[a[j]], j);
                break;
            }
        }
        assert(run());
    }
    assert(a == b);

    cout << len(ops) << '\n';
    for (auto &[l, r] : ops) {
        cout << l + 1 << ' ' << r + 1 << '\n';
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
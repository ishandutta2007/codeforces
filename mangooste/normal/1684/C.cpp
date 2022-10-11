#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> used(m);
    vector<int> cols;

    auto add = [&](int col) {
        if (col < 0 || col >= m) return;
        if (!used[col]) {
            used[col] = true;
            cols.push_back(col);
        }
    };

    vector a(n, vector<int>(m));
    for (auto &v : a) {
        for (auto &x : v) cin >> x;
        vector<int> nxt(m, m - 1);
        for (int i = m - 2; i >= 0; i--) {
            nxt[i] = v[i + 1] == v[i] ? nxt[i + 1] : i;
        }
        vector<int> prev(m);
        for (int i = 1; i < m; i++) {
            prev[i] = v[i - 1] == v[i] ? prev[i - 1] : i;
        }

        for (int i = 0; i < m - 1; i++) {
            if (v[i] > v[i + 1]) {
                add(prev[i]);
                add(i);
                add(nxt[i + 1]);
            }
        }
    }

    if (cols.empty()) {
        cout << "1 1\n";
        return;
    }
    if (len(cols) > 6) {
        cout << "-1\n";
        return;
    }

    auto check = [&](int i, int j) {
        auto b = a;
        for (int pos = 0; pos < n; pos++) {
            swap(b[pos][i], b[pos][j]);
        }
        for (auto &v : b) {
            if (!is_sorted(all(v))) return false;
        }
        return true;
    };

    for (auto x : cols) {
        for (auto y : cols) {
            if (check(x, y)) {
                cout << x + 1 << ' ' << y + 1 << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}
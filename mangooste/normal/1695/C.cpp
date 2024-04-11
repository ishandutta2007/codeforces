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
    vector a(n, vector<int>(m));
    for (auto &v : a) {
        for (auto &x : v) cin >> x;
    }
    if (n % 2 == m % 2) {
        cout << "No\n";
        return;
    }

    vector from(n, vector<int>(m, INT_MAX)), to(n, vector<int>(m, INT_MIN));
    from[0][0] = to[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            from[i][j] += a[i][j];
            to[i][j] += a[i][j];
            
            auto update = [&](int ii, int jj) {
                from[ii][jj] = min(from[ii][jj], from[i][j]);
                to[ii][jj] = max(to[ii][jj], to[i][j]);
            };

            if (i + 1 < n) update(i + 1, j);
            if (j + 1 < m) update(i, j + 1);
        }
    }
    cout << (from[n - 1][m - 1] <= 0 && 0 <= to[n - 1][m - 1] ? "Yes" : "No") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
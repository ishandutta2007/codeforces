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
    vector<int> p(n);
    for (auto &x : p) cin >> x, x--;

    if (n == 1) {
        cout << "-1\n";
        return;
    }

    vector<bool> used(n);
    vector<int> ans(n);
    for (int pos = 0; pos < n; pos++) {
        bool found = false;
        for (int x = 0; x < n; x++) {
            if (used[x] || x == p[pos]) continue;
            if (pos == n - 2) {
                int left = 0;
                while (used[left] || left == x) left++;
                if (left == p[n - 1]) continue;
            }
            found = true;
            ans[pos] = x;
            used[x] = true;
            break;
        }
        assert(found);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
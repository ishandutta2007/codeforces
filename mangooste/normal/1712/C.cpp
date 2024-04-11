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
    vector<int> a(n);
    for (auto &x : a) cin >> x, x--;

    vector<int> right(n, -1);
    for (int i = 0; i < n; i++) {
        right[a[i]] = i;
    }

    int suf = n - 1;
    while (suf > 0 && a[suf - 1] <= a[suf]) suf--;
    if (suf == 0) {
        cout << "0\n";
        return;
    }

    vector<bool> used(n);
    int mx = -1, diff = 0;
    for (int i = 0; i < n; i++) {
        if (!used[a[i]]) {
            used[a[i]] = true;
            mx = max(mx, right[a[i]]);
            diff++;
        }
        if (mx == i && i >= suf - 1) {
            cout << diff << '\n';
            return;
        }
    }
    assert(false);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
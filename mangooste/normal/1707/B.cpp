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
    for (auto &x : a) cin >> x;

    int zeroes = 0;
    while (true) {
        assert(is_sorted(all(a)));
        int pos = 0;
        while (pos < len(a) && a[pos] == 0) pos++;
        zeroes += pos;
        a = vector<int>(pos + all(a));

        if (a.empty()) {
            cout << "0\n";
            return;
        }
        if (len(a) == 1) {
            cout << a[0] << '\n';
            return;
        }

        vector<int> b;
        for (int i = 0; i < len(a) - 1; i++) {
            b.push_back(a[i + 1] - a[i]);
        }
        if (zeroes) {
            b.push_back(a[0]);
            zeroes--;
        }
        sort(all(b));
        a = b;
    }
    cout << a[0] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
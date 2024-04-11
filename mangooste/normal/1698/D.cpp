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

    auto query = [&](int l, int r) {
        cout << "? " << l + 1 << ' ' << r << endl;
        vector<int> res(r - l);
        for (auto &x : res) cin >> x;
        return res;
    };

    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        auto cur = query(0, mid);
        int bad = 0;
        for (auto &x : cur) bad += x > mid;
        ((mid - bad) % 2 ? r : l) = mid;
    }
    cout << "! " << r << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
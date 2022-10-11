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

    auto query = [&](int a, int b) {
        assert(0 <= a && a < (1 << n));
        assert(0 <= b && b < (1 << n));
        cout << "? " << a + 1 << ' ' << b + 1 << endl;
        int res;
        cin >> res;
        return res;
    };

    vector<int> cur(1 << n);
    iota(all(cur), 0);
    while (len(cur) > 1) {
        if (len(cur) == 2) {
            cur = {query(cur[0], cur[1]) == 1 ? cur[0] : cur[1]};
            continue;
        }

        assert(len(cur) % 4 == 0);
        vector<int> ncur;
        for (int i = 0; i < len(cur); i += 4) {
            int a = cur[i], b = cur[i + 1], c = cur[i + 2], d = cur[i + 3];
            int res = query(a, c);
            if (res == 1) {
                ncur.push_back(query(a, d) == 1 ? a : d);
            } else if (res == 2) {
                ncur.push_back(query(b, c) == 1 ? b : c);
            } else {
                ncur.push_back(query(b, d) == 1 ? b : d);
            }
        }
        swap(cur, ncur);
    }
    cout << "! " << cur[0] + 1 << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
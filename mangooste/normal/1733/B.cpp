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
    #define dprint(...)
#endif // LOCAL

void solve(int test_num) {
    int n, x, y;
    cin >> n >> x >> y;
    if (x > y) swap(x, y);
    if (y == 0 || x != 0 || (n - 1) % y) {
        cout << "-1\n";
        return;
    }
    for (int st = 0; st < n - 1; st += y) {
        int id = st == 0 ? 1 : st + 2;
        for (int i = 0; i < y; i++) {
            cout << id << ' ';
        }
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
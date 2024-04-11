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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (max({a, b, c, d}) == 0) {
        cout << "0\n";
    } else if (min({a, b, c, d}) == 1) {
        cout << "2\n";
    } else {
        cout << "1\n";
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
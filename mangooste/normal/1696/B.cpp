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

    if (count(all(a), 0) == n) {
        cout << "0\n";
        return;
    }

    int from = 0;
    while (a[from] == 0) from++;
    int to = n - 1;
    while (a[to] == 0) to--;
    cout << 1 + (count(a.begin() + from, a.begin() + to + 1, 0) != 0) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
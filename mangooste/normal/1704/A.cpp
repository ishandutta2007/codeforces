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
    string first, second;
    cin >> n >> m >> first >> second;

    cout << ([&]() {
        for (int i = 0; i < m - 1; i++) {
            if (first[n - 1 - i] != second[m - 1 - i]) return false;
        }
        int pos = n - m;
        return count(first.begin(), first.begin() + pos + 1, second[0]) != 0;
    }() ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
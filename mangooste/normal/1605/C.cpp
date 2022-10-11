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
    string s;
    cin >> n >> s;

    for (int len = 2; len <= 10; len++) {
        for (int i = 0; i + len <= n; i++) {
            auto cnt = [&](char c) {
                return std::count(s.begin() + i, s.begin() + i + len, c);
            };
            if (cnt('a') > max(cnt('b'), cnt('c'))) {
                cout << len << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
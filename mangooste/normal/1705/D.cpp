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
    string start, finish;
    cin >> n >> start >> finish;
    if (start[0] != finish[0] || start.back() != finish.back()) {
        cout << "-1\n";
        return;
    }

    auto transform = [&](const string &s) {
        vector<int> ones;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != s[i + 1]) ones.push_back(i);
        }
        return ones;
    };

    auto start_ones = transform(start);
    auto finish_ones = transform(finish);
    if (len(start_ones) != len(finish_ones)) {
        cout << "-1\n";
        return;
    }

    ll ans = 0;
    for (int i = 0; auto x : start_ones) {
        ans += abs(x - finish_ones[i++]);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
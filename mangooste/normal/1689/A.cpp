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
    int n, m, k;
    cin >> n >> m >> k;
    string first, second;
    cin >> first >> second;

    sort(all(first));
    sort(all(second));
    reverse(all(first));
    reverse(all(second));

    int tot = 0;
    string ans;
    while (!first.empty() && !second.empty()) {
        if (tot == k || second.back() <= first.back()) {
            tot = 1;
            ans += second.back();
            second.pop_back();
            swap(first, second);
        } else {
            tot++;
            ans += first.back();
            first.pop_back();
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
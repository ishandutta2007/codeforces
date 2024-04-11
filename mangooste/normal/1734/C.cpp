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
    int n;
    string s;
    cin >> n >> s;
    vector<bool> used(n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n && s[j - 1] == '0'; j += i) {
            if (!used[j - 1]) {
                used[j - 1] = true;
                ans += i;
            }
        }
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
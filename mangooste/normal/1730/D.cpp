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
    string s, t;
    cin >> n >> s >> t;
    reverse(all(t));
    map<pair<char, char>, int> mp;
    for (int i = 0; i < n; i++) {
        mp[minmax(s[i], t[i])] ^= 1;
    }

    cout << ([&]() {
        int sum = 0;
        for (auto &[p, val] : mp) {
            if (!val) continue;
            if (p.first != p.second) return false;
            sum++;
        }
        return sum <= 1;
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
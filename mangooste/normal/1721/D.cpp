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

#include <bits/extc++.h>

void solve(int test_num) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    std::unordered_map<int, int> mp1, mp2;
    mp1.rehash(n), mp2.rehash(n);

    int ans = 0;
    for (int bit = 29; bit >= 0; bit--) {
        ans ^= 1 << bit;
        mp1.clear();
        mp2.clear();
        for (int i = 0; i < n; i++) {
            mp1[a[i] & ans]++;
            mp2[(b[i] & ans) ^ ans]++;
        }

        bool ok = true;
        for (auto &[x, y] : mp1) {
            auto it = mp2.find(x);
            if (it == mp2.end() || it->second != y) {
                ok = false;
                break;
            }
        }
        if (!ok) ans ^= 1 << bit;
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
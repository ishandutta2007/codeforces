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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    map<int, vector<int>> mp;
    for (int rot : {0, 1}) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int value, cost;
            cin >> value >> cost;
            mp[value].push_back(cost);
        }
    }

    ll ans = 0;
    for (auto &[_, v] : mp) {
        assert(1 <= len(v) && len(v) <= 2);
        if (len(v) == 1) {
            ans += v[0];
        } else {
            ans += max(v[0], v[1]);
        }
    }
    cout << ans << '\n';
}
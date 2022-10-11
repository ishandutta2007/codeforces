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
    cin >> n;
    multiset<int> sta;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sta.insert(x);
    }
    multiset<int> stb;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        stb.insert(x);
    }

    auto tot = sta;
    for (auto x : stb) tot.insert(x);
    int ans = 0;
    while (!tot.empty()) {
        int val = *tot.rbegin();
        auto ita = sta.find(val);
        auto itb = stb.find(val);
        if (ita != sta.end() && itb != stb.end()) {
            sta.erase(ita);
            stb.erase(itb);
            tot.erase(tot.find(val));
            tot.erase(tot.find(val));
            continue;
        }
        ans++;
        if (ita == sta.end()) {
            swap(ita, itb);
            swap(sta, stb);
        }
        assert(ita != sta.end());
        int nval = len(to_string(*ita));
        tot.erase(tot.find(val));
        sta.erase(ita);
        sta.insert(nval);
        tot.insert(nval);
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
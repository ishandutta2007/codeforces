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

#define int ll
void solve(int test_num) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &x : a) cin >> x;
    sort(all(a));

    vector<int> d;
    for (int i = 0; i < m - 1; i++) {
        d.push_back(a[i + 1] - a[i] - 1);
    }
    d.push_back(n - a.back() + a[0] - 1);
    sort(all(d));
    reverse(all(d));

    multiset<int, greater<>> st2(all(d)), st1;
    int ans = 0;
    for (int it = 0; !st2.empty() || !st1.empty(); it++) {
        if (st1.empty()) {
            int cur_d = *st2.begin();
            cur_d -= 2 * it;
            st2.erase(st2.begin());
            if (cur_d > 0) {
                ans++;
                st1.insert(cur_d - 1 + it);
            }
            continue;
        }

        if (st2.empty()) {
            int cur_d = *st1.begin();
            st1.erase(st1.begin());
            cur_d -= it;
            ans += max(0ll, cur_d);
            continue;
        }

        int cur_d1 = *st2.begin();
        cur_d1 -= 2 * it;
        int cur_d2 = *st1.begin();
        cur_d2 -= it;

        // if (cur_d1 > 1 || (cur_d1 == 1 && cur_d2 > 0)) {
        if (cur_d2 <= 0) {
            st2.erase(st2.begin());
            ans += cur_d1 > 0;
            st1.insert(cur_d1 - 1 + it);
            continue;
        }

        st1.erase(st1.begin());
        ans += max(0ll, cur_d2);
    }
    cout << n - ans << '\n';
}
#undef int

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
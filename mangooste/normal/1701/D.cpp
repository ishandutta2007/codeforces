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
    cin >> n;
    vector<vector<pair<int, int>>> events(n);
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        // i / a[i] = val
        // a[i] * val <= i
        // a[i] * (val + 1) > i
        int from, to;
        if (val) {
            from = i / (val + 1) + 1;
            to = i / val;
            assert(from >= 1);
        } else {
            from = i + 1;
            to = n;
        }
        events[from - 1].emplace_back(i - 1, to);
    }

    vector<int> a(n);
    set<pair<int, int>> st;
    for (int val = 0; val < n; val++) {
        for (auto &[id, to] : events[val]) {
            st.emplace(to, id);
        }
        assert(!st.empty() && st.begin()->first > val);
        a[st.begin()->second] = val;
        st.erase(st.begin());
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
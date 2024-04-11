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

constexpr int A = 1e6 + 1;
vector<int> divs[A];

void precalc() {
    for (int i = 1; i < A; i++) {
        for (int j = i; j < A; j += i) {
            divs[j].push_back(i);
        }
    }
}

void solve(int test_num) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> less_left(n), less_right(n), greater_left(n), greater_right(n);
    for (int rot1 : {0, 1}) {
        for (int rot2 = 0; rot2 < 2; rot2++, reverse(all(a))) {
            auto &cur = rot1 == 0 ? (rot2 == 0 ? less_left : less_right) : (rot2 == 0 ? greater_left : greater_right);
            stack<int> st;
            for (int i = 0; i < n; i++) {
                while (!st.empty() && a[st.top()] >= a[i] + (rot1 ? rot2 : 0)) {
                    st.pop();
                }
                cur[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            if (rot2) {
                reverse(all(cur));
                for (auto &x : cur) x = n - 1 - x;
            }
        }
        for (auto &x : a) x *= -1;
    }

    struct info {
        int left, mid1, mid2, right;
    };
    vector<info> values(A, {-1, -1, -1});
    vector<vector<info>> events(n + 1);

    vector<vector<int>> occ(A);
    for (int i = 0; i < n; i++) occ[a[i]].push_back(i);
    for (int val = 0; val < A; val++) {
        if (occ[val].empty()) continue;
        for (int i = 0, j = 0; i < len(occ[val]); i = j) {
            while (j < len(occ[val]) && less_right[occ[val][i]] == less_right[occ[val][j]]) {
                j++;
            }

            events[less_left[occ[val][i]] + 1].push_back({less_left[occ[val][i]] + 1, -1, occ[val][i], less_right[occ[val][i]]});
            for (int k = i; k < j; k++) {
                events[occ[val][k] + 1].push_back({less_left[occ[val][i]] + 1, occ[val][k], k + 1 == j ? n : occ[val][k + 1], less_right[occ[val][i]]});
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto &[left, mid1, mid2, right] : events[i]) {
            int pos = mid1 == -1 ? mid2 : mid1;
            mid1 = max(mid1, left - 1);
            mid2 = min(mid2, right);
            values[a[pos]] = {left, mid1, mid2, right};
        }

        int from = greater_left[i] + 1, to = greater_right[i];
        for (auto d : divs[a[i]]) {
            auto [left, mid1, mid2, right] = values[d];
            if (left == -1 || right <= i) continue;
            ans += 1ll * max(0, (i - max(left, from) + 1)) * max(0, min(to, right) - i);
            ans -= 1ll * max(0, i - max(from - 1, mid1)) * max(0, min(to, mid2) - i);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    precalc();
    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
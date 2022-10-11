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
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &x : p) cin >> x, x--;
    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    vector<int> right_more(n), right_less(n);
    for (int rot : {0, 1}) {
        auto &cur = rot == 0 ? right_more : right_less;
        vector<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && p[st.back()] < p[i]) st.pop_back();
            cur[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }
        for (auto &x : p) x = n - 1 - x;
    }

    vector<pair<int, int>> points;
    points.reserve(12 * n);

    auto add_point = [&](int x, int y) {
        if (0 <= x && x < 2 * n - 1 && 0 <= y && y < 2 * n - 1) {
            points.emplace_back(x, y);
        }
    };

    for (int i = 0; i < n; i++) {
        for (int d1 : {-1, 1}) {
            for (int d2 : {-1, 1}) {
                add_point(2 * i + d1, 2 * p[i] + d2);
                add_point(2 * right_more[i] + d1, 2 * p[i] + d2);
                add_point(2 * right_less[i] + d1, 2 * p[i] + d2);
            }
        }
    }

    vector<vector<pair<int, int>>> by_y(2 * n - 1);
    for (int i = 0; i < len(points); i++) {
        by_y[points[i].second].emplace_back(points[i].first, i);
    }

    vector<int> left(len(points)), right(len(points));
    for (int rot : {0, 1}) {
        auto &cur = rot == 0 ? left : right;
        for (int coeff : {0, 1}) {
            vector<int> inv_p(n);
            for (int i = 0; i < n; i++) inv_p[p[i]] = i;

            struct binary_indexed_tree {
                int n;
                vector<int> bit;

                binary_indexed_tree(int n) : n(n), bit(n + 1) {}

                void setmax(int pos, int value) {
                    for (pos++; pos <= n; pos += pos & -pos) {
                        bit[pos] = max(bit[pos], value);
                    }
                }

                int query(int pref) {
                    int res = 0;
                    for (pref++; pref; pref -= pref & -pref) {
                        res = max(res, bit[pref]);
                    }
                    return res;
                }
            } bit(2 * n - 1);

            set<int> st;
            for (int x = 0; x < 2 * n - 1; x++) {
                if (x % 2 == 0) {
                    int pos = inv_p[x / 2];
                    auto it = st.lower_bound(pos);
                    if (it != st.end()) bit.setmax(2 * *it, 2 * (pos + 1));
                    st.insert(pos);
                }

                for (auto &[pos, id] : by_y[x]) {
                    cur[id] = max(cur[id], bit.query(pos));
                }
            }

            for (auto &x : p) x = n - 1 - x;
            reverse(all(by_y));
        }

        reverse(all(p));
        for (auto &v : by_y) {
            for (auto &[f, s] : v) f = 2 * n - 2 - f;
        }
    }
    for (auto &x : right) x = 2 * n - 2 - x;

    vector<vector<int>> events(n + 1);
    for (int i = 0; i < len(points); i++) {
        int from = (left[i] + 1) / 2, to = right[i] / 2;
        assert(from <= to);
        events[from].push_back(-1);
        events[to + 1].push_back(from);
    }

    multiset<int> open;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto x : events[i]) {
            if (x == -1) open.insert(i);
            else open.erase(open.find(x));
        }
        assert(!open.empty());
        ans += i - *open.begin() + 1;
    }
    cout << ans << '\n';
}
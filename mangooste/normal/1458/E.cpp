#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    map<int, vector<int>> bad_pairs;
    bad_pairs[0].push_back(0);

    vector<int> coords{0};
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coords.push_back(x);
        bad_pairs[x].push_back(y);
    }

    for (auto &[x, v] : bad_pairs)
        sort(all(v));

    map<int, vector<pair<int, int>>> queries;
    vector<bool> answer(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        queries[a].emplace_back(b, i);
        coords.push_back(a);
    }

    sort(all(coords));
    coords.resize(unique(all(coords)) - coords.begin());

    set<pair<ll, ll>> st;
    int last = -1;

    for (auto x : coords) {
        int delta = x - last - 1;
        while (delta) {
            assert(!st.empty());
            if (len(st) == 1) {
                auto [l, r] = *st.begin();
                st.erase(st.begin());
                st.emplace(l, r + delta);
                delta = 0;
                break;
            }

            auto [l1, r1] = *st.begin();
            st.erase(st.begin());
            auto [l2, r2] = *st.begin();
            st.erase(st.begin());

            int take = l2 - r1 - 1;
            if (take <= delta) {
                delta -= take;
                st.emplace(l1, r2);
                continue;
            }

            st.emplace(l1, r1 + delta);
            st.emplace(l2, r2);
            delta = 0;
        }

        // cout << x << ": "; for (auto &[x, y] : st) cout << "(" << x << ", " << y << ") "; cout << endl;

        int pos = st.empty() ? 1e9 + 228 : st.begin()->second + 1, mn = 1e9 + 1;

        auto insert_one = [&](int y) {
            // cout << "insert " << y  << endl;
            auto it = st.lower_bound({y + 1, -1});
            if (it == st.end() || it->first != y + 1) {
                if (it == st.begin() || prev(it)->second < y - 1)
                    st.emplace(y, y);
                else if (prev(it)->second == y - 1) {
                    it--;
                    st.emplace(it->first, y);
                    st.erase(it);
                }
            } else if (it == st.begin() || prev(it)->second < y - 1) {
                st.emplace(y, it->second);
                st.erase(it);
            } else if (prev(it)->second == y - 1) {
                auto [l1, r1] = *prev(it);
                auto [l2, r2] = *it;
                assert(r1 == y - 1 && y + 1 == l2);
                st.erase({l1, r1});
                st.erase({l2, r2});
                st.emplace(l1, r2);
            }
        };

        for (auto y : bad_pairs[x]) {
            mn = min(mn, y);
            insert_one(y);
        }

        if (pos < mn)
            insert_one(pos);

        // cout << x << ": "; for (auto &[x, y] : st) cout << "(" << x << ", " << y << ") "; cout << endl << endl;
        for (auto &[y, id] : queries[x])
            answer[id] = (pos < mn && y == pos) || binary_search(all(bad_pairs[x]), y);

        last = x;
    }

    for (int i = 0; i < m; i++)
        cout << (!answer[i] ? "WIN" : "LOSE") << '\n';
}
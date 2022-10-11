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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        a[i] -= b;
        a[i] += a[i - 1];
    }

    vector<vector<int>> ids(n + 1);
    vector<pair<int, int>> segs(m);
    vector<int> left(m);
    queue<int> que;

    for (int i = 0; i < m; i++) {
        auto &[l, r] = segs[i];
        cin >> l >> r;
        l--;
        left[i] = 2 - (a[l] == 0) - (a[r] == 0);
        if (left[i] == 0) que.push(i);
        ids[l].push_back(i);
        ids[r].push_back(i);
    }

    set<int> alive;
    for (int i = 0; i <= n; i++) {
        if (a[i]) alive.insert(i);
    }

    while (!que.empty()) {
        int id = que.front();
        que.pop();

        auto [l, r] = segs[id];
        auto it = alive.lower_bound(l);
        while (it != alive.end() && *it < r) {
            for (auto x : ids[*it]) {
                if (--left[x] == 0) que.push(x);
            }
            it++;
            alive.erase(prev(it));
        }
    }
    cout << (alive.empty() ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
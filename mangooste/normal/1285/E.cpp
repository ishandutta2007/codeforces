#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "./Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

struct Event {
    int x, type, id;

    bool operator < (const Event &ev) const {
        return x < ev.x || (x == ev.x && type < ev.type);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        vals.emplace_back(l[i]);
        vals.emplace_back(r[i]);
    }
    sort(all(vals));
    vals.resize(unique(all(vals)) - vals.begin());
    auto get = [&](int x) {
        return int(lower_bound(all(vals), x) - vals.begin());
    };
    for (int i = 0; i < n; i++) {
        l[i] = get(l[i]);
        r[i] = get(r[i]);
    }

    vector<Event> events;
    for (int i = 0; i < n; i++) {
        events.push_back({l[i], 0, i});
        events.push_back({r[i], 1, i});
    }
    sort(all(events));

    vector<vector<pair<int, int>>> segs(n);
    set<int> open;
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        auto [x, type, id] = events[i];
        if (type == 0) {
            if (len(open) == 1) {
                int prev = events[i - 1].x;
                if (x - 1 >= prev && events[i - 1].id != *open.begin()) segs[*open.begin()].emplace_back(prev, x);
            }
            cnt += len(open) == 0;
            open.insert(id);
        } else {
            open.erase(id);
        }
    }

    vector<int> bit(len(vals) + 1, 0);
    for (int i = 0; i < n; i++) {
        bit[l[i]]++;
        bit[r[i] + 1]--;
    }
    for (int i = 1; i < len(bit); i++) {
        bit[i] += bit[i - 1];
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = len(segs[i]);
    }
    for (int i = 1; i < 2 * n; i++) {
        if (events[i].type == 1 && events[i - 1].type == 0 && events[i].id == events[i - 1].id
         && bit[l[events[i].id]] == 1)
            res[events[i].id] = -1;
    }

    cout << cnt + *max_element(all(res)) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
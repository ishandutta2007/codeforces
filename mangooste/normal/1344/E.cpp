#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 1; i < n; i++) {
        int from, to, d;
        cin >> from >> to >> d;
        from--, to--;
        g[from].emplace_back(to, d);
    }

    vector<ll> depth(n);
    vector<int> tin(n);
    int timer = 0;

    y_combinator([&](auto dfs, int v) -> void {
        tin[v] = timer++;
        reverse(all(g[v]));
        for (auto &[u, d] : g[v]) {
            depth[u] = depth[v] + d;
            dfs(u);
        }
    })(0);

    vector<vector<ll>> ends(n);
    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        s--;
        ends[s].push_back(t + depth[s]);
    }
    set<array<ll, 3>> events;

    struct ret_type {
        set<pair<ll, int>> st;
        ll delta = 0;
    };

    y_combinator([&](auto dfs, int v) -> ret_type {
        ret_type res;
        auto get_class = [&](int u) {
            return partition_point(all(g[v]), [&](const pair<int, int> &x) {
                return tin[x.first] <= tin[u];
            }) - g[v].begin() - 1;
        };

        for (auto &[u, d] : g[v]) {
            auto cur = dfs(u);
            cur.delta -= d;
            if (len(res.st) < len(cur.st)) {
                swap(res, cur);
                for (auto it = cur.st.begin(); it != cur.st.end(); it++) {
                    if (it != cur.st.begin() && get_class(prev(it)->second) != get_class(it->second)) {
                        events.erase({prev(it)->first + cur.delta + 1, it->first + cur.delta, v});
                    }
                }
            }

            for (auto [t, pos] : cur.st) {
                t += cur.delta - res.delta;
                res.st.emplace(t, pos);

                auto it = res.st.lower_bound({t, pos});
                if (it != res.st.begin() && next(it) != res.st.end() && get_class(prev(it)->second) != get_class(next(it)->second)) {
                    events.erase({prev(it)->first + res.delta + 1, next(it)->first + res.delta, v});
                }

                int c = get_class(pos);
                if (it != res.st.begin() && get_class(prev(it)->second) != c) {
                    events.insert({prev(it)->first + res.delta + 1, t + res.delta, v});
                }
                if (next(it) != res.st.end() && get_class(next(it)->second) != c) {
                    events.insert({t + res.delta + 1, next(it)->first + res.delta, v});
                }
            }
        }

        if (!res.st.empty() && get_class(res.st.begin()->second) != 0) {
            events.insert({1, res.st.begin()->first + res.delta, v});
        }

        ret_type cur;
        for (auto t : ends[v]) {
            cur.st.emplace(t, v);
        }
        if (len(cur.st) > len(res.st)) swap(cur, res);
        for (auto [t, pos] : cur.st) {
            res.st.emplace(t + cur.delta - res.delta, pos);
        }
        return res;
    })(0);

    auto initial_events = events;
    ll cur_time = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    while (!events.empty() || !pq.empty()) {
        if (!pq.empty() && pq.top().first < cur_time) {
            cur_time--;
            break;
        }

        if (pq.empty()) cur_time = (*events.begin())[0];
        while (!events.empty() && (*events.begin())[0] == cur_time) {
            pq.push({(*events.begin())[1], (*events.begin())[0]});
            events.erase(events.begin());
        }

        pq.pop();
        cur_time++;
    }

    if (events.empty() && pq.empty()) cur_time = -1;
    int tot = 0;
    for (auto &[from, to, v] : initial_events) {
        if (to < cur_time || cur_time == -1) tot++;
    }
    cout << cur_time << ' ' << tot << '\n';
}
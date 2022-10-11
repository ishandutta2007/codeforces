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

    struct edge {
        int v, u, w, id;
    };
    vector<edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].v >> edges[i].u >> edges[i].w;
        edges[i].v--, edges[i].u--;
        edges[i].id = i;
    }

    sort(all(edges), [&](const auto &a, const auto &b) {
        return a.w < b.w;
    });
    vector<int> where(m);
    for (int i = 0; i < m; i++) {
        where[edges[i].id] = i;
    }

    struct disjoin_set_union {
        vector<int> par, rank;
        vector<array<int, 3>> events;
        int cnt_odd;

        disjoin_set_union(int n) : par(n), rank(n, 1), cnt_odd(n) {
            iota(all(par), 0);
        }

        int root(int v) {
            while (par[v] != v) v = par[v];
            return v;
        }

        void unite(int v, int u) {
            v = root(v);
            u = root(u);
            if (v == u) return;
            if (rank[v] < rank[u]) swap(v, u);
            events.push_back({v, u, cnt_odd});
            cnt_odd -= rank[v] & 1;
            cnt_odd -= rank[u] & 1;
            cnt_odd += (rank[v] + rank[u]) & 1;
            par[u] = v;
            rank[v] += rank[u];
        }

        void roll_back() {
            assert(!events.empty());
            auto [v, u, prev_cnt_odd] = events.back();
            events.pop_back();
            par[u] = u;
            rank[v] -= rank[u];
            cnt_odd = prev_cnt_odd;
        }
    } dsu(n);

    vector<int> ans(m, m);

    y_combinator([&](auto solve, int l, int r, int ql, int qr) -> void {
        if (r <= l) return;
        int initial = len(dsu.events);

        int mid = (l + r) >> 1;
        for (int i = l; i <= mid; i++) {
            int pos = where[i];
            if (pos < ql) dsu.unite(edges[pos].v, edges[pos].u);
        }
        assert(dsu.cnt_odd);

        int pos = ql;
        while (pos <= qr && dsu.cnt_odd) {
            if (pos == qr) {
                pos++;
                break;
            }
            if (edges[pos].id <= mid) {
                dsu.unite(edges[pos].v, edges[pos].u);
            }
            pos++;
        }
        pos--;
        ans[mid] = pos;

        auto go_back = [&]() {
            while (len(dsu.events) != initial) dsu.roll_back();
        };
        go_back();

        if (pos < qr) {
            for (int i = ql; i < pos; i++) {
                if (edges[i].id < l) dsu.unite(edges[i].v, edges[i].u);
            }
            solve(l, mid, pos, qr);
            go_back();
        } else {
            assert(pos == m);
        }

        for (int i = l; i <= mid; i++) {
            int pos = where[i];
            if (pos < ql) dsu.unite(edges[pos].v, edges[pos].u);
        }
        solve(mid + 1, r, ql, min(qr, pos + 1));
        go_back();
    })(0, m, 0, m);

    for (int i = 0; i < m; i++) {
        if (ans[i] == m) {
            cout << "-1\n";
        } else {
            cout << edges[ans[i]].w << '\n';
        }
    }
}
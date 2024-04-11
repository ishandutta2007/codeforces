#include <bits/stdc++.h>

using namespace std;

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;

    vector<vector<pair<int, int64_t>>> adj(N);
    vector<vector<pair<int, int64_t>>> radj(N);
    for (int i = 0; i < M; ++i) {
        int v, u; int64_t l; cin >> v >> u >> l;
        adj[--v].emplace_back(--u, l);
        radj[u].emplace_back(v, l);
    }

    vector<char> was(N);
    vector<int> ord;
    auto dfs = y_combinator([&](auto self, int v) -> void {
        was[v] = 1;
        for (auto [u, l] : adj[v]) if (!was[u]) self(u);
        ord.emplace_back(v);
    });

    for (int i = 0; i < N; ++i) if (!was[i]) dfs(i);
    reverse(ord.begin(), ord.end());
    vector<int> comp(N, -1);
    int cc = 0;
    auto rdfs = y_combinator([&](auto self, int v) -> void {
        comp[v] = cc;
        for (auto [u, l] : radj[v]) if (comp[u] == -1) {
            self(u);
        }
    });

    vector<int64_t> gs;
    vector<int64_t> dist(N, -1);
    vector<int64_t> rdist(N, -1);
    for (int s : ord) if (comp[s] == -1) {
        rdfs(s);
        dist[s] = 0;
        vector<int> bfs;
        bfs.emplace_back(s);
        for (int z = 0; z < bfs.size(); ++z) {
            int v = bfs[z];
            for (auto [u, l] : adj[v]) {
                if (dist[u] == -1 && comp[u] == cc) {
                    dist[u] = dist[v] + l;
                    bfs.emplace_back(u);
                }
            }
        }
        bfs.clear();
        rdist[s] = 0; bfs.emplace_back(s);
        for (int z = 0; z < bfs.size(); ++z) {
            int v = bfs[z];;
            for (auto [u, l] : radj[v]) {
                if (rdist[u] == -1 && comp[u] == cc) {
                    rdist[u] = rdist[v] + l;
                    bfs.emplace_back(u);
                }
            }
        }

        gs.emplace_back();
        for (int v : bfs) {
            for (auto [u, l] : adj[v]) if (comp[u] == cc) {
                gs.back() = __gcd(gs.back(), dist[v] + l + rdist[u]);
            }
        }
        cc++;
    }

    int Q; cin >> Q;

    while (Q--) {
        int v, s, t; cin >> v >> s >> t;
        int64_t g = gs[comp[--v]];
        if (g == 0) {
            if (s == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            g = __gcd(g, int64_t(t));
            if (s % g) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}
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

    int N, M, X; cin >> N >> M >> X;
    vector<int64_t> A(N); for (auto &a : A) cin >> a;
    vector<int> par(N, -1);

    auto get_par = [&](int v) {
        while (par[v] >= 0) {
            if (par[par[v]] >= 0) par[v] = par[par[v]];
            v = par[v];
        }
        return v;
    };

    auto merge = [&](int v, int u) {
        v = get_par(v);
        u = get_par(u);
        if (v == u)
            return false;
        else {
            if (par[v] > par[u]) swap(v, u);
            par[v] += par[u];
            par[u] = v;
            return true;
        }
    };

    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; ++i) {
        int v, u; cin >> v >> u; --v, --u;
        if (merge(v, u)) {
            adj[v].emplace_back(u, i);
            adj[u].emplace_back(v, i);
        }
    }

    y_combinator([&](auto self, int v) -> void {
        for (auto [u, i] : adj[v]) {
            adj[u].erase(find(adj[u].begin(), adj[u].end(), make_pair(v, i)));
            self(u);
            A[v] += A[u] - X;
        }
    })(0);

    if (A[0] < 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    y_combinator([&](auto self, int v) -> void {
        sort(adj[v].begin(), adj[v].end(), [&](const pair<int, int> &a, const pair<int, int> &b) { return A[a.first] > A[b.first]; });

        for (auto [u, i] : adj[v]) {
            if (A[u] > 0) {
                self(u);
                cout << i+1 << '\n';
            } else {
                cout << i+1 << '\n';
                self(u);
            }
        }
    })(0);
}
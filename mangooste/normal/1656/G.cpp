#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template <typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template <typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    vector<vector<int>> occ(n);
    for (int i = 0; i < n; i++) {
        occ[a[i] - 1].push_back(i);
    }

    vector<int> p(n, -1);
    int pos = 0;
    for (auto v : occ) {
        if (len(v) % 2) {
            if (n % 2 == 0 || p[n / 2] != -1 || (len(v) == 1 && v[0] == n / 2)) {
                cout << "NO\n";
                return;
            }

            int id = v[0] == n / 2;
            p[n / 2] = v[id];
            v.erase(v.begin() + id);
        }

        assert(len(v) % 2 == 0);
        for (int i = 0; i < len(v); i += 2) {
            p[pos] = v[i];
            p[n - pos - 1] = v[i + 1];
            pos++;
        }
    }

    vector<int> par(n);
    iota(all(par), 0);

    auto root = y_combinator([&](auto root, int v) -> int {
        return par[v] == v ? v : par[v] = root(par[v]);
    });

    vector<bool> used(n);
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        for (int j = i; !used[j]; j = p[j]) {
            par[root(i)] = root(j);
            used[j] = true;
        }
    }

    for (int i = 0; i < n / 2; i++) {
        int j = n - 1 - i;
        if (root(i) == root(j)) continue;
        swap(p[i], p[j]);
        par[root(i)] = root(j);
    }

    for (int i = 0; i < n / 2 - 1; i++) {
        if (root(i) == root(i + 1)) continue;
        int j = n - 1 - i;
        int a = p[i], b = p[i + 1], c = p[j], d = p[j - 1];
        p[j - 1] = a;
        p[i + 1] = c;
        p[j] = d;
        p[i] = b;
        par[root(i)] = root(i + 1);
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}
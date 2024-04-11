#include <bits/stdc++.h>

#include <utility>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

struct xor_set {
    int x = 0;
    set<int> values;

    xor_set() {}

    xor_set(int x) : values{x} {}

    xor_set *add(xor_set *other) {
        for (int y: other->values) values.insert(y ^ other->x ^ x);
        return this;
    }

    void xor_with(int y) { x ^= y; }

    int size() { return values.size(); }

    bool contains(int y) { return values.contains(y ^ x); }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<vector<int>> t(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    int ans = 0;
    auto dfs = [&](auto dfs, int cur, int prev) -> xor_set * {
        auto *res = new xor_set(0);
        bool intersection = false;
        for (int next: t[cur]) {
            if (next == prev) continue;
            auto *child = dfs(dfs, next, cur);
            if (res->size() < child->size()) swap(res, child);
            for (int x : child->values) {
                if (res->contains(x ^ child->x ^ a[cur])) intersection = true;
            }
            res->add(child);
        }
        res->xor_with(a[cur]);
        if (intersection) {
            ans++;
            return new xor_set();
        }
        return res;
    };
    dfs(dfs, 0, 0);
    cout << ans << '\n';
}
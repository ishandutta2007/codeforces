#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using vec = vector<T>;
template<typename A, typename B = A> using pr = pair<A, B>;
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()
#define ar array

int n;
vec<vec<int>> g;
vec<int> sz;
multiset<int> st;
vec<int> ans;

void init(int v, int par) {
    sz[v] = 1;
    for (auto u : g[v])
        if (u != par) {
            init(u, v);
            sz[v] += sz[u];
        }
}

int find(int v, int par) {
    for (auto u : g[v])
        if (u != par && sz[u] > n / 2)
            return find(u, v);
    return v;
}

void dfs_solve(int v, int par) {
    int delta = n - sz[v] - n / 2;
    assert(delta >= 0);
    if (delta == 0)
        ans[v] = 1;
    else {
        auto it = st.lower_bound(delta);
        if (it != st.end())
            ans[v] |= *it <= n / 2;
    }
    for (auto u : g[v])
        if (u != par)
            dfs_solve(u, v);
    st.insert(sz[v]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    sz.resize(n);
    init(0, 0);
    int c = find(0, 0);

    ans.resize(n);
    ans[c] = 1;
    auto solve = [&]() {
        st.clear();
        for (auto u : g[c]) {
            st.insert(n - sz[u]);
            dfs_solve(u, c);
            st.erase(st.find(n - sz[u]));
        }
    };

    init(c, c);
    solve();
    for (int i = 0; i < n; i++)
        reverse(all(g[i]));
    solve();

    for (auto x : ans)
        cout << x << ' ';
    cout << '\n';
}
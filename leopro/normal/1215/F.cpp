//#ifdef LOCAL
//#define _GLIBCXX_DEBUG
//#endif

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n, p, mx, m;
    cin >> n >> p >> mx >> m;
    vector<int> size(2 * p + 2 * mx);
    vector<pair<int, int>> aa(n), bb(p), cc(n);
    vector<vector<int>> impl(2 * p + 2 * mx);
    {
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            aa[i] = {x, y};
            size[x + p]++;
            size[y + p]++;
        }
        auto link = [&](int u, int v) {
            if (impl[u].empty() || impl[u].back() != u) impl[u].push_back(v);
        };
        for (int k = 0; k < p; ++k) {
            int l, r;
            cin >> l >> r;
            --l;
            bb[k] = {l, r};
            for (int lg = 0; lg <= __lg(mx); ++lg) {
                r = (r + (1 << lg) - 1) / (1 << lg) * (1 << lg);
                l = l / (1 << lg) * (1 << lg);
                if (r < mx) {
                    size[k]++;
                    size[2 * p + mx + r]++;
                }
                size[2 * p + l]++;
                size[k]++;
            }
        }
        for (int j = 0; j < m; ++j) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            cc[j] = {u, v};
            size[u]++;
            size[v]++;
        }
    }
    for (int i = 0; i < impl.size(); ++i) impl[i].reserve(size[i]);
    {
        for (int i = 0; i < n; ++i) {
            auto [x, y] = aa[i];
            impl[x + p].push_back(y);
            impl[y + p].push_back(x);
        }
        auto link = [&](int u, int v) {
            if (impl[u].empty() || impl[u].back() != u) impl[u].push_back(v);
        };
        for (int k = 0; k < p; ++k) {
            auto [l, r] = bb[k];
            for (int lg = 0; lg <= __lg(mx); ++lg) {
                r = (r + (1 << lg) - 1) / (1 << lg) * (1 << lg);
                l = l / (1 << lg) * (1 << lg);
                if (r < mx) {
                    link(k, 2 * p + r);
                    link(2 * p + mx + r, k + p);
                }
                link(2 * p + l, k + p);
                link(k, 2 * p + mx + l);
            }
        }
        for (int j = 0; j < m; ++j) {
            auto [u, v] = cc[j];
            impl[u].push_back(v + p);
            impl[v].push_back(u + p);
        }
    }
    vector<int> tout(impl.size());
    vector<bool> used(impl.size());
    int time = 1;
    auto dfs = [&](auto dfs, int cur) -> void {
        if (used[cur]) return;
        used[cur] = true;
        for (int nxt: impl[cur]) {
            dfs(dfs, nxt);
        }
        tout[cur] = time++;
    };
    for (int x = 0; x < impl.size(); ++x) if (tout[x] == 0) dfs(dfs, x);
    vector<int> ind(impl.size());
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int i, int j) { return tout[i] > tout[j]; });
    int c = 1;
#define comp tout
    fill(comp.begin(), comp.end(), 0);
    auto pair = [&](int i) { return i < p ? i + p : (i < 2 * p ? i - p : (i < 2 * p + mx ? i + mx : i - mx)); };
    auto go = [&](auto go, int cur, int c) {
        if (comp[cur]) return;
        comp[cur] = c;
        for (int nxt: impl[pair(cur)]) {
            go(go, pair(nxt), c);
        }
    };
    for (int x: ind) if (!comp[x]) go(go, x, c++);
    int ans = 0;
    int low = 0, high = mx;
    for (int i = 0; i < p; ++i) {
        if (comp[i] == comp[i + p]) answer(-1);
        if (comp[i] > comp[i + p]) {
            ans++;
            tout[i] = -3;
            low = max(low, bb[i].first);
        }
    }
    cout << ans << ' ' << low + 1 << '\n';
    for (int x = 0; x < p; ++x) if (tout[x] == -3) cout << x + 1 << ' ';
}
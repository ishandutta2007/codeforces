#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct segment {
    int l, r, i;
};

void solve() {
    int n;
    cin >> n;
    vector<segment> s(n);
    vector<int> d;
    for (int i = 0; i < n; ++i) {
        s[i].i = i;
        cin >> s[i].l >> s[i].r;
        d.push_back(s[i].l);
        d.push_back(s[i].r);
    }
    sort(d.begin(), d.end());
    int m = d.size();
    vector<int> ind(m);
    for (int i = 0; i < m; ++i) ind[i] = i;
    vector<vector<int>> g(m);
    for (auto &[l, r, i]: s) {
        l = ind[lower_bound(d.begin(), d.end(), l) - d.begin()]++;
    }
    for (auto &[l, r, i]: s) {
        r = ind[lower_bound(d.begin(), d.end(), r) - d.begin()]++;
        g[l].push_back(r);
        g[r].push_back(l);
    }
    for (int i = 0; i < m; ++i) {
        g[i].push_back(i ^ 1);
    }
    vector<int> color(m, -1);
    auto dfs = [&](auto dfs, int cur, int c) {
        if (color[cur] != -1) return;
        color[cur] = c;
        for (int next: g[cur]) dfs(dfs, next, c ^ 1);
    };
    for (int i = 0; i < m; ++i) dfs(dfs, i, 0);
    for (auto[l, r, i]: s) cout << color[l] << ' ';
    cout << '\n';
}
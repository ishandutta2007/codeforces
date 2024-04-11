#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;
    vector<vector<int>> g(n);
    vector<int> ind1(n), ind2(n);
    iota(ind1.begin(), ind1.end(), 0);
    iota(ind2.begin(), ind2.end(), 0);
    sort(ind1.begin(), ind1.end(), [&](int x, int y) { return a[x] < a[y]; });
    sort(ind2.begin(), ind2.end(), [&](int x, int y) { return b[x] < b[y]; });
    vector<vector<int>> lose(n);
    for (int i = 0; i + 1 < n; ++i) lose[ind1[i]].push_back(ind1[i + 1]);
    for (int i = 0; i + 1 < n; ++i) lose[ind2[i]].push_back(ind2[i + 1]);
    vector<bool> ans(n);
    auto dfs = [&](auto dfs, int cur) -> void {
        if (ans[cur]) return;
        ans[cur] = true;
        for (int nxt: lose[cur]) dfs(dfs, nxt);
    };
    int mx = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; ++i) if (a[i] == mx) dfs(dfs, i);
    for (int i = 0; i < n; ++i)cout << ans[i];
    cout << '\n';
}
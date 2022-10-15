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

#define answer(ans) { cout << (ans) << '\n'; return; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;
    vector<vector<int>> ind(n + 1);
    for (int i = 0; i < n; ++i) {
        ind[a[i]].push_back(i);
    }
    vector<pair<int, int>> c;
    for (int x : b) {
        if (c.empty() || c.back().first != x) c.emplace_back(x, 0);
        c.back().second++;
    }
    vector<vector<int>> last(n + 1);
    vector<bool> used(n);
    int k = n - 1;
    for (int j = (int) c.size() - 1; j >= 0; --j) {
        while (k >= 0 && a[k] != c[j].first) --k;
        if (k < 0) answer("NO")
        for (int t = 0; t < c[j].second; ++t) last[a[k]].push_back(k);
        used[k] = true;
        --k;
    }
    for (int i = 0; i < n; ++i) if (last[a[i]].back() < i) answer("NO") else last[a[i]].pop_back();
    answer("YES")
}
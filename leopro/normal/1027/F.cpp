#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

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
    int n;
    cin >> n;
    vector<pair<int, int>> d(n);
    for (auto &[a, b]: d) cin >> a >> b;
    vector<int> f;
    for (auto[a, b]: d) f.emplace_back(a), f.emplace_back(b);
    sort(f.begin(), f.end());
    f.erase(unique(f.begin(), f.end()), f.end());
    for (auto &[a, b]: d) {
        a = lower_bound(f.begin(), f.end(), a) - f.begin();
        b = lower_bound(f.begin(), f.end(), b) - f.begin();
    }
    int m = f.size();
    vector<int> used(m);
    vector<vector<int>> g(m);
    for (auto[a, b]: d) {
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> comp(m, -1);
    auto dfs = [&](auto dfs, int cur, int up) -> void {
        for (int nxt: g[cur]) {
            if (comp[nxt] != -1 || nxt >= up) continue;
            comp[nxt] = comp[cur];
            dfs(dfs, nxt, up);
        }
    };
    auto ok = [&](int up) {
        fill(used.begin(), used.end(), 0);
        for (auto[a, b]: d) {
            if (a >= up && b < up) {
                used[b]++;
            } else if (a < up && b >= up) {
                used[a]++;
            } else if (a >= up && b >= up) return false;
        }
        for (int i = 0; i < up; ++i) if (used[i] >= 2) return false;
        fill(comp.begin(), comp.end(), -1);
        int c = 0;
        for (int i = 0; i < up; ++i) {
            if (comp[i] == -1) {
                comp[i] = c++;
                dfs(dfs, i, up);
            }
        }
        vector<int> compFreeCnt(m), edgeCnt(m);
        for (int i = 0; i < up; ++i) if (used[i] == 0) compFreeCnt[comp[i]]++;
        for (auto[a, b]: d) {
            if (a < up && b < up) edgeCnt[comp[a]]++;
        }
        for (int i = 0; i < m; ++i) {
            if (edgeCnt[i] > compFreeCnt[i]) return false;
        }
        return true;
    };
    int mn = m;
    for (auto [a, b] : d) mn = min(mn, max(a, b));
    if (!ok(m)) answer(-1);
    if (ok(mn)) answer(f[mn - 1]);
    int low = mn - 1, high = m;
    while (high - low > 1) {
        int med = (low + high) / 2;
        if (ok(med)) high = med; else low = med;
    }
    answer(f[high - 1]);
}
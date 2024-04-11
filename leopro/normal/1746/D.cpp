#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

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
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    vector<int> s(n);
    for (int &x: s) cin >> x;
    ll sum = 0;
    auto dfs = [&](auto dfs, int cur, int prev, int k) -> vector<int> {
        sum += k * 1LL * s[cur];
        int sz = (int) g[cur].size() - (cur != prev);
        if (sz == 0) return vector(30, s[cur]);
        int plus = k % sz;
        vector<vector<int>> a;
        for (int nxt: g[cur]) {
            if (nxt == prev) continue;
            a.push_back(dfs(dfs, nxt, cur, k / sz));
        }
        sort(a.begin(), a.end(), [](auto &u, auto &v) {
            return v.empty() || !u.empty() && u[0] > v[0];
        });
        for (int i = 0; i < plus; ++i) {
            assert(a[i].size());
            sum += a[i][0];
            a[i].erase(a[i].begin());
        }
        vector<int> res;
        for (int i = plus; i < a.size(); ++i) {
            assert(a[i].size());
            res.push_back(a[i][0] + s[cur]);
            a[i].erase(a[i].begin());
        }
        while (res.size() < 30) {
            sort(a.begin(), a.end(), [](auto &u, auto &v) {
                return v.empty() || !u.empty() && u[0] > v[0];
            });
            for (int j = 0; j < a.size(); ++j) {
                if (a[j].empty() || res.size() == 30) return res;
                res.push_back(a[j][0] + s[cur]);
                a[j].erase(a[j].begin());
            }
        }
        return res;
    };
    dfs(dfs, 0, 0, k);
    cout << sum << '\n';
}
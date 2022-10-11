#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector<int> rev_a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        rev_a[x - 1] = i;
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] = rev_a[p[i] - 1];
    }

    vector<bool> used(n);
    vector<vector<int>> cycles;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        cycles.push_back({});
        for (int j = i; !used[j]; j = p[j]) {
            used[j] = true;
            cycles.back().push_back(j);
        }
    }

    vector<int> values(n);
    int l = 0, r = -1;
    for (auto &v : cycles) {
        if (len(v) % 2) {
            values[v.back()] = ++r;
            v.pop_back();
        }
    }

    for (auto &v : cycles) {
        assert(len(v) % 2 == 0);
        for (int i = 0; i < len(v); i++) {
            if (i % 2) {
                values[v[i]] = ++r;
            } else {
                values[v[i]] = --l;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(values[i] - values[p[i]]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}
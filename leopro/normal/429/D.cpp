#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

#define answer(ans) do { cout << (ans) << '\n'; exit(0); } while(0)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    a.erase(a.begin());
    vector<int> p(n);
    for (int i = 0; i + 1 < n; ++i) p[i + 1] = p[i] + a[i];
    auto dist = [&](int i, int j) { return (i - j) * 1LL * (i - j) + (p[i] - p[j]) * 1LL * (p[i] - p[j]); };
    ll minDistSquared = 1e12;
    set<pair<int, int>> pts;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        ll d = sqrt(minDistSquared) + 2;
        while ((i - j) >= d) {
            pts.erase({p[j], j});
            j++;
        }
        auto low = pts.lower_bound({p[i] - d, -1e9});
        auto high = pts.lower_bound({p[i] + d, 1e9});
        while (low != high) {
            minDistSquared = min(minDistSquared, dist(low++->second, i));
        }
        pts.emplace(p[i], i);
    }
    cout << minDistSquared << '\n';
}
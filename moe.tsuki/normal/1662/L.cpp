#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, v;
    cin >> n >> v;
    vector<int64_t> x(n), t(n);
    vector<pair<int64_t,int64_t>> p;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    p.emplace_back(0, 0);
    for (int i = 0; i < n; i++) {
        p.emplace_back(v * t[i] - x[i], v * t[i] + x[i]);
    }
    vector<int64_t> lis;
    sort(p.begin(), p.end(), greater<>());
    int64_t ans;
    for (auto [x, y]: p) {
        auto it = upper_bound(lis.begin(), lis.end(), y, greater<>());
        if (x == 0 && y == 0)
            ans = it - lis.begin();
        if (it == lis.end())
            lis.push_back(y);
        else
            *it = y;
    }
    cout << ans << '\n';
    return 0;
}
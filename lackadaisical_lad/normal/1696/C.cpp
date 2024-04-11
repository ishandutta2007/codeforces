#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }
    auto reduce = [&](const vector<int>& a) {
        vector<pair<ll, ll>> res;
        for (int i = 0; i < a.size(); i++) {
            ll val = a[i];
            ll cnt = 1;
            while (val % m == 0) {
                val /= m;
                cnt *= m;
            }
            if (!res.empty() && res.back().first == val) {
                res.back().second += cnt;
            } else {
                res.emplace_back(val, cnt);
            }
        }
        return res;
    };
    if (reduce(a) == reduce(b))
        cout << "Yes\n";
    else
        cout << "No\n";
}

signed main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
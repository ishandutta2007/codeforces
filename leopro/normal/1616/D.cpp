#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

using segment = pair<int, int>;
#define l first
#define r second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int x;
    cin >> x;
    vector<segment> low;
    for (int i = 0; i < n; ++i) {
        for (int len = 2; len <= 3 && i + len <= n; ++len) {
            int sum = 0;
            for (int k = i; k < i + len; ++k) sum += a[k];
            if (sum < len * x) low.emplace_back(i, i + len);
        }
    }
    sort(low.begin(), low.end(), [](auto p, auto q) { return pair{p.r, p.l} < pair{q.r, q.l}; });
    vector<bool> notChosen(n);
    for (auto s : low) {
        bool ok = false;
        for (int i = s.l; i < s.r; ++i) {
            if (notChosen[i]) ok = true;
        }
        if (!ok) notChosen[s.r - 1] = true;
    }
    cout << count(notChosen.begin(), notChosen.end(), false) << '\n';
}
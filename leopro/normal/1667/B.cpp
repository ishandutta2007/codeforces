#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int32_t main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct MaxTree {
    int n;
    vector<int> mx;

    MaxTree(int n) : mx(2 * n, -1e9), n(n) {}

    void set(int i, int x) {
        i += n;
        mx[i] = max(mx[i], x);
        for (i /= 2; i > 0; i /= 2) mx[i] = max(mx[2 * i], mx[2 * i + 1]);
    }

    int get(int l, int r) {
        int res = -1e9;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = max(res, mx[l++]);
            if (r & 1) res = max(res, mx[--r]);
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    vector<ll> d = pref;
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    vector<int> c(n + 1);
    for (int i = 0; i <= n; ++i) c[i] = lower_bound(d.begin(), d.end(), pref[i]) - d.begin();
    MaxTree map(n + 1);
    map.set(c[0], 0);
    vector<int> ifEqual(n + 1, -1e9);
    ifEqual[c[0]] = 0;
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] - 1;
        dp[i] = max(dp[i], ifEqual[c[i]]);
        int l = map.get(0, c[i]);
        dp[i] = max(dp[i], i + l);
        map.set(c[i], dp[i] - i);
        ifEqual[c[i]] = dp[i];
    }
    cout << dp[n] << '\n';
}
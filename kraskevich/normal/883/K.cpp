#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> s(n);
    vector<ll> g(n);
    for (int i = 0; i < n; i++)
        cin >> s[i] >> g[i];

    vector<ll> min_l(n);
    vector<ll> min_r(n);
    ll cur = 1e9;
    for (int i = 0; i < n; i++) {
        cur++;
        cur = min(cur, s[i] + g[i]);
        min_l[i] = cur;
    }
    cur = 1e9;
    for (int i = n - 1; i >= 0; i--) {
        cur++;
        cur = min(cur, s[i] + g[i]);
        min_r[i] = cur;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll val = min(min_l[i], min_r[i]);
        if (val < s[i]) {
            cout << -1 << endl;
            return 0;
        }
        ans += val - s[i];
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        cout << min(min_l[i], min_r[i]) << " ";
    cout << "\n";
}
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;
    ll mx = a[0];
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ll del = mx - a[i];
        if (del <= 0) {
            mx = max(mx, a[i]);
            continue;
        }
        int cur = -1;
        for (ll j = 35; j >= 0; j--) {
            if (((del >> j) & 1) == 1) {
                cur = j + 1;
                break;
            }
        }
        ans = max(ans, cur);
        mx = max(mx, a[i]);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
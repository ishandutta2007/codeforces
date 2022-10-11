#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> used;
        for (int i = 0; i < n; i++) {
            string cur;
            cin >> cur;
            ll power = 1;
            ll num = 0;
            for (int i = cur.size() - 1; i >= 0; i--) {
                num += 1ll * (cur[i] - '0') * power;
                power *= 2ll;
            }
            used.push_back(num);
        }
        sort(all(used));
        used.resize(unique(all(used)) - used.begin());
        const ll INF = 1e18;
        ll L = -1, R = INF;
        ll all = (1ll << m);
        ll need = (all - n - 1) / 2ll + 1ll;
        // cout << "need = " << need << '\n';
        while (R - L > 1) {
            ll md = (L + R) / 2;
            ll cnt = md + 1 - (upper_bound(all(used), md) - used.begin());
            // cout << "md = " << md << " cnt = " << cnt << '\n';
            if (cnt >= need) {
                R = md;
            } else {
                L = md;
            }
        }
        string ans = "";
        for (ll i = m - 1; i >= 0; i--) {
            if (R & (1ll << i)) {
                ans.pb('1');
            } else {
                ans.pb('0');
            }
        }
        cout << ans << '\n';
    }
}
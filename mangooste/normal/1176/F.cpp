#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fun function
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    const ll INF = 1e18;
    vector<ll> dp(10, -INF);
    dp[0] = 0ll;
    for (int i = 0; i < n; i++) {
        vector<ll> new_dp(10, -INF);
        int k;
        cin >> k;
        array<vector<ll>, 3> cur;
        for (int i = 0; i < k; i++) {
            int c;
            ll d;
            cin >> c >> d;
            cur[c - 1].pb(d);
        }
        for (auto &el : cur) {
            sort(all(el));
            reverse(all(el));
        }
        for (int ost = 0; ost < 10; ost++) {
            if (cur[0].size() >= 1) {
                ll p = (ost >= 9 ? 2ll : 1ll);
                new_dp[(ost + 1) % 10] = max(new_dp[(ost + 1) % 10], dp[ost] + p * cur[0][0]);
            }
            if (cur[0].size() >= 2) {
                ll p = (ost >= 8 ? 2ll : 1ll);
                new_dp[(ost + 2) % 10] = max(new_dp[(ost + 2) % 10], dp[ost] + p * cur[0][0] + cur[0][1]);
            }
            if (cur[0].size() >= 3) {
                ll p = (ost >= 7 ? 2ll : 1ll);
                new_dp[(ost + 3) % 10] = max(new_dp[(ost + 3) % 10], dp[ost] + p * cur[0][0] + cur[0][1] + cur[0][2]);
            }
            if (cur[0].size() >= 1 && cur[1].size() >= 1) {
                array<ll, 2> tmp = {cur[0][0], cur[1][0]};
                if (tmp[0] < tmp[1]) {
                    swap(tmp[0], tmp[1]);
                }
                ll p = (ost >= 8 ? 2ll : 1ll);
                new_dp[(ost + 2) % 10] = max(new_dp[(ost + 2) % 10], dp[ost] + p * tmp[0] + tmp[1]);
            }
            if (cur[1].size() >= 1) {
                ll p = (ost >= 9 ? 2ll : 1ll);
                new_dp[(ost + 1) % 10] = max(new_dp[(ost + 1) % 10], dp[ost] + p * cur[1][0]);
            }
            if (cur[2].size() >= 1) {
                ll p = (ost >= 9 ? 2ll : 1ll);
                new_dp[(ost + 1) % 10] = max(new_dp[(ost + 1) % 10], dp[ost] + p * cur[2][0]);
            }
            new_dp[ost] = max(new_dp[ost], dp[ost]);
        }
        swap(dp, new_dp);
    }
    cout << *max_element(all(dp)) << '\n';
}
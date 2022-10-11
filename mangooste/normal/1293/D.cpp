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

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

const ll INF = 1e16 + 2;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    vector<pair<ll, ll>> pts;
    pts.eb();
    ll ax, ay, bx, by;
    cin >> pts[0].first >> pts[0].second >> ax >> ay >> bx >> by;
    ll x, y, t;
    cin >> x >> y >> t;
    while (pts.back().first < INF && pts.back().second < INF)
        pts.eb(pts.back().first * ax + bx, pts.back().second * ay + by);
    // cerr << pts.size() << '\n';
    // for (int i = 0; i < 10; i++)
    //     cerr << '(' << pts[i].first << ' ' << pts[i].second << ") ";
    // cerr << endl;
    // cerr << pts[53].first << ' ' << pts[53].second << endl;
    int m = pts.size();
    vector<int> dp(m);
    for (int i = 0; i < m; i++) {
        ll len;
        len = abs(pts[i].first - x) + abs(pts[i].second - y);
        ll cur_t = t;
        if (len > cur_t) {
            dp[i] = 0;
            continue;
        }
        cur_t -= len;
        dp[i] = 1;
        // if (i == 3)
        //     cerr << len << endl;
        for (int j = i - 1; j >= 0; j--) {
            len = abs(pts[j].first - pts[j + 1].first) + abs(pts[j].second - pts[j + 1].second);
            // if (i == 3)
            //     cerr << "j = " << j << ' ' << "len = " << len << endl;
            if (cur_t >= len)
                dp[i] = i - j + 1;
            cur_t -= len;
        }
        len = abs(pts[i].first - x) + abs(pts[i].second - y);
        cur_t = t - len;
        len = abs(pts[i].first - pts[0].first) + abs(pts[i].second - pts[0].second);
        if (cur_t < 2 * len)
            continue;
        cur_t -= 2 * len;
        dp[i] = max(dp[i], i + 1);
        for (int j = i + 1; j < m; j++) {
            ll len = abs(pts[j].first - pts[j - 1].first) + abs(pts[j].second - pts[j - 1].second);
            if (cur_t >= len)
                dp[i] = max(dp[i], i + 1 + j - i);
            cur_t -= len;
        }
    }
    // cerr << dp[3] << endl;
    ll ans = *max_element(all(dp));
    cout << ans << '\n';
}